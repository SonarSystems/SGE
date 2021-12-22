#pragma once

#include "pch.hpp"

namespace Sonar
{
	struct Math
	{
		static const glm::vec2 &SFMLVector2FToGLMvec2( const sf::Vector2f &vector )
		{ return glm::vec2( vector.x, vector.y ); }

		static const sf::Vector2f &GLMvec2ToSFMLVector2F( const glm::vec2 &vector )
		{ return sf::Vector2f( vector.x, vector.y ); }

		static const glm::vec3 &SFMLVector3FToGLMvec3( const sf::Vector3f &vector )
		{ return glm::vec3( vector.x, vector.y, vector.z ); }

		static const sf::Vector3f &GLMvec3ToSFMLVector3F( const glm::vec3 &vector )
		{ return sf::Vector3f( vector.x, vector.y, vector.z ); }
	};
}
