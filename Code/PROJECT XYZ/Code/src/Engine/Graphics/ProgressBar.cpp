#include "pch.hpp"

namespace Sonar
{
	ProgressBar::ProgressBar( GameDataRef data, const Orientation &orientation ) : _data( data ), _orientation( orientation )
	{
		_background = std::make_shared<Rectangle>( _data );
		_progressBar = std::make_shared<Rectangle>( _data );

		_value = DEFAULT_PROGRESS_BAR_CURRENT_VALUE;
		_minimumValue = DEFAULT_PROGRESS_BAR_MINIMUM_VALUE;
		_maximumValue = DEFAULT_PROGRESS_BAR_MAXIMUM_VALUE;
		_jumpAmount = DEFAULT_PROGRESS_BAR_JUMP_AMOUNT;

		_progressBarPercentageSize = DEFAULT_PROGRESS_BAR_VALUE_BAR_SIZE_PERCENT;

		SetBackgroundColor( DEFAULT_PROGRESS_BAR_BACKGROUND_COLOR );
		SetBackgroundBorderThickness( DEFAULT_PROGRESS_BAR_BACKGROUND_BORDER_THICKNESS );
		SetBackgroundBorderColor( DEFAULT_PROGRESS_BAR_BACKGROUND_BORDER_COLOR );

		SetProgressBarColor( DEFAULT_PROGRESS_BAR_BACKGROUND_COLOR );
		SetProgressBarBorderThickness( DEFAULT_PROGRESS_BAR_BACKGROUND_BORDER_THICKNESS );
		SetProgressBarBorderColor( DEFAULT_PROGRESS_BAR_BACKGROUND_BORDER_COLOR );

		if ( Orientation::HORIZONTAL == _orientation )
		{ SetBackgroundSize( DEFAULT_PROGRESS_BAR_HORIZONTAL_BACKGROUND_WIDTH, DEFAULT_PROGRESS_BAR_HORIZONTAL_BACKGROUND_HEIGHT ); }
		else if ( Orientation::VERTICAL == _orientation )
		{ SetBackgroundSize( DEFAULT_PROGRESS_BAR_VERTICAL_BACKGROUND_WIDTH, DEFAULT_PROGRESS_BAR_VERTICAL_BACKGROUND_HEIGHT ); }

		CalculateProgressBarSize( );

		SetPosition( _background->GetPosition( ) );
	}

	ProgressBar::~ProgressBar( ) { }

	void ProgressBar::Draw( )
	{
		_background->Draw( );
		_progressBar->Draw( );
	}

	void ProgressBar::Update( const float &dt )
	{
		_background->Update( dt );
		_progressBar->Update( dt );
	}

	void ProgressBar::PollInput( const float &dt, const Event &event ) { }

	void ProgressBar::SetTheme( const MenuComponent::Theme &theme )
	{
		switch ( theme )
		{
			case MenuComponent::Theme::DARK:
				SetBackgroundColor( Color::Black );
				SetBackgroundBorderColor( Color::White );
				SetProgressBarColor( Color:: White );

				break;

			case MenuComponent::Theme::LIGHT:
				SetBackgroundColor( Color::White );
				SetBackgroundBorderColor( Color::Black );
				SetProgressBarColor( Color:: Black );

				break;
		}
	}

	glm::vec4 ProgressBar::GetLocalBounds( ) const
	{ return _background->GetLocalBounds( ); }

	glm::vec4 ProgressBar::GetGlobalBounds( ) const
	{ return _background->GetGlobalBounds( ); }

	void ProgressBar::SetPosition( const glm::vec2 &position )
	{
		_background->SetPosition( position );

		float readjustmentAmountPercent = 1.0f - _progressBarPercentageSize;
		glm::vec2 readjustmentAmount = _background->GetSize( ) * readjustmentAmountPercent * 0.5f;

		_progressBar->SetPosition( position + readjustmentAmount );
	}

	void ProgressBar::SetPosition( const float &x, const float &y )
	{ SetPosition( glm::vec2( x, y ) ); }

