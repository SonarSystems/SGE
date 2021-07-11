#include "pch.hpp"

namespace Sonar
{
	ButtonGroup::ButtonGroup( GameDataRef data ) : _data( data )
	{
		_currentIndex = 0;
		_clickedIndex = -1;

		_isKeyboardEnabled = DEFAULT_BUTTON_GROUP_KEYBOARD_ENABLED;
		_minimumWidth = DEFAULT_BUTTON_GROUP_MINIMUM_WIDTH;
		_orientation = DEFAULT_BUTTON_GROUP_ORIENTATION;

		_gap = DEFAULT_BUTTON_GROUP_GAP;
		_position = DEFAULT_BUTTON_GROUP_POSITION;

		_isCurrentButtonClicked = false;
		_hasButtonGroupLoaded = false;

		_currentMouseState = Button::MOUSE_STATE::NOT_INTERACTING;

		_isMouseButtonPressedOutsideOfButton = _wasMouseButtonClicked = false;

		_validTriggerKeys.push_back( DEFAULT_BUTTON_GROUP_KEYBOARD_TRIGGER_KEY );
		_mouseClickButton = DEFAULT_BUTTON_GROUP_MOUSE_CLICK_BUTTON;

		SetOrientation( _orientation );
	}

	ButtonGroup::~ButtonGroup( ) { }

	void ButtonGroup::Draw( )
	{
		if ( !_hasButtonGroupLoaded )
		{
			_hasButtonGroupLoaded = true;
			UpdateButtons( );
		}

		for ( const auto &button : _buttons )
		{ button->Draw( ); }
	}

	void ButtonGroup::Update( const float &dt )
	{
		//_clickedIndex = -1;

		for ( unsigned int i = 0; i < _buttons.size( ); i++ )
		{
			Button::MOUSE_STATE mouseState = _buttons.at( i )->UpdateForButtonGroup( dt, !_isKeyboardEnabled );

			switch ( mouseState )
			{
				case Button::MOUSE_STATE::NOT_INTERACTING:
					if ( i == _currentIndex )
					{
						_isCurrentButtonClicked = false;

						if ( Button::MOUSE_STATE::NOT_INTERACTING != _currentMouseState )
						{
							_currentMouseState = Button::MOUSE_STATE::NOT_INTERACTING;

							UpdateButtons( );
						}
						else if ( Button::MOUSE_STATE::NOT_INTERACTING == _currentMouseState )
						{
							if ( _wasMouseButtonClicked )
							{ _wasMouseButtonClicked = false;  }
						}
					}

					break;

				case Button::MOUSE_STATE::CLICKED:
					if ( i == _currentIndex )
					{
						_isCurrentButtonClicked = true;

						if ( Button::MOUSE_STATE::CLICKED != _currentMouseState )
						{
							_currentMouseState = Button::MOUSE_STATE::CLICKED;

							UpdateButtons( );

							if ( !_isMouseButtonPressedOutsideOfButton )
							{ _wasMouseButtonClicked = true; }
						}
					}

					break;

				case Button::MOUSE_STATE::HOVER:
					_currentIndex = i;

					if ( i == _currentIndex )
					{
						_isCurrentButtonClicked = false;

						if ( Button::MOUSE_STATE::HOVER != _currentMouseState )
						{
							_currentMouseState = Button::MOUSE_STATE::HOVER;

							UpdateButtons( );

						}
						else if ( Button::MOUSE_STATE::HOVER == _currentMouseState )
						{
							if ( _wasMouseButtonClicked )
							{
								_clickedIndex = i;
								_wasMouseButtonClicked = false;
							}
						}
					}

					break;
			}
		}
	}

	void ButtonGroup::PollInput( const float &dt, const Event &event )
	{
		for ( const auto &button : _buttons )
		{ button->PollInput( dt, event ); }

		if ( Event::KeyReleased == event.type )
		{
			for ( const auto &navigationPair : _validNavigationKeys )
			{
				if ( navigationPair.first == event.key.code )
				{ MoveUp( ); }
				else if ( navigationPair.second == event.key.code )
				{ MoveDown( ); }
			}

			for ( const auto &key : _validTriggerKeys )
			{
				if ( key == event.key.code )
				{ _clickedIndex = _currentIndex; }
			}
		}
		else if ( Event::MouseButtonPressed == event.type )
		{
			if ( _mouseClickButton == event.mouseButton.button )
			{
				_isMouseButtonPressedOutsideOfButton = true;

				for ( const auto &button : _buttons )
				{
					if ( button->IsMouseOver( ) )
					{ _isMouseButtonPressedOutsideOfButton = false; }
				}
			}
		}
	}

