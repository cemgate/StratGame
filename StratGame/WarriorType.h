#pragma once
#include"Entity.h"
#include<iostream>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define BARBARIAN TOSTRING(WARRIOR1)
#define KNIGHT TOSTRING(WARRIOR2)
#define PALADIN TOSTRING(WARRIOR3)

class WarriorType : public AnyEntity
{public:
	void makeNewType() override
	{

	};
};

class Barbarian : public WarriorType
{
public:
	void makeNewType() override
	{

	};

};

class Knight : public Barbarian
{
public:
	void makeNewType() override
	{

	};
};

class Paladin : public Knight
{
public:
	Paladin()
	{
		std::cout << "zrobilem paladyna";
	}
	void makeNewType() override
	{

	};
};

