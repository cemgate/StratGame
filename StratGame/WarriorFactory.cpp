#include "WarriorFactory.h"

std::unique_ptr<AnyEntity> WarriorFactory::createCharacter(int evolution) const
{
	EntityType::WarriorEvolution whichEvolution = static_cast<EntityType::WarriorEvolution>(evolution);

	switch (whichEvolution)
	{
	case EntityType::WarriorEvolution::Barbarian:
		return std::make_unique<Barbarian>();

	case EntityType::WarriorEvolution::Knight:
		return std::make_unique<Knight>();

	case EntityType::WarriorEvolution::Paladin:
		return std::make_unique<Paladin>();

	default:
		return nullptr;
	}
}