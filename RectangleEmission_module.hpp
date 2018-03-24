#ifndef RECTANGLE_HEADER
#define RECTANGLE_HEADER

#include "ShapeEmission_module.hpp"

namespace RaghallaighEngine
{
	/**
	* Representa un modulo que otorga una posicion dentro de un área rectangular .
	*
	* @author Michael O'Reilly
	*/

	class RectangleEmission_module : public ShapeEmission_module
	{
	private:

		float & height;
		float & width;

		float limits_x[2];
		float limits_y[2];

	public:

		RectangleEmission_module(sf::Vector2f & _position, float & _height, float & _width) :
			ShapeEmission_module(_position), height(_height), width(_width),
			limits_x{ position.x - (width * 0.5f), position.x + (width * 0.5f) },
			limits_y{ position.y - (height * 0.5f), position.y + (height * 0.5f) } {}

		~RectangleEmission_module() {}

		/**
		* Otorga una posicion aleatoria dentro de un área rectangular .
		*/

		inline sf::Vector2f GetRandomPointInArea()
		{
			return sf::Vector2f
			(
				((limits_x[1] + 1) + (((float)rand()) / (float)RAND_MAX) * (limits_x[0] - (limits_x[1] + 1))),
				((limits_y[1] + 1) + (((float)rand()) / (float)RAND_MAX) * (limits_y[0] - (limits_y[1] + 1)))
			);
		}

	};
}
#endif