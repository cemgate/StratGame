#include "SiegeFactory.h"

std::unique_ptr<AnyEntity> SiegeFactory::createCharacter(int evolution) const
{
	EntityType::SiegeEvolution whichEvolution = static_cast<EntityType::SiegeEvolution>(evolution);

	switch (whichEvolution)
	{
	case EntityType::SiegeEvolution::Catapult:
		return std::make_unique<Catapult>();

	case EntityType::SiegeEvolution::Ram:
		return std::make_unique<Ram>();

	case EntityType::SiegeEvolution::Grond:
		return std::make_unique<Grond>();

	default:
		return nullptr;
	}
}