	void ButtonGroup::AddButton( Button *button, const bool &overrideStyle, const bool &resetWidthForAllButtons, const bool &autoOrient )
	{
		if ( autoOrient )
		{
			int numberOfButtons = _buttons.size( );

			if ( numberOfButtons > 0 )
			{
				auto lastButton = _buttons.at( numberOfButtons - 1 );
				glm::vec2 position = { 0, 0 };

				if ( ORIENTATION::VERTICAL == _orientation )
				{
					position.x = lastButton->GetPositionX( );
					position.y = lastButton->GetPositionY( ) + lastButton->GetHeight( ) + _gap;
				}
				else if ( ORIENTATION::HORIZONTAL == _orientation )
				{
					position.x = lastButton->GetPositionX( ) + lastButton->GetWidth( ) + _gap;
					position.y = lastButton->GetPositionY( );
				}

				button->SetPosition( position );
			}
		}
		
		button->SetMouseButtonToClick( _mouseClickButton );

		button->Update( 0 );

		if ( overrideStyle )
		{ button->SetTheme( _theme ); }

		_buttons.push_back( button );

		if ( resetWidthForAllButtons )
		{
			float buttonWidth = button->GetWidth( );

			if ( buttonWidth > _minimumWidth )
			{ _minimumWidth = buttonWidth; }

			for ( const auto &button : _buttons )
			{ button->SetMinimumWidth( buttonWidth ); }
		}

		UpdateButtons( );
	}

	void ButtonGroup::RemoveButton( Button *button )
	{
		std::vector<Button *> newMenuComponentsVector( _buttons.size( ) );

		std::remove_copy( _buttons.begin( ), _buttons.end( ), newMenuComponentsVector.begin( ), button );

		if ( newMenuComponentsVector.at( newMenuComponentsVector.size( ) - 1 ) == NULL )
		{
			newMenuComponentsVector.pop_back( );

			_buttons = newMenuComponentsVector;

			UpdateButtons( );
		}
	}

	void ButtonGroup::RemoveButton( const unsigned int &index )
	{
		if ( index < _buttons.size( ) )
		{
			_buttons.erase( _buttons.begin( ) + index );

			if ( _buttons.size( ) <= _currentIndex )
			{
				_currentIndex = _buttons.size( ) - 1;

				if ( 0 > _currentIndex )
				{ _currentIndex = 0; }
			}

			UpdateButtons( );
		}
	}

	void ButtonGroup::RemoveFirstButton( )
	{
		if ( 0 < _buttons.size( ) )
		{
			_buttons.erase( _buttons.begin( ) );

			if ( _buttons.size( ) <= _currentIndex )
			{
				_currentIndex = _buttons.size( ) - 1;

				if ( 0 > _currentIndex )
				{ _currentIndex = 0; }
			}

			UpdateButtons( );
		}
	}

	void ButtonGroup::RemoveLastButton( )
	{
		if ( _buttons.size( ) > 0 )
		{
			_buttons.erase( _buttons.end( ) - 1 );

			if ( _buttons.size( ) <= _currentIndex )
			{
				_currentIndex = _buttons.size( ) - 1;

				if ( 0 > _currentIndex )
				{ _currentIndex = 0; }
			}

			UpdateButtons( );
		}
	}

	unsigned int ButtonGroup::GetNumberOfButtons( ) const
	{ return _buttons.size( ); }

	glm::vec2 ButtonGroup::GetSize( )
	{ return glm::vec2( GetWidth( ), GetHeight( ) ); }

	float ButtonGroup::GetWidth( )
	{
		float width = 0;

		if ( ORIENTATION::VERTICAL == _orientation )
		{
			for ( const auto &button : _buttons )
			{
				if ( button->GetWidth( ) > width )
				{ width = button->GetWidth( ); }
			}
		}
		else if ( ORIENTATION::HORIZONTAL == _orientation )
		{
			for ( const auto &button : _buttons )
			{ width += button->GetWidth( ); }

			int numberOfButtons = _buttons.size( );

			if ( numberOfButtons > 0 )
			{ width += _gap * ( numberOfButtons - 1 ); }
		}

		return width;
	}

	float ButtonGroup::GetHeight( )
	{
		float height = 0;

		if ( ORIENTATION::VERTICAL == _orientation )
		{
			for ( const auto &button : _buttons )
			{ height += button->GetHeight( ); }

			int numberOfButtons = _buttons.size( );

			if ( numberOfButtons > 0 )
			{ height += _gap * ( numberOfButtons - 1 ); }
		}
		else if ( ORIENTATION::HORIZONTAL == _orientation )
		{
			for ( const auto &button : _buttons )
			{
				if ( button->GetHeight( ) > height )
				{ height = button->GetHeight( ); }
			}
		}

		return height;
	}

