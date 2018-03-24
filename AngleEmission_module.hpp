#pragma once
#ifndef ANGLEEMISSION_HEADER
#define ANGLEEMISSION_HEADER

#include <SFML/Graphics.hpp>

namespace RaghallaighEngine
{  
	/**
	*random = �ngulo aleatorio, angle = �ngulo fijo,(en construcci�n) allDirections = otorga un �ngulo en funci�n de su posicion respecto al origen,
	*rotation = crea "curvas"
	*/
	enum class DirectionEmission { random, angle, allDirections, rotation };

	/**
	* Representa un modulo que otorga un �ngulo a cada particula en funci�n de su configuraci�n .
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
		* Otorga un �ngulo a cada particula en funci�n de su configuraci�n .
		*/
		unsigned int GetAngleEmission(sf::Vector2f & position, sf::Vector2f & origin);
	};
}
#endif