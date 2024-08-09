#include "MapGenerator.h"
#include "queue"

namespace MapNavigation
{
	using Coordinate = std::pair<int, int>;

	// Directions of movement on the x/y map, each pair represents a specific movement direction
	const std::vector<Coordinate> directions = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };
	const std::vector<Coordinate> pathMoves = { {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	// Turn left by 45 degrees
	int turnLeft(int actualDirection)
	{
		return actualDirection = (actualDirection + 7) % 8;
	}

	// Turn right by 45 degrees
	int turnRight(int actualDirection)
	{
		return actualDirection = (actualDirection + 1) % 8;
	}

	// Check if a position (row, col) is within the map boundaries
	bool isValid(int row, int col, int x, int y, const std::vector<std::vector<char>>& map)
	{
		return row >= 0 && row < x && col >= 0 && col < y && map[row][col] != 'X' and map[row][col] != 'O';
	}

	// Find the shortest path excluding the start and end points
	std::vector<Coordinate> findShortestPath(const std::vector<std::vector<char>>& map, Coordinate start, Coordinate end)
	{
		int xSize = map.size();
		int ySize = map[0].size();

		// Check if start or end are valid
		if (!isValid(start.first, start.second, xSize, ySize, map) ||
			!isValid(end.first, end.second, xSize, ySize, map))
		{
			return {};
		}

		std::vector<std::vector<bool>> visited(xSize, std::vector<bool>(ySize, false));
		std::vector<std::vector<Coordinate>> parent(xSize, std::vector<Coordinate>(ySize, { -1, -1 }));

		std::queue<Coordinate> q;

		// Initialize BFS with the start point
		q.push(start);
		visited[start.first][start.second] = true;

		// Perform BFS
		while (!q.empty())
		{
			Coordinate current = q.front();
			q.pop();

			if (current == end)
			{
				break;
			}

			// Explore all possible directions
			for (const auto& dir : pathMoves)
			{
				int newRow = current.first + dir.first;
				int newCol = current.second + dir.second;

				if (isValid(newRow, newCol, xSize, ySize, map) && !visited[newRow][newCol])
				{
					visited[newRow][newCol] = true;
					parent[newRow][newCol] = current;
					q.push({ newRow, newCol });
				}
			}
		}

		// Reconstruct path from the end to start
		std::vector<Coordinate> path;
		Coordinate step = end;
		while (step != start && step.first != -1)
		{
			path.push_back(step);
			step = parent[step.first][step.second];
		}

		// Reverse the path to get it from start to end
		std::reverse(path.begin(), path.end());

		// Remove the start and end points from the path if they are included
		if (!path.empty() && path.front() == start) path.erase(path.begin());
		if (!path.empty() && path.back() == end) path.pop_back();

		return path;
	}
}

namespace MapCheck
{
	// Check if a position is within the map boundaries
	bool isSafePlace(const std::vector<std::vector<char>>& map, int xPos, int yPos)
	{
		return xPos >= 0 and xPos < map.size() and yPos >= 0 and yPos < map[0].size();
	}

	// Check if a position is free to place an object (' . ' means it's free)
	bool isFreePlace(const std::vector<std::vector<char>>& map, int xPos, int yPos)
	{
		return map[xPos][yPos] == '.';
	}
}

namespace BiomGenarator
{
	// Recursively grows the forest starting from (startX, startY) with a given probability.
	void forestGrowth(std::vector<std::vector<char>>& map, int startX, int startY, int probability)
	{
		// If the probability to grow the forest is less than or equal to 0, stop the function.
		if (probability <= 0)
		{
			return;
		}

		// The forest can grow in any direction.
		for (auto& i : MapNavigation::directions)
		{
			// If the new position is within the map's bounds.
			if (MapCheck::isSafePlace(map, startX + i.first, startY + i.second))
			{
				// Generate a random number that will determine the growth probability.
				int tmpProbability = Utilities::getRandomNumberFromRange(1, 100);

				// If the new position is free for forest growth.
				if (MapCheck::isFreePlace(map, startX + i.first, startY + i.second) and tmpProbability < probability)
				{
					map[startX + i.first][startY + i.second] = 'W'; // Place forest ('W').

					// Recursively grow the forest with decreased probability.
					forestGrowth(map, startX + i.first, startY + i.second, probability - FOREST_GROWTH_PROPABILITY_DECREASE);
				}
			}
		}
	}

	// Generate multiple forests on the map.
	void generateForests(std::vector<std::vector<char>>& map)
	{
		// Generate the number of forests.
		int numberOfForests = INITIAL_AMOUNT_OF_FORESTS + Utilities::getRandomNumberFromRange(1, RANDOM_EXTRA_FOREST_AMOUNTS);

		int xSizeOfMap = map.size() - 1; // X size of the map.
		int ySizeOfMap = map[0].size() - 1; // Y size of the map.

		for (int i = 0; i < numberOfForests; i++)
		{
			// Randomly select a position to start the forest.
			int startX = Utilities::getRandomNumberFromRange(0, xSizeOfMap);
			int startY = Utilities::getRandomNumberFromRange(0, ySizeOfMap);

			// Counter to prevent infinite loops if a bad position is selected repeatedly.
			int badPositionGenerate = 0;

			// Keep generating until a valid position is found or the counter exceeds its limit.
			while (!MapCheck::isFreePlace(map, startX, startY) and badPositionGenerate < BAD_GENERATE_COUNTER)
			{
				startX = Utilities::getRandomNumberFromRange(0, xSizeOfMap);
				startY = Utilities::getRandomNumberFromRange(0, ySizeOfMap);
				badPositionGenerate++;
			}

			if (badPositionGenerate < BAD_GENERATE_COUNTER)
			{
				map[startX][startY] = 'W';
				forestGrowth(map, startX, startY, FOREST_GROWTH_PROPABILITY);
			}
		}
	}

	// Grows a mountain chain starting from (posX, posY) in a given direction and length.
	void mountainsGrowth(std::vector<std::vector<char>>& map, int posX, int posY, int chainLength, int currentDir)
	{
		for (int i = 0; i < chainLength; i++)
		{
			// Randomly determine the direction of mountain chain growth.
			// 1 -> Left
			// 2 -> Straight
			// 3 -> Right
			int tmpProbability = Utilities::getRandomNumberFromRange(1, 3);

			if (tmpProbability == 1 || tmpProbability == 3)
			{
				if (tmpProbability == 1)
				{
					currentDir = MapNavigation::turnLeft(currentDir); // Turn left (decrease by 1, within the range 0-7).
				}
				else if (tmpProbability == 3)
				{
					currentDir = MapNavigation::turnRight(currentDir); // Turn right (increase by 1, within the range 0-7).
				}
			}

			MapNavigation::Coordinate dir = MapNavigation::directions[currentDir];

			// If the new position is within the map's bounds.
			if (MapCheck::isSafePlace(map, posX + dir.first, posY + dir.second))
			{
				// If the new position is free or contains forest ('W'), grow the mountain chain.
				if (MapCheck::isFreePlace(map, posX + dir.first, posY + dir.second) or
					map[posX + dir.first][posY + dir.second] == 'W')
				{
					posX += dir.first;
					posY += dir.second;
					map[posX][posY] = 'X'; // Place mountain ('X').
				}
			}
		}

	}

	// Generate multiple mountain chains on the map.
	void generateMountains(std::vector<std::vector<char>>& map)
	{
		// Generate how many mountain chains we have.
		int numberOfMountainChains = INITIAL_AMOUNT_OF_MOUNTAINS + Utilities::getRandomNumberFromRange(0, RANDOM_EXTRA_MOUNTAIN_AMOUNTS);

		std::vector<int> lengthsOfMountainChains(numberOfMountainChains);

		int xSizeOfMap = map.size() - 1;
		int ySizeOfMap = map[0].size() - 1;

		for (auto& chainLength : lengthsOfMountainChains)
		{
			chainLength = INITIAL_CHAIN_LENGTH + Utilities::getRandomNumberFromRange(0, RANDOM_EXTRA_CHAIN_LENGTH);

			int startX = Utilities::getRandomNumberFromRange(0, xSizeOfMap);  // Start x position of each chain.
			int startY = Utilities::getRandomNumberFromRange(0, ySizeOfMap);  // Start y position of each chain.

			int badPositionGenerate = 0;

			// Keep generating until a valid position is found or the counter exceeds its limit.
			while (!MapCheck::isFreePlace(map, startX, startY) and badPositionGenerate < BAD_GENERATE_COUNTER)
			{
				startX = Utilities::getRandomNumberFromRange(0, xSizeOfMap);
				startY = Utilities::getRandomNumberFromRange(0, ySizeOfMap);
				badPositionGenerate++;
			}

			if (badPositionGenerate < BAD_GENERATE_COUNTER)
			{
				map[startX][startY] = 'X'; // Place the beginning of the mountain chain on the map.

				int currentDir = Utilities::getRandomNumberFromRange(0, 7); // Take the direction of mountain chain growth.

				mountainsGrowth(map, startX, startY, chainLength, currentDir);
			}
		}
	}

	// Grows a lake starting from (posX, posY) in a given direction.
	void lakesGrowth(std::vector<std::vector<char>>& map, int posX, int posY, int currentDir)
	{
		for (int i = 0; i < INITIAL_LAKE_GROWTH; i++)
		{
			//lake can grow in 3 directions something like that, underneath explanation
			// 
			//    ############################################################
			//    #        ...........                                       #
			//    #        .....O.....<- X means our position in this moment #
			//    #        ....OXO....<- O means our new lake                #  
			//    #        ...........                                       #
			//    ############################################################   
			//        
			std::vector<MapNavigation::Coordinate> moves = { MapNavigation::directions[currentDir] ,
															 MapNavigation::directions[MapNavigation::turnLeft(currentDir)] ,
															 MapNavigation::directions[MapNavigation::turnRight(currentDir)] };

			for (auto& i : moves)
			{
				if (MapCheck::isSafePlace(map, posX + i.first, posY + i.second) and
					MapCheck::isFreePlace(map, posX + i.first, posY + i.second))
				{
					map[posX + i.first][posY + i.second] = 'O';
				}
			}

			//get our new direction
			int tmpProbability = Utilities::getRandomNumberFromRange(1, 3);

			if (tmpProbability == 1 || tmpProbability == 3)
			{
				if (tmpProbability == 1)
				{
					currentDir = MapNavigation::turnLeft(currentDir); // Zmniejszenie o 1 z uwzglêdnieniem zakresu 0-7
					posX += moves[1].first;
					posY += moves[1].second;
				}
				else if (tmpProbability == 3)
				{
					currentDir = MapNavigation::turnRight(currentDir); // Zwiêkszenie o 1 z uwzglêdnieniem zakresu 0-7
					posX += moves[2].first;
					posY += moves[2].second;
				}
				else
				{
					posX += moves[0].first;
					posY += moves[0].second;
				}
			}

		}
	}

	// Generate multiple lakes on the map.
	void generateLakes(std::vector<std::vector<char>>& map)
	{
		int numberOfLakes = INITIAL_AMOUNT_OF_LAKES + Utilities::getRandomNumberFromRange(0, RANDOM_EXTRA_LAKES_AMOUNTS);

		int xSizeOfMap = map.size() - 1;
		int ySizeOfMap = map[0].size() - 1;

		for (int i = 0; i < numberOfLakes; i++)
		{
			int startX = Utilities::getRandomNumberFromRange(0, xSizeOfMap);  //started x position of each chain
			int startY = Utilities::getRandomNumberFromRange(0, ySizeOfMap);  //started y position of each chain

			int badPositionGenerate = 0;

			while (!MapCheck::isFreePlace(map, startX, startY) and badPositionGenerate < BAD_GENERATE_COUNTER) //if the start x/y pos is invalid repeat action
			{
				startX = Utilities::getRandomNumberFromRange(0, xSizeOfMap);
				startY = Utilities::getRandomNumberFromRange(0, ySizeOfMap);
				badPositionGenerate++;
			}


			if (badPositionGenerate < BAD_GENERATE_COUNTER)
			{
				map[startX][startY] = 'O'; //place the actual center of lake

				//this double loop underneath is for make initial lake shape like this 
				// ####################
				// #         0        # 
				// #        000       #   <- lake has started shape
				// #         0        #
				// ####################
				for (int j = -1; j <= 1; j += 2)
				{
					if (MapCheck::isSafePlace(map, startX + j, startY) and
						MapCheck::isFreePlace(map, startX + j, startY))
					{
						map[startX + j][startY] = 'O';
					}
					if (MapCheck::isSafePlace(map, 0, startY + j) and
						MapCheck::isFreePlace(map, 0, startY + j))
					{
						map[startX][startY + j] = 'O';
					}

				}

				//get our direction of growth
				int currentDir = Utilities::getRandomNumberFromRange(0, 7);

				lakesGrowth(map, startX, startY, currentDir);
			}
		}
	}

	void generateMines(std::vector<std::vector<char>>& map)
	{

	}

	void generatePlayerBases(std::vector<std::vector<char>>& map)
	{
		int xSize = map.size() - 1;
		int ySize = map[0].size() - 1;


		//first base will be in top left quarter
		MapNavigation::Coordinate firstBase = { Utilities::getRandomNumberFromRange(0, xSize / 2),
											   Utilities::getRandomNumberFromRange(0, ySize / 2) };

		//second base will be in bottom left quarter
		MapNavigation::Coordinate secondBase = { Utilities::getRandomNumberFromRange(xSize / 2 , xSize),
												 Utilities::getRandomNumberFromRange(ySize / 2 , ySize) };

		// Case where both bases end up in the same location, which is unlikely but possible
		if (firstBase.first == secondBase.first)
		{
			secondBase.first += 1;
		}

		map[firstBase.first][firstBase.second] = '1';
		map[secondBase.first][secondBase.second] = '2';

		auto siema = MapNavigation::findShortestPath(map, {firstBase.first,firstBase.second }, {secondBase.first,secondBase.second });

		for (int i = 0; i < siema.size(); i++)
		{
			map[siema[i].first][siema[i].second] = '#';
		}

	}
}

std::vector<std::vector<char>> MapManager::generateRandomMap()
{

	int xSize = MINIMAL_MAP_XSIZE + Utilities::getRandomNumberFromRange(0, RANDOM_EXTRA_XSIZE);
	int ySize = MINIMAL_MAP_YSIZE + Utilities::getRandomNumberFromRange(0, RANDOM_EXTRA_YSIZE);

	std::vector<std::vector<char>> map(xSize, std::vector<char>(ySize, '.'));

	BiomGenarator::generateLakes(map);

	BiomGenarator::generateForests(map);

    BiomGenarator::generateMountains(map);

	BiomGenarator::generatePlayerBases(map);

	return map;
}

