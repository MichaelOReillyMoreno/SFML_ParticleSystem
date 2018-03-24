#include "Particle.hpp"

void RaghallaighEngine::Particle::Update(sf::Time & elapsed)
{
	currentLifeTime -= elapsed;

	if (currentLifeTime <= sf::Time::Zero) Reset();

	vertex.position += velocity * elapsed.asSeconds();
	vertex.color = time_module.SetColorOverLifeTime(currentLifeTime);
}

void RaghallaighEngine::Particle::Reset()
{
	vertex.position = shapeEmission_module.GetRandomPointInArea();

	angle = angleEmission_module.GetAngleEmission(shapeEmission_module.GetPostion(), vertex.position);

	velocity_module.Reset(velocity, angle);

	currentLifeTime = time_module.GetLifeTime();
}