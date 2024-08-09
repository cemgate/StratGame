#pragma once
#include"Entity.h"

class VehicleType : public AnyEntity 
{
public:
	VehicleType() : AnyEntity('W', 100, 50, 10, 1, 1, 1, 1) {}
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

class Horse : public VehicleType
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

class Chariot : public Horse
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

class Unicorn : public Chariot
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

