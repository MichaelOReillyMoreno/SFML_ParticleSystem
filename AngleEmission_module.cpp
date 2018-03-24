#include "AngleEmission_module.hpp"

unsigned int RaghallaighEngine::AngleEmission_module::GetAngleEmission(sf::Vector2f & position, sf::Vector2f & origin)
{
		switch (directionEmission) 
		{
		case DirectionEmission::angle:

			return angle;
			break;

		case DirectionEmission::allDirections:
		//TEST CODE----------in development

			return static_cast<unsigned int>(atan2(origin.y - position.y, origin.x - position.x) * 180 / 3.1416f);
			break;

		case DirectionEmission::rotation:

			return static_cast<unsigned int>(atan2(origin.y - position.y, origin.x - position.x) * 180 / 3.1416f);
			break;

		default:

			return rand() % (360 - 1);
			break;
		}
	}
