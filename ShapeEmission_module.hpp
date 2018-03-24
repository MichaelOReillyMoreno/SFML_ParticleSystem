#pragma once
#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include <SFML/Graphics.hpp>

namespace RaghallaighEngine
{
	/**
	* Representa un modulo que otorga una posicion dentro de un área (virtual) .
	*
	* @author Michael O'Reilly
	*/

	class ShapeEmission_module
	{
	protected:

		sf::Vector2f & position;

	public:

		ShapeEmission_module(sf::Vector2f & _position) : position(_position) {}

		virtual ~ShapeEmission_module() {}

		virtual sf::Vector2f GetRandomPointInArea() = 0;

		sf::Vector2f & GetPostion() {return position;}

	};
}
#endif