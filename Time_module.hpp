#pragma once
#ifndef TIME_HEADER
#define TIME_HEADER

#include <SFML/Graphics.hpp>

namespace RaghallaighEngine
{
	/**
	* random = tiempo de vida aleatorio, max = tiempo de vida fijo
	*/
	enum class StartLifeTime { random, max };

	/**
	* decreases = decrece el canal alpha a lo largo del tiempo, increase = incrementa, constant = permanece constante
	*/
	enum class AlphaOverLifeTime { decreases, increase, constant };

	/**
	* Representa un modulo que otorga un tiempo de vida y un color a lo largo del tiempo.
	*
	* @author Michael O'Reilly
	*/
	class Time_module
	{
	private:

		StartLifeTime & startLifeTime;
		AlphaOverLifeTime & alphaOverLifeTime;
		sf::Time & lifetime;

		sf::Color & initialColor;
		sf::Color & finalColor;

		sf::Uint8 r, g, b, a;

		float ratio;

	public:

		Time_module(StartLifeTime & _startLifeTime, AlphaOverLifeTime & _alphaOverLifeTime, sf::Time & _lifetime,
			sf::Color & _initialColor, sf::Color & _finalColor) :
			startLifeTime(_startLifeTime), alphaOverLifeTime(_alphaOverLifeTime), lifetime(_lifetime),
			initialColor(_initialColor), finalColor(_finalColor) {}

		/**
		* Otorga un tiempo de vida.
		*/
		sf::Time GetLifeTime()
		{
			if (startLifeTime == StartLifeTime::max) return lifetime;
			else return sf::milliseconds(std::rand() % lifetime.asMilliseconds());
		}


		/**
		* Otorga un color a lo largo del tiempo.
		*/
		sf::Color SetColorOverLifeTime(sf::Time & currentLifeTime);

		inline sf::Uint8 lerp(sf::Uint8 a, sf::Uint8 b, float f)
		{
			return static_cast<sf::Uint8>(a + f * (b - a));
		}
	};
}
#endif