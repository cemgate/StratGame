#include <vector>
#include "Entity.h"
#include "FactoryManager.h"
#include "GameManager.h"
#include "MapGenerator.h"
#include "Logger.hpp"



int main(void)
{
	/*FactoryManager tmp;
	std::shared_ptr<AnyEntity> mybowman = tmp.createEntity('A', 3);

	mybowman->makeAMove();*/

	std::vector<std::vector<char>> siema = MapManager::generateRandomMap();

	log.Info() << LOG_FUNC() << " Starting machine git gut";
	
    Utilities::printColoredMap(siema);
}     