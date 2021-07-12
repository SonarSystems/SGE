#pragma once

/**
 * Precompiled Include File
*/
/**
* \brief Library files
*/
#include <algorithm>
#include <array>
#include <cmath>
#include <External/glm/glm.hpp>
#include <filesystem>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>



/**
* \brief Custom files (including external libraries manually included and not linked)
*/
#include "Core/Debug.hpp"
#include "Core/ENGINEDEFINITIONS.hpp"
#include "Core/StateMachine.hpp"
#include "Core/Time.hpp"
#include "Core/Clock.hpp"
#include "Core/Window.hpp"
#include "External/Collision.hpp"
#include "External/csv.hpp"
#include "External/Gamepad.h"
#include "External/json.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/Font.hpp"
#include "Graphics/Menu.hpp"
#include "Graphics/MenuComponent.hpp"
#include "Graphics/Minimap.hpp"
#include "Graphics/Parallax.hpp"
#include "Graphics/ProgressBar.hpp"
#include "Graphics/RadioButton.hpp"
#include "Graphics/RadioButtonGroup.hpp"
#include "Graphics/ScrollingBackground.hpp"
#include "Graphics/Shapes/Rectangle.hpp"
#include "Graphics/Shapes/Triangle.hpp"
#include "Graphics/Slider.hpp"
#include "Graphics/Sprite.hpp"
#include "Graphics/TextBox.hpp"
#include "Graphics/Texture.hpp"
#include "Graphics/Shapes/Circle.hpp"
#include "Graphics/View.hpp"
#include "Input/Joystick.hpp"
#include "Input/Gesture.hpp"
#include "Input/Keyboard.hpp"
#include "Input/Mouse.hpp"
#include "Graphics/Drawable.hpp"
#include "Graphics/Label.hpp"
#include "Graphics/Checkbox.hpp"
#include "Graphics/Button.hpp"
#include "Graphics/ButtonGroup.hpp"
#include "Input/QTE.hpp"
#include "Input/RBM.hpp"
#include "Input/Sensor.hpp"
#include "Input/Sequence.hpp"
#include "Input/Events.hpp"
#include "Input/Input.hpp"
#include "Managers/AssetManager.hpp"
#include "Managers/FileManager.hpp"
#include "Managers/HighScoreManager.hpp"
#include "Managers/MapManager.hpp"
#include "Core/Game.hpp"