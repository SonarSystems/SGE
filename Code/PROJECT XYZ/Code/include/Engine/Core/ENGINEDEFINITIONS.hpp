#pragma once

/**
* \brief Game window width
*/
#define SCREEN_WIDTH 1280
/**
* \brief Game window height
*/
#define SCREEN_HEIGHT 720

/**
* \brief Game window title
*/
#define WINDOW_TITLE "PR0J3CT XY2"

/**
* \brief Default name for scores in the high score manager that aren't set
*/
#define HIGH_SCORE_DEFAULT_NAME "-NOT SET-"
/**
* \brief Default date/time for scores in the high score manager that aren't set
*/
#define HIGH_SCORE_DEFAULT_DATE_TIME 0
/**
* \brief Default score for scores in the high score manager that aren't set
*/
#define HIGH_SCORE_DEFAULT_SCORE 0

/**
* \brief Default label text
*/
#define DEFAULT_LABEL_TEXT "DEFAULT TEXT"
/**
* \brief Default label character size
*/
#define DEFAULT_LABEL_CHARACTER_SIZE 32
/**
* \brief Default label text color
*/
#define DEFAULT_LABEL_TEXT_COLOR Sonar::Color::Black

/**
* \brief Default button padding
*/
#define DEFAULT_BUTTON_PADDING_X_RATIO 0.5f
#define DEFAULT_BUTTON_PADDING_Y_RATIO 0.5f

/**
* \brief Default button properties
*/
#define DEFAULT_BUTTON_BACKGROUND_COLOR Sonar::Color::Black
#define DEFAULT_BUTTON_LABEL_COLOR Sonar::Color::Red
#define DEFAULT_BUTTON_LABEL_CHARACTER_SIZE 64
#define DEFAULT_BUTTON_CURSOR Sonar::Mouse::Cursor::Arrow

/**
* \brief Default button hover properties
*/
#define DEFAULT_BUTTON_HOVER_STATUS true
#define DEFAULT_BUTTON_HOVER_BACKGROUND_COLOR Sonar::Color::Red
#define DEFAULT_BUTTON_HOVER_BORDER_COLOR Sonar::Color::Black
#define DEFAULT_BUTTON_HOVER_LABEL_COLOR Sonar::Color::Black
#define DEFAULT_BUTTON_HOVER_LABEL_BORDER_COLOR Sonar::Color::Red
#define DEFAULT_BUTTON_HOVER_LABEL_CHARACTER_SIZE 64
#define DEFAULT_BUTTON_HOVER_LABEL_TEXT_STYLE 0
#define DEFAULT_BUTTON_HOVER_BORDER_THICKNESS 0
#define DEFAULT_BUTTON_HOVER_LABEL_BORDER_THICKNESS 0
#define DEFAULT_BUTTON_HOVER_SCALE glm::vec2( 1.0f, 1.0f )
#define DEFAULT_BUTTON_HOVER_CURSOR Sonar::Mouse::Cursor::Hand

/**
* \brief Default button clicked properties
*/
#define DEFAULT_BUTTON_CLICK_STATUS true				
#define DEFAULT_BUTTON_CLICKED_BACKGROUND_COLOR Sonar::Color( 200, 0, 0, 255 )
#define DEFAULT_BUTTON_CLICKED_BORDER_COLOR Sonar::Color::Black
#define DEFAULT_BUTTON_CLICKED_LABEL_COLOR Sonar::Color::Black
#define DEFAULT_BUTTON_CLICKED_LABEL_BORDER_COLOR Sonar::Color::Red
#define DEFAULT_BUTTON_CLICKED_LABEL_CHARACTER_SIZE 64
#define DEFAULT_BUTTON_CLICKED_LABEL_TEXT_STYLE 0
#define DEFAULT_BUTTON_CLICKED_BORDER_THICKNESS 0
#define DEFAULT_BUTTON_CLICKED_LABEL_BORDER_THICKNESS 0
#define DEFAULT_BUTTON_CLICKED_SCALE glm::vec2( 1.0f, 1.0f )
#define DEFAULT_BUTTON_CLICKED_CURSOR Sonar::Mouse::Cursor::Hand
#define DEFAULT_BUTTON_CLICKED_MOUSE_BUTTON Sonar::Mouse::Button::Left
