#pragma once
#include"AbstractCharacterFactory.h"
#include"SiegeType.h"



inline bool operator ==(const int& type2, const EntityType::SiegeEvolution& type1)
{
	return static_cast<int>(type1) == type2;
}

class SiegeFactory : public AbstractCharacterFactory
{
public:

	std::unique_ptr<AnyEntity> createCharacter(int evolution) const override;

};