	void ButtonGroup::SetTheme( const MenuComponent::Theme &theme )
	{
		_theme = theme;

		for ( const auto &button : _buttons )
		{ button->SetTheme( theme ); }
	}

	void ButtonGroup::MoveUp( const bool &cycleDown, const unsigned int &moveAmount )
	{
		if ( _currentIndex - ( int )moveAmount >= 0 )
		{ _currentIndex -= moveAmount; }
		else if ( cycleDown && _buttons.size( ) > 0 )
		{ _currentIndex = _buttons.size( ) - 1; }
			
		UpdateButtons( );
	}

	void ButtonGroup::MoveDown( const bool &cycleUp, const unsigned int &moveAmount )
	{
		if ( _currentIndex + moveAmount < _buttons.size( ) )
		{ _currentIndex += moveAmount; }
		else if ( cycleUp && _buttons.size( ) > 0 )
		{ _currentIndex = 0; }
		
		UpdateButtons( );
	}

	void ButtonGroup::JumpToIndex( const unsigned int &index )
	{
		if ( index < _buttons.size( ) )
		{ _currentIndex = index; }

		UpdateButtons( );
	}

	unsigned int ButtonGroup::GetCurrentIndex( ) const
	{ return _currentIndex; }

	void ButtonGroup::SetKeyboadEnabled( const bool &isEnabled )
	{ _isKeyboardEnabled = isEnabled; }

	void ButtonGroup::EnableKeyboard( )
	{ _isKeyboardEnabled = true; }

	void ButtonGroup::DisableKeyboard( )
	{ _isKeyboardEnabled = false; }

	void ButtonGroup::ToggleKeyboard( )
	{ _isKeyboardEnabled = !_isKeyboardEnabled; }

	const bool &ButtonGroup::IsKeyboardEnabled( ) const
	{ return _isKeyboardEnabled; }

	void ButtonGroup::SetMinimumWidth( const float &width )
	{
		_minimumWidth = width;

		UpdateButtons( );
	}

	const float &ButtonGroup::GetMinimumWidth( ) const
	{ return _minimumWidth; }

	void ButtonGroup::SetOrientation( const ORIENTATION &orientation )
	{
		_orientation = orientation;

		if ( ORIENTATION::VERTICAL == _orientation )
		{ _validNavigationKeys.push_back( DEFAULT_BUTTON_GROUP_KEYBOARD_VERTIICAL_NAVIGATION_KEYS ); }
		else if ( ORIENTATION::HORIZONTAL == _orientation )
		{ _validNavigationKeys.push_back( DEFAULT_BUTTON_GROUP_KEYBOARD_HORIZONTAL_NAVIGATION_KEYS ); }
	}

	const Sonar::ButtonGroup::ORIENTATION &ButtonGroup::GetOrientation( ) const
	{ return _orientation; }

	void ButtonGroup::SetGap( const float &gap )
	{ _gap = gap; }

	const float &ButtonGroup::GetGap( ) const
	{ return _gap; }

	void ButtonGroup::SetPosition( const glm::vec2 &position )
	{
		_position = position;

		int numberOfButtons = _buttons.size( );

		if ( numberOfButtons > 0 )
		{
			for ( int i = 0; i < numberOfButtons; i++ )
			{
				if ( 0 == i )
				{ _buttons.at( i )->SetPosition( position ); }
				else
				{
					auto previousButton = _buttons.at( i - 1 );
					glm::vec2 position = { 0, 0 };

					if ( ORIENTATION::VERTICAL == _orientation )
					{
						position.x = previousButton->GetPositionX( );
						position.y = previousButton->GetPositionY( ) + previousButton->GetHeight( ) + _gap;
					}
					else if ( ORIENTATION::HORIZONTAL == _orientation )
					{
						position.x = previousButton->GetPositionX( ) + previousButton->GetWidth( ) + _gap;
						position.y = previousButton->GetPositionY( );
					}

					_buttons.at( i )->SetPosition( position );
				}
			}
		}
	}

	void ButtonGroup::SetPositionToCenter( const bool &setCenterInXAxis, const bool &setCenterInYAxis )
	{
		if ( setCenterInXAxis )
		{ SetPositionX( ( _data->window.GetSize( ).x * 0.5f ) - ( GetWidth( ) * 0.5f ) ); }

		if ( setCenterInYAxis )
		{ SetPositionY( ( _data->window.GetSize( ).y * 0.5f ) - ( GetHeight( ) * 0.5f ) ); }
	}

