GAME
-----------------------------------------------------------------
* Fluid box2d


ENGINE
-----------------------------------------------------------------
* Input manager - CHECK ALL INPUT
    - QTE Mouse and Joystick
    - Gestures
        - Circular rotations on the analogue sticks
    - Rumble
* Objects move faster when scrolling aswell, bug I believe, check it out
* Debug
    - Toggle different message categories on and off
        - Use a list/vector of the name of the categories that are disabled to see if the message is to be displayed
    - Box2d shape rendering toggle
    - Print cast anything to string (ATM IT ONLY ACCEPTS STRINGS WHICH IS VERY LIMITED AND THUS COUT HAS TO BE USED MOST OF THE TIME)
* Sprite
* Shapes
    - Circle
    - Triangle
        - Equilateral
        - Vertex based
* Parallax background
* Migrate game folder classes to using sprite class
* File loading
* Saving and loading (link with file loading)
    - Single pieces of data
    - Chunks of data like a database
* GUI - https://github.com/Hopson97/SFML-Game-Framework
    - Menu system - https://www.youtube.com/watch?v=4Vg9d1pjL20
        - Mouse support
        - Keyboard support
        - Drawing
        - Hover
        - Textures for buttons
            - Hover
            - Colour masking
    - Labels
        - Tick up/down to a number from a number over a set duration
    - Textbox
    - Radio button
    - Checkbox
    - FPS counter - https://github.com/Hopson97/SFML-Game-Framework/blob/master/Source/Util/FPSCounter.cpp
        - **Part of DEBUG CLASS**
        - **MAKE IT LIKE DOOM'S**
        - Draw calls count
        - Indices count
        - Vertices count
        - Triangles count
        - Quads count
    - Mini map
        - Square
        - Rounded
        - Draw using shapes, ability to override using sprites
* Update SFML
* Shadows
* Fog
* Ray tracing
* Networking
* Alt + F4 to close (make it optional to enable from the developers point of view)
* AI
    - A star
* Camera
* CMAKE (NOT YET)
* Accessibilty for blind and deaf people
    - Built in voice reader
    - Built in screen reader
