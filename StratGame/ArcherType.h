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
		std::cout << "zbudowany a type\n";
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
		std::cout << "zbudowany slinger\n";
	}
	void makeNewType() override
	{
		classType = 'X';
	}
};

class Bowman : public Slinger
{
public:
	Bowman()
	{
		std::cout << "zbudowany Bowman\n";
	}
	void makeNewType() override
	{
		std::cout << "siema to ja bowman\n";

	}
	void eszkere()
	{
		std::cout << "kurwa\n";
	}
};

class Arquebusier : public Bowman
{
public:
	Arquebusier()
	{
		std::cout << "zbudowany arkebuzer\n";
	}
	void makeNewType() override
	{
		std::cout << "siema to ja arkebuzer\n";
	}
	void arkebuzer()
	{
		std::cout << "skill arkebuzer";
	}
};


