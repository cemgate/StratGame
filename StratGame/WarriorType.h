#pragma once
#include"Entity.h"
#include<iostream>

class WarriorType : public AnyEntity
{public:
	WarriorType() : AnyEntity('W', 100, 50, 10, 1, 1, 1, 1) {}
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

class Barbarian : public WarriorType
{
public:
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

class Knight : public Barbarian
{
public:
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

class Paladin : public Knight
{
public:
	Paladin()
	{
		std::cout << "zrobilem paladyna";
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

