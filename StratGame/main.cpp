#include <vector>
#include "Entity.h"
#include "FactoryManager.h"
#include "GameManager.h"
#include "MapGenerator.h"



int main(void)
{
	/*FactoryManager tmp;
	std::shared_ptr<AnyEntity> mybowman = tmp.createEntity('A', 3);

	mybowman->makeAMove();*/

	std::vector<std::vector<char>> siema = MapManager::generateRandomMap();

    Utilities::printColoredMap(siema);
}     