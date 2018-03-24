#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER

#include "ShapeEmission_module.hpp"

namespace RaghallaighEngine
{
	/**
	* Representa un modulo que otorga una posicion dentro de un área circular .
	*
	* @author Michael O'Reilly
	*/
	class CircleEmission_module : public ShapeEmission_module
	{
	private:

		float & radius;
		const float PI;

	public:

		CircleEmission_module(sf::Vector2f & _position, float & _radius) : ShapeEmission_module(_position), radius(_radius), PI(3.14f) {}

		~CircleEmission_module() {}

		/**
		* Otorga una posicion aleatoria dentro de un área circular .
		*/
		inline sf::Vector2f GetRandomPointInArea()
		{
			float angle = static_cast<float>(rand()* 3.14 * 2);

			return sf::Vector2f(position.x + cos(angle)*radius, position.y +  sin(angle)*radius);
		}

	};
}
#endif