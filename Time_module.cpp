#include "Time_module.hpp"
using namespace sf;

sf::Color RaghallaighEngine::Time_module::SetColorOverLifeTime(sf::Time & currentLifeTime)
{
	ratio = currentLifeTime.asSeconds() / lifetime.asSeconds();

	r = lerp(initialColor.r, finalColor.r, ratio);
	g = lerp(initialColor.g, finalColor.g, ratio);
	b = lerp(initialColor.b, finalColor.b, ratio);

	if (alphaOverLifeTime == AlphaOverLifeTime::decreases)
	{
		ratio = currentLifeTime.asSeconds() / lifetime.asSeconds();
		a = static_cast<sf::Uint8>(ratio * 255);
	}
	else if (alphaOverLifeTime == AlphaOverLifeTime::increase)
	{
		ratio = 1 - (currentLifeTime.asSeconds() / lifetime.asSeconds());
		a = static_cast<sf::Uint8>((1 - ratio) * 255);
	}

	return Color(r, g, b, a);
}