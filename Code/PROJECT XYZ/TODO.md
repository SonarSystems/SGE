GAME
-----------------------------------------------------------------

ENGINE
-----------------------------------------------------------------
* File loading
    - Map
        - specify width and height
        - place characters/numbers and methods for looping over them
* GUI - USE DRAWABLE CLASS, MAYBE HAVE A GUI CLASS THAT INHERITS DRAWABLE AND BUTTON INHERITS GUI FOR EXAMPLE
    - Menu system - https://www.youtube.com/watch?v=4Vg9d1pjL20
        - Mouse support
        - Keyboard support
        - Drawing
        - Hover
        - Textures for buttons
            - Hover
            - Colour masking
    - Labels
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
* Anti Aliasing and other settings for SFML
* Get points of screen - RETURN AS glm::vec2
    - Center
    - Top left
    - Top right
    - Bottom left
    - Bottom right
* Add grid for debugging/developing - ABILITY TO SET SPACE BETWEEN LINES AND/OR HOW MANY LINES IN BOTH AXES
* Physics
    - Box2d - MAYBE IN THE ENGINE POTENTIALLY, WILL SEE - build into the graphics classes like shapes and sprite
    - Fluid box2d
    - LiquidFun maybe, check it out
* Update SFML
* Borders on left and right or up and down going to center, like a movie changed from 16x9 to 21x9, use rectangle shape and ability to set colour
* Shadows
* Fog
* Ray tracing
* Networking
* AI
    - A star
* Camera
* VR
* CMAKE (NOT YET)
* iOS/Android
* Accessibilty for blind and deaf people
    - Built in voice reader
    - Built in screen reader


SKIPPED
-----------------------------------------------------------------
* Input manager - Motion (Wii, PS3+)