	void ProgressBar::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, GetPositionY( ) ) ); }

	void ProgressBar::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( GetPositionX( ), y ) ); }

	glm::vec2 ProgressBar::GetPosition( ) const
	{ return _background->GetPosition( ); }

	float ProgressBar::GetPositionX( ) const
	{ return _background->GetPositionX( ); }

	float ProgressBar::GetPositionY( ) const
	{ return _background->GetPositionY( ); }

	void ProgressBar::SetBackgroundSize( const glm::vec2 &size )
	{
		_background->SetSize( size );

		CalculateProgressBarSize( );
	}

	void ProgressBar::SetBackgroundSize( const float &width, const float &height )
	{ SetBackgroundSize( glm::vec2( width, height ) ); }

	void ProgressBar::SetBackgroundWidth( const float &width )
	{ SetBackgroundSize( glm::vec2( width, _background->GetHeight( ) ) ); }

	void ProgressBar::SetBackgroundHeight( const float &height )
	{ SetBackgroundSize( glm::vec2( _background->GetWidth( ), height ) ); }

	glm::vec2 ProgressBar::GetBackgroundSize( ) const
	{ return _background->GetSize( ); }

	float ProgressBar::GetBackgroundWidth( ) const
	{ return _background->GetWidth( ); }

	float ProgressBar::GetBackgroundHeight( ) const
	{ return _background->GetHeight( ); }

	void ProgressBar::SetBackgroundColor( const Color &color )
	{ _background->SetInsideColor( color ); }

	void ProgressBar::SetBackgroundBorderThickness( const float &thickness )
	{ _background->SetBorderThickness( thickness ); }

	void ProgressBar::SetBackgroundBorderColor( const Color &color )
	{ _background->SetBorderColor( color ); }

	Color ProgressBar::GetBackgroundColor( ) const
	{ return _background->GetInsideColor( ); }

	float ProgressBar::GetBackgroundBorderThickness( ) const
	{ return _background->GetBorderThickness( ); }

	Color ProgressBar::GetBackgroundBorderColor( ) const
	{ return _background->GetBorderColor( ); }

	void ProgressBar::SetProgressBarColor( const Color &color )
	{ _progressBar->SetInsideColor( color ); }

	void ProgressBar::SetProgressBarBorderThickness( const float &thickness )
	{ _progressBar->SetBorderThickness( thickness ); }

	void ProgressBar::SetProgressBarBorderColor( const Color &color )
	{ _progressBar->SetBorderColor( color ); }

	Color ProgressBar::GetProgressBarColor( ) const
	{ return _progressBar->GetInsideColor( ); }

	float ProgressBar::GetProgressBarBorderThickness( ) const
	{ return _progressBar->GetBorderThickness( ); }

	Color ProgressBar::GetProgressBarBorderColor( ) const
	{ return _progressBar->GetBorderColor( ); }

	void ProgressBar::Move( const glm::vec2 &offset )
	{
		_background->Move( offset );
		_progressBar->Move( offset );
	}

	void ProgressBar::Move( const float &x, const float &y )
	{ Move( glm::vec2( x, y ) ); }

	void ProgressBar::MoveX( const float &x )
	{ Move( glm::vec2( x, 0 ) ); }

	void ProgressBar::MoveY( const float &y )
	{ Move( glm::vec2( 0, y ) ); }

	void ProgressBar::SetScale( const float &scale )
	{
		_background->SetScale( scale, scale );
		_progressBar->SetScale( scale, scale );

		SetPosition( _background->GetPosition( ) );
	}

	void ProgressBar::Scale( const float &scale )
	{
		_background->Scale( scale, scale );
		_progressBar->Scale( scale, scale );

		SetPosition( _background->GetPosition( ) );
	}

	float ProgressBar::GetScale( ) const
	{ return _background->GetScaleX( ); }

	void ProgressBar::SetValue( const float &value )
	{
		if ( value >= _minimumValue && value <= _maximumValue )
		{
			_value = value;
			SetPosition( GetPosition( ) );
		}
		else if ( value < _minimumValue )
		{
			_value = _minimumValue;
			SetPosition( GetPosition( ) );
		}
		else if ( value > _maximumValue )
		{
			_value = _maximumValue;
			SetPosition( GetPosition( ) );
		}

		CalculateProgressBarSize( );
	}

	const float &ProgressBar::GetValue( ) const
	{ return _value; }

	void ProgressBar::SetMinimumValue( const float &value )
	{
		if ( value < _maximumValue )
		{
			_minimumValue = value;

			SetValue( _value );
		}
	}

	void ProgressBar::SetMaximumValue( const float &value )
	{
		if ( value > _minimumValue )
		{
			_maximumValue = value;

			SetValue( _value );
		}
	}

	const float &ProgressBar::GetMinimumValue( ) const
	{ return _minimumValue; }

	const float &ProgressBar::GetMaximumValue( ) const
	{ return _maximumValue; }

	void ProgressBar::Increment( )
	{ SetValue( _value + _jumpAmount ); }

	void ProgressBar::Decrement( )
	{ SetValue( _value - _jumpAmount ); }

	void ProgressBar::SetJumpAmount( const float &value )
	{ _jumpAmount = value; }

	const float &ProgressBar::GetJumpAmount( ) const
	{ return _jumpAmount; }

	bool ProgressBar::IsMouseOver( ) const
	{ return _background->IsMouseOver( ); }

	const Sonar::ProgressBar::Orientation &ProgressBar::GetOrientation( ) const
	{ return _orientation; }

	void ProgressBar::SetProgressBarSizePercentage( const float &percentage )
	{
		_progressBarPercentageSize = percentage;

		CalculateProgressBarSize( );
	}

	const float &ProgressBar::GetProgressBarSizePercentage( ) const
	{ return _progressBarPercentageSize; }

	void ProgressBar::CalculateProgressBarSize( )
	{
		float range = _maximumValue - _minimumValue;
		float percent = ( _value - _minimumValue ) / range;

		float readjustmentAmountPercent = 1.0f - _progressBarPercentageSize;
		glm::vec2 readjustmentAmount = _background->GetSize( ) * readjustmentAmountPercent;

		if ( Orientation::HORIZONTAL == _orientation )
		{
			_progressBar->SetSize
			(
				_background->GetWidth( ) * percent * ( 1.0f - readjustmentAmountPercent ),
				_background->GetHeight( ) * ( 1.0f - readjustmentAmountPercent )
			);
		}
		else if ( Orientation::VERTICAL == _orientation )
		{
			_progressBar->SetSize
			(
				_background->GetWidth( ) * ( 1.0f - readjustmentAmountPercent ),
				_background->GetHeight( ) * percent * ( 1.0f - readjustmentAmountPercent )
			);
		}

		SetPosition( _background->GetPosition( ) );
	}

}

