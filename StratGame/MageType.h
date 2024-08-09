#pragma once
#include "Entity.h"

class MageType : public AnyEntity
{
public:
	MageType()
		: AnyEntity('W', 100, 50, 10, 1, 1, 1, 1) {}
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

class AirElement : public MageType
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

class WaterElement : public AirElement
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

class FireElement : public WaterElement
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