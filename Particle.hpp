#pragma once
#ifndef PARTICLE_HEADER
#define PARTICLE_HEADER


#include <SFML/Graphics.hpp>
#include "AngleEmission_module.hpp"
#include "ShapeEmission_module.hpp"
#include "Velocity_module.hpp"
#include "Time_module.hpp"

namespace RaghallaighEngine
{


	/**
	* Representa una única partícula.
	*
	* @author Michael O'Reilly
	*/

	class Particle
	{

	private:

		//variables propias de la particula, tiempo de vida, angulo, vertice que dibujar...

		sf::Time currentLifeTime;

		sf::Vertex & vertex;

		unsigned int angle;

		sf::Vector2f velocity;

		//Referencias a distintos módulos

		ShapeEmission_module & shapeEmission_module;
		AngleEmission_module & angleEmission_module;
		Velocity_module & velocity_module;
		Time_module & time_module;

	public:

		Particle(AngleEmission_module & _angleEmission, Velocity_module & _velocity_module, 
				 ShapeEmission_module & _area, Time_module & _time_module, sf::Vertex & _vertex) :
			     angleEmission_module(_angleEmission), velocity_module(_velocity_module), 
				 shapeEmission_module(_area), time_module(_time_module),
				 vertex(_vertex)
		{
			currentLifeTime = time_module.GetLifeTime();
		}
		//currentLifeTime(time_module.GetLifeTime() error, fix bug. Module not initialize

		void Update(sf::Time & elapsed);

		void Reset();
	};
}
#endif