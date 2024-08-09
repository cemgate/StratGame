#pragma once
#include"Entity.h"
#include <iostream>

class SiegeType : public AnyEntity
{
public:
	SiegeType() : AnyEntity('W', 100, 50, 10, 1, 1, 1, 1)
	{
		std::cout << "stworzylem Siege \n";
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

class Catapult : public SiegeType
{
public:
	Catapult()
	{
		std::cout << "stworzylem Catapult \n";
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

class Ram : public Catapult
{
public:
	Ram()
	{
		std::cout << "stworzylem Ram \n";
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

class Grond : public Ram
{
public:
	Grond()
	{
		std::cout << "stworzylem Grond \n";
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

