#include "ArcherFactory.h"


std::unique_ptr<AnyEntity> ArcherFactory::createCharacter(int evolution) const 
{
	EntityType::ArcherEvolution whichEvolution = static_cast<EntityType::ArcherEvolution>(evolution);
	
	switch (whichEvolution)
	{
	case EntityType::ArcherEvolution::Slinger:
		return std::make_unique<Slinger>();

	case EntityType::ArcherEvolution::Bowman:
		return std::make_unique<Bowman>();

	case EntityType::ArcherEvolution::Arquebusier:
		return std::make_unique<Arquebusier>();

	default:
		return nullptr;
	}
}
	