GAME
-----------------------------------------------------------------

ENGINE
-----------------------------------------------------------------
* Look into smart pointers
* Delete all pointers in all custom classes including methods where stuff is removed (release memory)
    - delete pointer;
    - pointer = nullptr;
* Make constructor and destructors that have no code into default (remove the implemention in the cpp and make the declaration in the header "= default")
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
* Mini map
    - Zoom level