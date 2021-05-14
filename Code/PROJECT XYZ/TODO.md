GAME
-----------------------------------------------------------------

ENGINE
-----------------------------------------------------------------
* GUI
    - Mini map
        - Prevent objects outside of the background from being drawm
        - Method for removing objects
        - Method for updating existing objects positions, maybe use the object struct and pass in using pointers so they are linked
        - Zoom level
    - FPS counter - https://github.com/Hopson97/SFML-Game-Framework/blob/master/Source/Util/FPSCounter.cpp
        - ***LOOK INTO IMGUI ESPECIALLY FOR THE GRAPH STUFF***
        - **Part of DEBUG CLASS**
        - **MAKE IT LIKE DOOM'S**
        - Choose which corner of the screen to put it in
        - Draw calls count
        - Indices count
        - Vertices count
        - Triangles count
        - Quads count
* Fix all warnings
* Music and sound items
* Port AssetManager to Sonar Classes
* Sorting algorithms, bubble sort, quick sort, insert sort
* Anti Aliasing and other settings for SFML
* Abstract dt into GameData struct in the Game.hpp, only for Sonar classes not states, states still get dt
* Set background color of the clear method (currently set in Game.hpp in the struct)
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
* Buttons (rotation, pivot)