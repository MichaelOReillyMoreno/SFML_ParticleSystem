#pragma once
#ifndef VELOCITY_HEADER
#define VELOCITY_HEADER

namespace RaghallaighEngine
{
	/**
	* random = velocidad aleatoria, constant = constante
	*/
	enum class StartSpeed { random, constant };

	/**
	* Representa un modulo que otorga velocidad.
	*
	* @author Michael O'Reilly
	*/
	class Velocity_module
	{
	private:

		StartSpeed & startSpeed;
		int & speed;
		int currentSpeed;

	public:

		Velocity_module(StartSpeed  & _startSpeed, int & _speed) :
						startSpeed(_startSpeed), speed(_speed) {}

		/**
		* Da una nueva velocidad a la partícula
		*/
		void Reset(sf::Vector2f & velocity, unsigned int & angle)
		{
			currentSpeed = (startSpeed == StartSpeed::constant) ? speed : (std::rand() % speed) + speed;
			velocity = sf::Vector2f(static_cast<float>(std::cos(angle) * currentSpeed), static_cast<float>(std::sin(angle) * currentSpeed));
		}

	};
}
#endif