#pragma once
#include"Entity.h"
#include"BaseOfPlayer.h"

#include<vector>

class Player
{ 
private:
	BaseOfPlayer base;
	std::vector<std::shared_ptr<AnyEntity>> entities;
};

