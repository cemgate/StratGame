#pragma once
#include "Entity.h"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define AIRELEMENT TOSTRING(MAGE1)
#define WATERELEMENT TOSTRING(MAGE2)
#define FIRELEMENT TOSTRING(MAGE3)

class MageType : public AnyEntity
{
public:
	void makeNewType() override
	{

	};
};

class AirElement : public MageType
{
public:
	void makeNewType() override
	{

	};
};

class WaterElement : public AirElement
{
public:
	void makeNewType() override
	{

	};
};

class FireElement : public WaterElement
{
public:
	void makeNewType() override
	{

	};
};