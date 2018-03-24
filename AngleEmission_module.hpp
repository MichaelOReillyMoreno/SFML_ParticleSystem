#pragma once
#ifndef ANGLEEMISSION_HEADER
#define ANGLEEMISSION_HEADER

#include <SFML/Graphics.hpp>

namespace RaghallaighEngine
{  
	/**
	*random = ángulo aleatorio, angle = ángulo fijo,(en construcción) allDirections = otorga un ángulo en función de su posicion respecto al origen,
	*rotation = crea "curvas"
	*/
	enum class DirectionEmission { random, angle, allDirections, rotation };

	/**
	* Representa un modulo que otorga un ángulo a cada particula en función de su configuración .
	*
	* @author Michael O'Reilly
	*/

	class AngleEmission_module
	{

	private:

		DirectionEmission & directionEmission;

		unsigned int angle;

	public:

		AngleEmission_module(DirectionEmission & _directionEmission, unsigned int & _angle) :
					  angle(_angle), directionEmission(_directionEmission){}

		/**
		* Otorga un ángulo a cada particula en función de su configuración .
		*/
		unsigned int GetAngleEmission(sf::Vector2f & position, sf::Vector2f & origin);
	};
}
#endif