	void ButtonGroup::SetPosition( const float &x, const float &y )
	{ SetPosition( glm::vec2( x, y ) ); }

	void ButtonGroup::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, GetPositionY( ) ) ); }

	void ButtonGroup::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( GetPositionX( ), y ) ); }

	float ButtonGroup::GetPositionX( ) const
	{ return _position.x; }

	float ButtonGroup::GetPositionY( ) const
	{ return _position.y; }

	glm::vec2 ButtonGroup::GetPosition( ) const
	{ return _position; }

	void ButtonGroup::Move( const glm::vec2 &offset )
	{
		_position += offset;

		for ( const auto &button : _buttons )
		{ button->Move( offset ); }
	}

	void ButtonGroup::Move( const float &x, const float &y )
	{ Move( glm::vec2( x, y ) ); }

	void ButtonGroup::MoveX( const float &x )
	{ Move( x, 0 ); }

	void ButtonGroup::MoveY( const float &y )
	{ Move( 0, y ); }

	const int &ButtonGroup::GetButtonClickedIndex( ) const
	{ return _clickedIndex; }

	void ButtonGroup::AddValidKeyboardTriggerKey( const Keyboard::Key &key )
	{
		for ( const auto &validKey : _validTriggerKeys )
		{
			if ( validKey == key )
			{ return; }
		}

		_validTriggerKeys.push_back( key );
	}

	const std::vector<Keyboard::Key> &ButtonGroup::GetValidKeyboardTriggerKeys( ) const
	{ return _validTriggerKeys; }

	void ButtonGroup::RemoveKeyFromValidKeyboardTriggerKeys( const Keyboard::Key &key )
	{
		std::vector<Keyboard::Key> newKeysVector( _validTriggerKeys.size( ) );

		std::remove_copy( _validTriggerKeys.begin( ), _validTriggerKeys.end( ), newKeysVector.begin( ), key );

		if ( static_cast<int>( newKeysVector.at( newKeysVector.size( ) - 1 ) ) == NULL )
		{
			newKeysVector.pop_back( );

			_validTriggerKeys = newKeysVector;
		}
	}

	void ButtonGroup::RemoveAllValidKeyboardTriggerKeys( )
	{ _validTriggerKeys.clear( ); }

	void ButtonGroup::SetMouseClickButton( const Mouse::Button &button )
	{
		_mouseClickButton = button;

		for ( const auto &buttonObj : _buttons )
		{ buttonObj->SetMouseButtonToClick( button ); }
	}

	const Mouse::Button &ButtonGroup::GetMouseClickButton( ) const
	{ return _mouseClickButton; }

	void ButtonGroup::AddNavigationKeyPair( const std::pair<Keyboard::Key, Keyboard::Key> &keyPair )
	{
		bool alreadyExists = false;

		for ( const auto &keys : _validNavigationKeys )
		{
			if ( keyPair == keys )
			{
				alreadyExists = true;

				break;
			}
		}

		if ( !alreadyExists )
		{ _validNavigationKeys.push_back( keyPair ); }
	}

	void ButtonGroup::AddNavigationKeyPair( const Keyboard::Key &up, const Keyboard::Key &down )
	{ AddNavigationKeyPair( std::pair( up, down ) ); }

	void ButtonGroup::RemoveNavigationKeyPair( const std::pair<Keyboard::Key, Keyboard::Key> &keyPair )
	{
		std::vector<std::pair<Keyboard::Key, Keyboard::Key>> newKeysVector( _validNavigationKeys.size( ) );

		std::remove_copy( _validNavigationKeys.begin( ), _validNavigationKeys.end( ), newKeysVector.begin( ), keyPair );

		if ( static_cast<int>( newKeysVector.at( newKeysVector.size( ) - 1 ).first ) == NULL )
		{
			newKeysVector.pop_back( );

			_validNavigationKeys = newKeysVector;
		}
	}

	const std::vector<std::pair<Keyboard::Key, Keyboard::Key>> &ButtonGroup::GetAllNavigationKeyPairs( ) const
	{ return _validNavigationKeys; }

	void ButtonGroup::UpdateButtons( )
	{
		for ( unsigned int i = 0; i < _buttons.size( ); i++ )
		{
			if ( i == _currentIndex )
			{ 
				auto button = _buttons.at( i );

				if ( _isCurrentButtonClicked )
				{ button->SetButtonStyle( button->GetClickedButtonStyle( ), false ); }
				else
				{ button->SetButtonStyle( button->GetHighlightedButtonStyle( ), false ); }
			}
			else
			{
				auto button = _buttons.at( i );
				button->SetButtonStyle( button->GetDefaultButtonStyle( ), false );
			}
		}
	}
}

