#pragma once
#include"Entity.h"
#include <iostream>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define WOODMAN TOSTRING(WORKER1)
#define MINER TOSTRING(WORKER2)
#define DIAMONDMINER TOSTRING(WORKER3)


class WorkerType : public AnyEntity
{
public:
	WorkerType()
	{
		
	}
	void makeNewType() override
	{

	};
};

class Woodman : public WorkerType
{
public:
	Woodman()
	{
		
	}
	void makeNewType() override 
	{

	};
};

class Miner : public Woodman
{
public:
	Miner()
	{
		
	}
	void makeNewType() override 
	{

	};
};

class DiamondMiner : public Miner
{
public:
	DiamondMiner()
	{
		std::cout << "zrobilem diamond";
	}
	void makeNewType() override final {

	};
};

