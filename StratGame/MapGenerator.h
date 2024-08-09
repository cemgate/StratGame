#pragma once
#include"Utilities.h"
#include <vector>


constexpr auto MINIMAL_MAP_XSIZE = 30;
constexpr auto MINIMAL_MAP_YSIZE = 150;

constexpr auto RANDOM_EXTRA_XSIZE = 21;
constexpr auto RANDOM_EXTRA_YSIZE = 31;

constexpr auto BAD_GENERATE_COUNTER = 5;

constexpr auto INITIAL_AMOUNT_OF_FORESTS = 50;
constexpr auto RANDOM_EXTRA_FOREST_AMOUNTS = 1;
constexpr auto FOREST_GROWTH_PROPABILITY = 50; 
constexpr auto FOREST_GROWTH_PROPABILITY_DECREASE = 10;

constexpr auto INITIAL_AMOUNT_OF_MOUNTAINS = 15;
constexpr auto RANDOM_EXTRA_MOUNTAIN_AMOUNTS = 10;
constexpr auto INITIAL_CHAIN_LENGTH = 15;
constexpr auto RANDOM_EXTRA_CHAIN_LENGTH = 20;

constexpr auto INITIAL_AMOUNT_OF_LAKES = 30;
constexpr auto RANDOM_EXTRA_LAKES_AMOUNTS = 1;
constexpr auto INITIAL_LAKE_GROWTH = 5;

class MapManager
{
public :

    static std::vector<std::vector<char>> generateRandomMap();
};

