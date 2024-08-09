#pragma once
#include"Entity.h"
#include <iostream>


class WorkerType : public AnyEntity
{
public:
	WorkerType() : AnyEntity('W', 100, 50, 10, 1, 1, 1, 1)
	{


	}

	virtual void makeAMove() override
	{
	}

	virtual void useMagicSkill() override
	{

	}

	virtual void useAttack()  override
	{

	}

	virtual void travelAroundTheMap() override
	{

	}
};

class Woodman : public WorkerType
{
public:
	Woodman()
	{

	}
	virtual void makeAMove() override
	{
	}

	virtual void useMagicSkill() override
	{

	}

	virtual void useAttack()  override
	{

	}

	virtual void travelAroundTheMap() override
	{

	}
};

class Miner : public Woodman
{
public:
	Miner()
	{

	}
	virtual void makeAMove() override
	{
	}

	virtual void useMagicSkill() override
	{

	}

	virtual void useAttack()  override
	{

	}

	virtual void travelAroundTheMap() override
	{

	}
};

class DiamondMiner : public Miner
{
public:
	DiamondMiner()
	{
		
	}
	virtual void makeAMove() override
	{
	}

	virtual void useMagicSkill() override
	{

	}

	virtual void useAttack()  override
	{

	}

	virtual void travelAroundTheMap() override
	{

	}
};

