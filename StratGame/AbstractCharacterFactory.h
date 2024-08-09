#pragma once
#include "Entity.h"
#include <memory>
#include <string>


class AbstractCharacterFactory
{
public:
	virtual ~AbstractCharacterFactory() = default;

	virtual std::unique_ptr<AnyEntity> createCharacter(int evolution) const = 0;
};

