#pragma once
#include "AbstractCharacterFactory.h"
#include "ArcherType.h"




inline bool operator ==( const int& type2, const EntityType::ArcherEvolution& type1 )
{
	return static_cast<int>(type1) == type2;
}

class ArcherFactory : public AbstractCharacterFactory
{
public:

	std::unique_ptr<AnyEntity> createCharacter(int evolution) const override;
	
};

