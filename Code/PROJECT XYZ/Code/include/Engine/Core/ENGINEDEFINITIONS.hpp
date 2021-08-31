#pragma once

/**
* \brief Engine version
*/
#define ENGINE_VERSION "0.01 Pre-Release"

/**
* \brief Game window width
*/
#define SCREEN_WIDTH 1280
/**
* \brief Game window height
*/
#define SCREEN_HEIGHT 720

/**
* \brief Default corner for stats
* 
* -1 - No corner (free moving)
* 0 - Top left
* 1 - Top right
* 2 - Bottom left
* 3 - Bottom right
*/
#define COMPUTER_STATS_DEFAULT_CORNER 1

/**
* \brief Opacity of the background
* 
* 0 being fully transparent, 1 being fully opaque
*/
#define COMPUTER_STATS_BACKGROUND_OPACITY 0.45f

/**
* \brief Game window title
*/
#define WINDOW_TITLE "PR0J3CT XY2"

/**
* \brief How many times per second should the FPS be updated
*/
#define DEBUG_FPS_UPDATE_FREQUENCY 10.0f

/**
* \brief Whether or not to show the system stats overlay on launch
*/
#define SHOW_SYSTEM_STATS_OVERLAY_ON_LAUNCH true

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
#define DEFAULT_CHECKBOX_OUTSIDE_LAYER_BORDER_THICKNESS 10.0f
#define DEFAULT_CHECKBOX_OUTSIDE_LAYER_BORDER_COLOR Color::Black
#define DEFAULT_CHECKBOX_OUTSIDE_LAYER_INSIDE_COLOR Color::Transparent
#define DEFAULT_CHECKBOX_INSIDE_LAYER_INSIDE_COLOR Color::Black
#define DEFAULT_CHECKBOX_IS_MOUSE_OVER_ALPHA_MULTIPLIER 0.75f

/**
* \brief Default radio button properties
*/
#define DEFAULT_RADIO_BUTTON_CLICKED_MOUSE_BUTTON Sonar::Mouse::Button::Left
#define DEFAULT_RADIO_BUTTON_IS_CLICKED_STATUS false
#define DEFAULT_RADIO_BUTTON_OUTER_LAYER_SIZE glm::vec2( 100, 100 )
#define DEFAULT_RADIO_BUTTON_INSIDE_LAYER_SIZE glm::vec2( 80, 80 )
#define DEFAULT_RADIO_BUTTON_OUTSIDE_LAYER_BORDER_THICKNESS 10.0f
#define DEFAULT_RADIO_BUTTON_OUTSIDE_LAYER_BORDER_COLOR Color::Black
#define DEFAULT_RADIO_BUTTON_OUTSIDE_LAYER_INSIDE_COLOR Color::Transparent
#define DEFAULT_RADIO_BUTTON_INSIDE_LAYER_INSIDE_COLOR Color::Black
#define DEFAULT_RADIO_BUTTON_IS_MOUSE_OVER_ALPHA_MULTIPLIER 0.75f
#define DEFAULT_RADIO_BUTTON_RADIUS 50.0f

/**
* \brief Default slider properties
*/
#define DEFAULT_SLIDER_CURRENT_VALUE 0.0f
#define DEFAULT_SLIDER_MINIMUM_VALUE 0.0f
#define DEFAULT_SLIDER_MAXIMUM_VALUE 100.0f
#define DEFAULT_SLIDER_JUMP_AMOUNT 10.0f
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
* \brief Default progress bar properties
*/
#define DEFAULT_PROGRESS_BAR_CURRENT_VALUE 0.0f
#define DEFAULT_PROGRESS_BAR_MINIMUM_VALUE 0.0f
#define DEFAULT_PROGRESS_BAR_MAXIMUM_VALUE 100.0f
#define DEFAULT_PROGRESS_BAR_JUMP_AMOUNT 1.0f
#define DEFAULT_PROGRESS_BAR_BACKGROUND_COLOR Color::Black
#define DEFAULT_PROGRESS_BAR_BACKGROUND_BORDER_THICKNESS 0.0f
#define DEFAULT_PROGRESS_BAR_BACKGROUND_BORDER_COLOR Color::Transparent
#define DEFAULT_PROGRESS_BAR_VALUE_BAR_COLOR Color::White
#define DEFAULT_PROGRESS_BAR_VALUE_BAR_BORDER_THICKNESS 0.0f
#define DEFAULT_PROGRESS_BAR_VALUE_BAR_BORDER_COLOR Color::Transparent
#define DEFAULT_PROGRESS_BAR_HORIZONTAL_BACKGROUND_WIDTH 200.0f
#define DEFAULT_PROGRESS_BAR_HORIZONTAL_BACKGROUND_HEIGHT 20.0f
#define DEFAULT_PROGRESS_BAR_VERTICAL_BACKGROUND_WIDTH 20.0f
#define DEFAULT_PROGRESS_BAR_VERTICAL_BACKGROUND_HEIGHT 200.0f
#define DEFAULT_PROGRESS_BAR_VALUE_BAR_SIZE_PERCENT 0.95f // (0 is 0%, 1.0 is 100%)

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
#define DEFAULT_BUTTON_GROUP_GAP 64.0f
#define DEFAULT_BUTTON_GROUP_POSITION glm::vec2( 0, 0 )
#define DEFAULT_BUTTON_GROUP_KEYBOARD_TRIGGER_KEY Sonar::Keyboard::Key::Enter
#define DEFAULT_BUTTON_GROUP_MOUSE_CLICK_BUTTON Sonar::Mouse::Button::Left
#define DEFAULT_BUTTON_GROUP_KEYBOARD_VERTIICAL_NAVIGATION_KEYS std::pair<Sonar::Keyboard::Key, Sonar::Keyboard::Key> { Keyboard::Key::Up, Keyboard::Key::Down }
#define DEFAULT_BUTTON_GROUP_KEYBOARD_HORIZONTAL_NAVIGATION_KEYS std::pair<Sonar::Keyboard::Key, Sonar::Keyboard::Key> { Keyboard::Key::Left, Keyboard::Key::Right }

/**
* \brief Default minimap properties
*/
#define DEFAULT_MINIMAP_BACKGROUND_COLOR Color::Black
#define DEFAULT_MINIMAP_BACKGROUND_BORDER_THICKNESS 0.0f
#define DEFAULT_MINIMAP_BACKGROUND_BORDER_COLOR Color::Transparent
#define DEFAULT_MINIMAP_BACKGROUND_WIDTH 256
#define DEFAULT_MINIMAP_BACKGROUND_HEIGHT 256
#define DEFAULT_MINIMAP_INTERNAL_MAP_WIDTH DEFAULT_MINIMAP_BACKGROUND_WIDTH
#define DEFAULT_MINIMAP_INTERNAL_MAP_HEIGHT DEFAULT_MINIMAP_BACKGROUND_HEIGHT
#define DEFAULT_MINIMAP_OBJECT_RADIUS 2.0f
#define DEFAULT_MINIMAP_OBJECT_COLOR Color::Red
