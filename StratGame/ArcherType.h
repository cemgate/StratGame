#pragma once
#include"Entity.h"
#include <iostream>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define SLINGER TOSTRING(ARCHER1)
#define BOWMAN TOSTRING(ARCHER2)
#define ARQUEBUSIER TOSTRING(ARCHER3)

class ArcherType : public AnyEntity
{
public:
	ArcherType()
	{
		
	}
	void makeNewType() override
	{

	};
};


class Slinger : public ArcherType
{
public:
	Slinger()
	{
		
	}
	void makeNewType() override
	{
		
	}
};

class Bowman : public Slinger
{
public:
	Bowman()
	{
		
	}
	void makeNewType() override
	{
		

	}
};

class Arquebusier : public Bowman
{
public:
	Arquebusier()
	{
		
	}
	void makeNewType() override
	{
		
	}
	
};


