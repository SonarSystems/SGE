#pragma once

/**
 * Precompiled Include File
*/

/**
* \brief STD Library files
*/
#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

/**
* \brief ImGUI Library
*/
#include <imgui.h>
#include <imgui-SFML.h>

/**
* \brief SFML Library files
*/
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
* \brief External Library Files
*/
#include <External/Collision.hpp>
#include <External/glm/glm.hpp>
#include "SysInfo.hpp"

/**
* \brief Custom files (including external libraries manually included and not linked)
*/
#include "Core/ENGINEDEFINITIONS.hpp"
#include "Core/Debug.hpp"
#include "Core/Time.hpp"
#include "Core/Clock.hpp"
#include "External/Collision.hpp"
#include "External/csv.hpp"
#include "External/Gamepad.h"
#include "External/json.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/Font.hpp"
#include "Graphics/ScrollingBackground.hpp"
#include "Graphics/Parallax.hpp"
#include "Graphics/Shapes/Circle.hpp"
#include "Graphics/View.hpp"
#include "Input/Joystick.hpp"
#include "Input/Gesture.hpp"
#include "Input/Keyboard.hpp"
#include "Input/Mouse.hpp"
#include "Input/Sequence.hpp"
#include "Graphics/Drawable.hpp"
#include "Graphics/Texture.hpp"
#include "Graphics/Sprite.hpp"
#include "Graphics/Shapes/Triangle.hpp"
#include "Graphics/Shapes/Rectangle.hpp"
#include "Graphics/Label.hpp"
#include "Graphics/Checkbox.hpp"
#include "Input/QTE.hpp"
#include "Input/RBM.hpp"
#include "Input/Sensor.hpp"
#include "Input/Events.hpp"
#include "Core/Window.hpp"
#include "Graphics/TextBox.hpp"
#include "Core/State.hpp"
#include "Core/StateMachine.hpp"
#include "Graphics/MenuComponent.hpp"
#include "Graphics/Button.hpp"
#include "Graphics/ButtonGroup.hpp"
#include "Graphics/Slider.hpp"
#include "Graphics/Menu.hpp"
#include "Graphics/RadioButton.hpp"
#include "Graphics/RadioButtonGroup.hpp"
#include "Graphics/ProgressBar.hpp"
#include "Graphics/Minimap.hpp"
#include "Input/Input.hpp"
#include "Managers/AssetManager.hpp"
#include "Managers/FileManager.hpp"
#include "Managers/HighScoreManager.hpp"
#include "Managers/MapManager.hpp"
#include "Core/Game.hpp"
#include "Audio/AudioItem.hpp"
#include "Audio/Music.hpp"