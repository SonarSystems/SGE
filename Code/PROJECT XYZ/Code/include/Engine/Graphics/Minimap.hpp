#pragma once

namespace Sonar
{
    class Minimap
    {
    public:
        /**
        * \brief Position anchors for the minimap
        */
        enum POSITION
        {
            TOP_LEFT = 0,
            TOP_CENTER,
            TOP_RIGHT,
            RIGHT_CENTER,
            BOTTOM_RIGHT,
            BOTTOM_CENTER,
            BOTTOM_LEFT,
            LEFT_CENTER,
            CENTER
        };

        /**
        * \brief Object properties struct
        */
        struct ObjectProperty
        {
            Circle *_shape;
            std::string _type;
            glm::vec2 _position;
            bool _isShowing;
        };

        /**
        * \brief Class constructor
        *
		* \param data Game data object
        */
        Minimap( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~Minimap( );
        
        /**
        * \brief Draw the classes objects
        */
        void Draw( );

        /**
        * \brief Update the classes objects
        *
        * \param dt Delta time (difference between frames)
        */
        void Update( const float &dt );

        /**
        * \brief Set x and y position based on the a POSITION anchor
        *
        * \param position POSITION anchor to position the minimap
        */
        void SetPosition( const POSITION &position );

        /**
        * \brief Set x and y position
        *
        * \param position X and Y position
        */
        void SetPosition( const glm::vec2 &position );

        /**
        * \brief Set the position (x and y)
        *
        * \param x X position
        * \param y Y position
        */
        void SetPosition( const float &x, const float &y );

        /**
        * \brief Set the x position
        *
        * \param x X position
        */
        void SetPositionX( const float &x );

        /**
        * \brief Set the y position
        *
        * \param y Y position
        */
        void SetPositionY( const float &y );

        /**
        * \brief Get the x position
        *
        * \return Output returns the x position
        */
        float GetPositionX( ) const;

        /**
        * \brief Get the y position
        *
        * \return Output returns the y position
        */
        float GetPositionY( ) const;

        /**
        * \brief Get the position vector
        *
        * \return Output returns the position vector
        */
        glm::vec2 GetPosition( ) const;

        /**
        * \brief Set the background size
        *
        * \param size Width and height of the background
        */
        void SetBackgroundSize( const glm::vec2 &size );

        /**
        * \brief Set the background size
        *
        * \param width Width of the background
        * \param height Height of the background
        */
        void SetBackgroundSize( const float &width, const float &height );

        /**
        * \brief Set the background width
        *
        * \param width Width of the background
        */
        void SetBackgroundWidth( const float &width );

        /**
        * \brief Set the background height
        *
        * \param height Height of the background
        */
        void SetBackgroundHeight( const float &height );

        /**
        * \brief Get the background size
        *
        * \return Output returns the background size
        */
        glm::vec2 GetBackgroundSize( ) const;

        /**
        * \brief Get the background width
        *
        * \return Output returns the background width
        */
        float GetBackgroundWidth( ) const;

        /**
        * \brief Get the background height
        *
        * \return Output returns the background height
        */
        float GetBackgroundHeight( ) const;

        /**
        * \brief Set the color of the background
        *
        * \param color Color object
        */
        void SetBackgroundColor( const Color &color );

        /**
        * \brief Set the background border thickness
        *
        * \param thickness Thickness of the border
        *
        * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetBackgroundBorderThickness( const float &thickness );

        /**
        * \brief Set the color of the background border
        *
        * \param color Color object
        */
        void SetBackgroundBorderColor( const Color &color );

        /**
        * \brief Get the background color
        *
        * \return Output returns the background color
        */
        Color GetBackgroundColor( ) const;

        /**
        * \brief Get the background border thickness
        *
        * \return Output returns the border thickness
        */
        float GetBackgroundBorderThickness( ) const;

        /**
        * \brief Get the background border color
        *
        * \return Output returns the checked color
        */
        Color GetBackgroundBorderColor( ) const;

        /**
        * \brief Move the object relative to it's current position in the x and y axis
        *
        * \param offset Offset in x and y axis
        */
        void Move( const glm::vec2 &offset );

        /**
        * \brief Move the object relative to it's current position in the x and y axis
        *
        * \param x Offset in x axis
        * \param y Offset in y axis
        */
        void Move( const float &x, const float &y );

        /**
        * \brief Move the object relative to it's current position in the x axis
        *
        * \param x Offset in x axis
        */
        void MoveX( const float &x );

        /**
        * \brief Move the object relative to it's current position in the y axis
        *
        * \param y Offset in y axis
        */
        void MoveY( const float &y );

        /**
        * \brief Set the scale factor
        *
        * \param scale Scale factor
        */
        void SetScale( const float &scale );

        /**
        * \brief Scale the object relative to it's current scale
        *
        * \param scale Scale factor
        */
        void Scale( const float &scale );

        /**
        * \brief Get the scale factor
        *
        * \return Output returns the scale factor
        */
        float GetScale( ) const;

        /**
        * \brief Get the local bounds (for the background)
        *
        * \return Output returns the shape's local bounds
        */
        glm::vec4 GetLocalBounds( ) const;

        /**
        * \brief Get the global bounds (for the background)
        *
        * \return Output returns the shape's global bounds
        */
        glm::vec4 GetGlobalBounds( ) const;

        /**
        * \brief Is the mouse hovering over the slider
        *
        * \return Output returns the true or false for the hover event
        */
        bool IsMouseOver( ) const;

		/**
		* \brief Set the map size
		*
		* \param size Width and height of the map
		*/
		void SetMapSize( const glm::vec2 &size );

		/**
		* \brief Set the map size
		*
		* \param width Width of the map
		* \param height Height of the map
		*/
		void SetMapSize( const float &width, const float &height );

		/**
		* \brief Set the map width
		*
		* \param width Width of the map
		*/
		void SetMapWidth( const float &width );

		/**
		* \brief Set the map height
		*
		* \param height Height of the map
		*/
		void SetMapHeight( const float &height );

		/**
		* \brief Get the map size
		*
		* \return Output returns the map size
		*/
		glm::vec2 GetMapSize( ) const;

		/**
		* \brief Get the map width
		*
		* \return Output returns the map width
		*/
		float GetMapWidth( ) const;

		/**
		* \brief Get the map height
		*
		* \return Output returns the map height
		*/
		float GetMapHeight( ) const;
        
        /**
        * \brief Add an object to the minimap
        *
		* \param type Type of object
		* \param position Position of the object
		* \param radius Radius of the object
		* \param color Background color of the object
        *
        * \return Output returns the ID of the object just added
        */
		[[nodiscard]] unsigned int AddObject( const std::string &type, const glm::vec2 &position, const float &radius = DEFAULT_MINIMAP_OBJECT_RADIUS, const Color &color = DEFAULT_MINIMAP_OBJECT_COLOR );

        /**
        * \brief Remove object by ID
        *
        * \param id ID of the object to be removed
        */
        void RemoveObjectByID( const unsigned int &id );

        /**
        * \brief Remove object(s) by type
        *
        * \param type Type of the object(s) to be removed
        */
        void RemoveObjectByType( const std::string &type );

        /**
        * \brief Hide object(s) by type
        *
        * \param type Type of the object(s) to be hidden
        */
        void HideObjectByType( const std::string &type );

        /**
        * \brief Show object(s) by type
        *
        * \param type Type of the object(s) to be shown
        */
        void ShowObjectByType( const std::string &type );

        /**
        * \brief Hide object
        *
        * \param id ID of the object to be removed
        */
        void HideObjectByID( const unsigned int &id );

        /**
        * \brief Show object
        *
        * \param id ID of the object to be removed
        */
        void ShowObjectByID( const unsigned int &id );

        /**
        * \brief Update an object's properties
		*
		* \param id ID of the object
        * \param type Type of object
        * \param position Position of the object
        * \param radius Radius of the object
        * \param color Background color of the object
        */
        void UpdateObjectByID( const unsigned int &id, const std::string &type, const glm::vec2 &position, const float &radius, const Color &color );

        /**
        * \brief Update an object's type
		*
		* \param id ID of the object
        * \param type Type of object
        */
		void UpdateObjectTypeByID( const unsigned int &id, const std::string &type );

        /**
        * \brief Update an object's position
		*
		* \param id ID of the object
        * \param position Position of the object
        */
		void UpdateObjectPositionByID( const unsigned int &id, const glm::vec2 &position );

        /**
        * \brief Update an object's radius/size
		*
		* \param id ID of the object
        * \param radius Radius of the object
        */
        void UpdateObjectRadiusByID( const unsigned int &id, const float &radius );

        /**
        * \brief Update an objects color
		*
		* \param id ID of the object
        * \param color Background color of the object
        */
        void UpdateObjectColorByID( const unsigned int &id, const Color &color );

        /**
        * \brief Update an object's properties
        *
        * \param oldType Type of the current object(s)
        * \param type Type of object
        * \param position Position of the object
        * \param radius Radius of the object
        * \param color Background color of the object
        */
        void UpdateObjectByType( const std::string &oldType, const std::string &type, const glm::vec2 &position, const float &radius, const Color &color );

        /**
        * \brief Update an object's type
		*
		* \param type oldType of the current object(s)
        * \param type Type of object
        */
        void UpdateObjectTypeByType( const std::string &oldType, const std::string &type );

        /**
        * \brief Update an object's position
		*
		* \param type Type of the current object(s)
        * \param position Position of the object
        */
        void UpdateObjectPositionByType( const std::string &type, const glm::vec2 &position );

        /**
        * \brief Update an object's radius/size
		*
		* \param type Type of the current object(s)
        * \param radius Radius of the object
        */
        void UpdateObjectRadiusByType( const std::string &type, const float &radius );

        /**
        * \brief Update an object's color
		*
		* \param type Type of the current object(s)
        * \param color Background color of the object
        */
        void UpdateObjectColorByType( const std::string &type, const Color &color );

    private:
        /**
        * \brief Is point within specified range range
        *
        * \param point Point to check within range
        * \param start Start of the range
        * \param end End of the range
        *
        * \return Output returns the true if the point is within the range and false if it is not
        */
        bool IsPointWithinRange( const float &point, const float &start, const float &end ) const;

        /**
        * \brief Does the object exist
        *
        * \param id ID of the object
        *
        * \return Output returns true if the object exists and false if it does not
        */
        bool DoesObjectExist( const unsigned int &id );

        /**
        * \brief Game data object
        */
        GameDataRef _data;

        /**
        * \brief Slider background
        */
        Rectangle *_background;

        /**
        * \brief Internal map size
        */
        glm::vec2 _mapSize;

        /**
        * \brief Objects to be displayed on the minimap
        */
        std::unordered_map<unsigned int, ObjectProperty> _objects;

        /**
        * \brief The type of objects that won't be drawn but aren't removed
        */
        std::vector<std::string> _typesToHide;

    };
}
