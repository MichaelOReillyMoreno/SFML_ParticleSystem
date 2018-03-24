#ifndef PARTICLES_EDITOR
#define PARTICLES_EDITOR

#include <SFML/Graphics.hpp>
#include "ParticleSystem.hpp"

#include "CircleEmission_module.hpp"
#include "RectangleEmission_module.hpp"

using namespace sf;

namespace RaghallaighEngine
{
	class ParticlesSystemEditor
	{

	public:

		//shape module vars
		sf::Vector2f position;
		float width;
		float height;
		float radius;

		//shape module vars
		sf::Time lifetime;
		StartLifeTime startLifeTime;
		AlphaOverLifeTime alphaOverLifeTime;
		sf::Color initialColor;
		sf::Color finalColor;

		//shape module vars
		unsigned int angle;
		DirectionEmission direction;

		//shape module vars
		int speed;
		StartSpeed  startSpeed;

	private:

		//modules
		RectangleEmission_module rectangleEmission_module;
		CircleEmission_module circleEmission_module;
		Time_module time_module;
		AngleEmission_module angleEmission_module;
		Velocity_module velocity_module;

	public:

		ParticleSystem  particleSystem;

	public:

		ParticlesSystemEditor(size_t nParticles, sf::Vector2f _position, float _width, float _height, 
							  const sf::Time _lifetime, StartLifeTime _startLifeTime, AlphaOverLifeTime _alphaOverLifeTime,
							  sf::Color _initialColor, sf::Color _finalColor,
							  unsigned int _angle,DirectionEmission _direction, 
							  int _speed, StartSpeed  _startSpeed) :

							  width(_width), height(_height), radius(1)
							  ,position(_position), rectangleEmission_module(position, height, width),
							  circleEmission_module(position, _height),
			
							  startLifeTime(_startLifeTime), alphaOverLifeTime(_alphaOverLifeTime), lifetime(_lifetime),
							  initialColor(_initialColor), finalColor(_finalColor),
							  time_module(startLifeTime, alphaOverLifeTime, lifetime, initialColor, finalColor),

							  angle(_angle), direction(_direction), angleEmission_module(direction, angle),

							  speed(_speed), startSpeed(_startSpeed), velocity_module(startSpeed, speed),

							  particleSystem(nParticles, rectangleEmission_module, angleEmission_module, velocity_module, time_module)
		{}

		ParticlesSystemEditor(size_t nParticles, sf::Vector2f _position, float _radius,
							  const sf::Time _lifetime, StartLifeTime _startLifeTime, AlphaOverLifeTime _alphaOverLifeTime,
							  sf::Color _initialColor, sf::Color _finalColor,
							  unsigned int _angle, DirectionEmission _direction,
							  int _speed, StartSpeed  _startSpeed) :

			width(1), height(1), radius(_radius)
			, position(_position), rectangleEmission_module(position, height, width),
			circleEmission_module(position, radius),

			startLifeTime(_startLifeTime), alphaOverLifeTime(_alphaOverLifeTime), lifetime(_lifetime),
			initialColor(_initialColor), finalColor(_finalColor),
			time_module(startLifeTime, alphaOverLifeTime, lifetime, initialColor, finalColor),

			angle(_angle), direction(_direction), angleEmission_module(direction, angle),

			speed(_speed), startSpeed(_startSpeed), velocity_module(startSpeed, speed),

			particleSystem(nParticles, circleEmission_module, angleEmission_module, velocity_module, time_module)
		{}
	};

}
#endif