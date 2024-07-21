#include "WorkerFactory.h"

std::unique_ptr<AnyEntity> WorkerFactory::createCharacter(int evolution) const
{
	EntityType::WorkerEvolution whichEvolution = static_cast<EntityType::WorkerEvolution>(evolution);
	
	switch (whichEvolution)
	{
	case EntityType::WorkerEvolution::Woodman:
		return std::make_unique<Woodman>();

	case EntityType::WorkerEvolution::Miner:
		return std::make_unique<Miner>();

	case EntityType::WorkerEvolution::DiamondMiner:
		return std::make_unique<DiamondMiner>();

	default:
		return nullptr;
	}
}