#pragma once
#include"Entity.h"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define HORSE TOSTRING(VEHICLE1)
#define CHARIOT TOSTRING(VEHICLE2)
#define UNICORN TOSTRING(VEHICLE3)

class VehicleType : public AnyEntity 
{
public:
	void makeNewType() override
	{

	};
};

class Horse : public VehicleType
{
public:
	void makeNewType() override
	{

	};
};

class Chariot : public Horse
{
public:
	void makeNewType() override
	{

	};
};

class Unicorn : public Chariot
{
public:
	void makeNewType() override
	{

	};
};

