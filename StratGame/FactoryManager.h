#pragma once
#include"Entity.h"

#include"AbstractCharacterFactory.h"
#include"ArcherFactory.h"
#include"MageFactory.h"
#include"SiegeFactory.h"
#include"VehicleFactory.h"
#include"WarriorFactory.h"
#include"WorkerFactory.h"

#include<memory>
#include<map>


class FactoryManager 
{
public:
    FactoryManager() 
    {
        // Inicjalizacja fabryk
        factories["Archer"] = std::make_unique<ArcherFactory>();
        factories["Mage"] = std::make_unique<MageFactory>();
        factories["Siege"] = std::make_unique<SiegeFactory>();
        factories["Vehicle"] = std::make_unique<VehicleFactory>();
        factories["Warrior"] = std::make_unique<WarriorFactory>();
        factories["Worker"] = std::make_unique<WorkerFactory>();
    }

    std::unique_ptr<AnyEntity> createEntity(const std::string& typeOfUnit, int evolutionOfUnit) 
    {
        auto whichFactory = factories.find(typeOfUnit);
        if (whichFactory != factories.end()) 
        {
            return whichFactory->second->createCharacter(evolutionOfUnit);
        }
        else 
        {
            return nullptr;
        }
    }

private:
    std::map<std::string, std::unique_ptr<AbstractCharacterFactory>> factories;
};


