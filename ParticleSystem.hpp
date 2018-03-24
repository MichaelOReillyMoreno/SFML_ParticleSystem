#ifndef PARTICLES_SYSTEM_HEADER
#define PARTICLES_SYSTEM_HEADER
#pragma once


#include "Particle.hpp"

namespace RaghallaighEngine
{
	/**
	* Representa el sistema de partículas en sí.
	*
	* @author Michael O'Reilly
	*/

	class ParticleSystem : public sf::Drawable, public sf::Transformable
	{
	public:

		/* Contiene las paticulas */
		std::vector<Particle> particles;

		/* Contiene llos vertices de las particulas, facilita su dibujado*/
		sf::VertexArray vertices;


		ParticleSystem(size_t & nParticles, ShapeEmission_module & _area, AngleEmission_module & _angleEmission, 
					   Velocity_module & _velocity_module, Time_module & _time_module) : vertices(sf::Points, nParticles)
		{
			particles.reserve(nParticles);

			for (size_t i = 0; i < nParticles; ++i)
			{
				particles.push_back(Particle(_angleEmission, _velocity_module, _area, _time_module, vertices[i]));
			}
		}

		/**
		* Actualiza los valores de las partículas
		*/
		void Update(sf::Time & elapsed)
		{
			for (std::size_t i = 0; i < particles.size(); ++i)
			{
				particles[i].Update(elapsed);
			}
		}

		/**
		* Dibuja las partículas de la forma más optima posible en SFML, al contener la clase los vertices en un VertexArray 
		* y heredar de Drawable y Transformable
		*/
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			target.draw(vertices, states);
		}
	};
}
#endif