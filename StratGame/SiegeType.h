#pragma once
#include"Entity.h"
#include <iostream>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define CATAPULT TOSTRING(SIEGE1)
#define RAM TOSTRING(SIEGE2)
#define GROND TOSTRING(SIEGE3)

class SiegeType : public AnyEntity
{
public:
	SiegeType()
	{
		std::cout << "stworzylem Siege \n";
	}
	void makeNewType() override
	{

	};
};

class Catapult : public SiegeType
{
public:
	Catapult()
	{
		std::cout << "stworzylem Catapult \n";
	}
	void makeNewType() override
	{

	};
};

class Ram : public Catapult
{
public:
	Ram()
	{
		std::cout << "stworzylem Ram \n";
	}
	void makeNewType() override
	{

	};

};

class Grond : public Ram
{
public:
	Grond()
	{
		std::cout << "stworzylem Grond \n";
	}
	void makeNewType() override
	{

	};
};

