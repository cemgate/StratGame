#include "VehicleFactory.h"

std::unique_ptr<AnyEntity> VehicleFactory::createCharacter(int evolution) const
{
	EntityType::VehicleEvolution whichEvolution = static_cast<EntityType::VehicleEvolution>(evolution);

	switch (whichEvolution)
	{
	case EntityType::VehicleEvolution::Horse:
		return std::make_unique<Horse>();

	case EntityType::VehicleEvolution::Chariot:
		return std::make_unique<Chariot>();

	case EntityType::VehicleEvolution::Unicorn:
		return std::make_unique<Unicorn>();

	default:
		return nullptr;
	}
}