GAME
-----------------------------------------------------------------
* Fluid box2d


ENGINE
-----------------------------------------------------------------
* Input manager - CHECK ALL INPUT
    - Sequences/QTE (maybe a separate thing)
    - Time tracked events (press key/chord for x amount of time)
    - Gestures
* Clearing the screen colour abstraction
* Sprite/Drawable culling outside of the screen
* Collision Detection (In Drawable) - Bounding box
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
- Migrate game folder classes to using sprite class
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
        - **MAKE IT LIKE DOOMS**
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
* CMAKE (NOT YET)
