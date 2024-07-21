#pragma once
#include"AbstractCharacterFactory.h"
#include"MageType.h"




inline bool operator ==(const int& type2, const EntityType::MageEvolution& type1)
{
	return static_cast<int>(type1) == type2;
}

class MageFactory : public AbstractCharacterFactory
{
public:

	std::unique_ptr<AnyEntity> createCharacter(int evolution) const override;

};

