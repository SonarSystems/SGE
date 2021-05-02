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

/**
* \brief Default text box properties
*/
#define DEFAULT_TEXTBOX_MAXIMUM_CHARACTERS 32
#define DEFAULT_TEXTBOX_BLINKER_TIME 0.5
#define DEFAULT_TEXTBOX_CLICKED_MOUSE_BUTTON Sonar::Mouse::Button::Left
#define DEFAULT_TEXTBOX_HOVER_CURSOR Sonar::Mouse::Cursor::Text
#define DEFAULT_TEXTBOX_NO_HOVER_CURSOR Sonar::Mouse::Cursor::Arrow
#define DEFAULT_TEXTBOX_IS_DEBUG_DRAWING false

/**
* \brief Default checkbox properties
*/
#define DEFAULT_CHECKBOX_CLICKED_MOUSE_BUTTON Sonar::Mouse::Button::Left
#define DEFAULT_CHECKBOX_IS_CLICKED_STATUS false
#define DEFAULT_CHECKBOX_OUTER_LAYER_SIZE glm::vec2( 100, 100 )
#define DEFAULT_CHECKBOX_INSIDE_LAYER_SIZE glm::vec2( 80, 80 )
#define DEFAULT_CHECKBOX_OUTSIDE_LAYER_BORDER_THICKNESS 10
#define DEFAULT_CHECKBOX_OUTSIDE_LAYER_BORDER_COLOR Color::Black
#define DEFAULT_CHECKBOX_OUTSIDE_LAYER_INSIDE_COLOR Color::Transparent
#define DEFAULT_CHECKBOX_INSIDE_LAYER_INSIDE_COLOR Color::Black
#define DEFAULT_CHECKBOX_IS_MOUSE_OVER_ALPHA_MULTIPLIER 0.75

/**
* \brief Default radio button properties
*/
#define DEFAULT_RADIO_BUTTON_CLICKED_MOUSE_BUTTON Sonar::Mouse::Button::Left
#define DEFAULT_RADIO_BUTTON_IS_CLICKED_STATUS false
#define DEFAULT_RADIO_BUTTON_OUTER_LAYER_SIZE glm::vec2( 100, 100 )
#define DEFAULT_RADIO_BUTTON_INSIDE_LAYER_SIZE glm::vec2( 80, 80 )
#define DEFAULT_RADIO_BUTTON_OUTSIDE_LAYER_BORDER_THICKNESS 10
#define DEFAULT_RADIO_BUTTON_OUTSIDE_LAYER_BORDER_COLOR Color::Black
#define DEFAULT_RADIO_BUTTON_OUTSIDE_LAYER_INSIDE_COLOR Color::Transparent
#define DEFAULT_RADIO_BUTTON_INSIDE_LAYER_INSIDE_COLOR Color::Black
#define DEFAULT_RADIO_BUTTON_IS_MOUSE_OVER_ALPHA_MULTIPLIER 0.75
#define DEFAULT_RADIO_BUTTON_RADIUS 50

/**
* \brief Default slider properties
*/
#define DEFAULT_SLIDER_CURRENT_VALUE 0.0f
#define DEFAULT_SLIDER_MINIMUM_VALUE 0.0f
#define DEFAULT_SLIDER_MAXIMUM_VALUE 100.0f
#define DEFAULT_SLIDER_JUMP_AMOUNT 0.0f
#define DEFAULT_SLIDER_BACKGROUND_COLOR Color::Black
#define DEFAULT_SLIDER_BACKGROUND_BORDER_THICKNESS 0.0f
#define DEFAULT_SLIDER_BACKGROUND_BORDER_COLOR Color::Transparent
#define DEFAULT_SLIDER_KNOB_COLOR Color::Red
#define DEFAULT_SLIDER_KNOB_BORDER_THICKNESS 0.0f
#define DEFAULT_SLIDER_KNOB_BORDER_COLOR Color::Transparent
#define DEFAULT_SLIDER_HORIZONTAL_BACKGROUND_WIDTH 200.0f
#define DEFAULT_SLIDER_HORIZONTAL_BACKGROUND_HEIGHT 20.0f
#define DEFAULT_SLIDER_VERTICAL_BACKGROUND_WIDTH 20.0f
#define DEFAULT_SLIDER_VERTICAL_BACKGROUND_HEIGHT 200.0f
#define DEFAULT_SLIDER_KNOB_RADIUS 12.0f
#define DEFAULT_SLIDER_MOUSE_BUTTON Sonar::Mouse::Button::Left

/**
* \brief Default menu properties
*/
#define DEFAULT_MENU_THEME Sonar::MenuComponent::Theme::DARK

/**
* \brief Default button group properties
*/
#define DEFAULT_BUTTON_GROUP_KEYBOARD_ENABLED true
#define DEFAULT_BUTTON_GROUP_MINIMUM_WIDTH 0
#define DEFAULT_BUTTON_GROUP_ORIENTATION Sonar::ButtonGroup::ORIENTATION::VERTICAL
#define DEFAULT_BUTTON_GROUP_GAP 64
#define DEFAULT_BUTTON_GROUP_POSITION glm::vec2( 0, 0 )
#define DEFAULT_BUTTON_GROUP_KEYBOARD_TRIGGER_KEY Sonar::Keyboard::Key::Enter
#define DEFAULT_BUTTON_GROUP_MOUSE_CLICK_BUTTON Sonar::Mouse::Button::Left
