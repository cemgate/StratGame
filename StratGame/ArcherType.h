#pragma once
#include"Entity.h"
#include <iostream>

class ArcherType : public AnyEntity
{
public:
	ArcherType()
		: AnyEntity('W', 100, 50, 10, 1, 1, 1, 1)
	{

	}
private:
	void makeAMove() override
	{
		useMagicSkill();
	}
	virtual void useMagicSkill() = 0;
	virtual void useAttack() = 0;
	virtual void travelAroundTheMap() = 0;

};


class Slinger : public ArcherType
{
public:
	Slinger()
	{

	}
	void travelAroundTheMap() override
	{

	}
	void useAttack() override
	{

	}
	void useMagicSkill() override
	{
		useSlingerSkill();
	}

	void useSlingerSkill()
	{
		std::cout << "Slinger skill\n";
	}
};

class Bowman : public Slinger
{
public:
	Bowman()
	{
		
	}
	void travelAroundTheMap() override
	{

	}
	void useAttack() override
	{

	}
	void useMagicSkill() override
	{
		useBowmanSkill();
	}
	void useBowmanSkill()
	{
		std::cout << "Bowman skill\n";
	}
};

class Arquebusier : public Bowman
{
public:
	Arquebusier()
	{

	}
	void travelAroundTheMap() override
	{

	}
	void useAttack() override
	{

	}
	void useMagicSkill() override
	{
		useArquebusierSkill();
	}

	void useArquebusierSkill()
	{
		std::cout << "arkebuzer skill\n";
	}

};


