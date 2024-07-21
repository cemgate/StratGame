#include "MageFactory.h"

std::unique_ptr<AnyEntity> MageFactory::createCharacter(int evolution) const
{
	EntityType::MageEvolution whichEvolution = static_cast<EntityType::MageEvolution>(evolution);

	switch (whichEvolution)
	{
	case EntityType::MageEvolution::AirElement:
		return std::make_unique<AirElement>();

	case EntityType::MageEvolution::WaterElement:
		return std::make_unique<WaterElement>();

	case EntityType::MageEvolution::FireElement:
		return std::make_unique<FireElement>();

	default:
		return nullptr;
	}
}