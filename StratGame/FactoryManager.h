#pragma once
#include"ArcherFactory.h"
#include"MageFactory.h"
#include"SiegeFactory.h"
#include"VehicleFactory.h"
#include"WarriorFactory.h"
#include"WorkerFactory.h"
#include<map>


class FactoryManager
{
public:
	FactoryManager()
	{
		// Inicjalizacja fabryk
		factories['A'] = std::make_unique<ArcherFactory>();
		factories['M'] = std::make_unique<MageFactory>();
		factories['S'] = std::make_unique<SiegeFactory>();
		factories['V'] = std::make_unique<VehicleFactory>();
		factories['W'] = std::make_unique<WarriorFactory>();
		factories['X'] = std::make_unique<WorkerFactory>();
	}



	std::unique_ptr<AnyEntity> createEntity(const char typeOfUnit, const int evolution)
	{
		auto whichFactory = factories.find(typeOfUnit);

		if (whichFactory != factories.end())
		{
			return whichFactory->second->createCharacter(evolution);
		}
		else
		{
			return nullptr;
		}
	}
	
private:
	std::map<char, std::unique_ptr<AbstractCharacterFactory>> factories;
};


