#include "Graphics/ButtonGroup.hpp"

namespace Sonar
{
	ButtonGroup::ButtonGroup( GameDataRef data ) : _data( data )
	{
		_currentIndex = 0;

		_isKeyboardEnabled = DEFAULT_BUTTON_GROUP_KEYBOARD_ENABLED;
		_minimumWidth = DEFAULT_BUTTON_GROUP_MINIMUM_WIDTH;
		_orientation = DEFAULT_BUTTON_GROUP_ORIENTATION;
		_gap = DEFAULT_BUTTON_GROUP_GAP;
		_position = DEFAULT_BUTTON_GROUP_POSITION;

		_isCurrentButtonClicked = false;
		_hasButtonGroupLoaded = false;

		_currentMouseState = Button::MOUSE_STATE::NOT_INTERACTING;
	}

	ButtonGroup::~ButtonGroup( ) { }

	void ButtonGroup::Draw( )
	{
		if ( !_hasButtonGroupLoaded )
		{
			_hasButtonGroupLoaded = true;
			UpdateButtons( );
		}

		for ( auto &button : _buttons )
		{ button->Draw( ); }
	}

	void ButtonGroup::Update( const float &dt )
	{
		for ( int i = 0; i < _buttons.size( ); i++ )
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
					}

					break;
			}
		}
	}

	void ButtonGroup::PollInput( const float &dt, const Event &event )
	{
		for ( auto &button : _buttons )
		{ button->PollInput( dt, event ); }

		if ( Event::KeyReleased == event.type )
		{
			if ( Keyboard::Up == event.key.code )
			{ MoveUp( ); }
			else if ( Keyboard::Down == event.key.code )
			{ MoveDown( ); }
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
				glm::vec2 position;

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

		button->Update( 0 );

		if ( overrideStyle )
		{ button->SetTheme( _theme ); }

		_buttons.push_back( button );

		if ( resetWidthForAllButtons )
		{
			float buttonWidth = button->GetWidth( );

			if ( buttonWidth > _minimumWidth )
			{ _minimumWidth = buttonWidth; }

			for ( auto &button : _buttons )
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

	void ButtonGroup::RemoveButton( const int &index )
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

	unsigned int ButtonGroup::GetSize( ) const
	{ return _buttons.size( ); }

	void ButtonGroup::SetTheme( const MenuComponent::Theme &theme )
	{
		_theme = theme;

		for ( auto &button : _buttons )
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
	{ _orientation = orientation; }

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
					glm::vec2 position;

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

	void ButtonGroup::UpdateButtons( )
	{
		for ( int i = 0; i < _buttons.size( ); i++ )
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

