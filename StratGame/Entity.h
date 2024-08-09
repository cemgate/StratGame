#pragma once
#include <map>
#include<memory>

namespace EntityType
{
	enum class ArcherEvolution
	{
		Slinger = 1,
		Bowman = 2,
		Arquebusier = 3
	};

	enum class MageEvolution
	{
		AirElement = 1,
		WaterElement = 2,
		FireElement = 3
	};

	enum class SiegeEvolution
	{
		Catapult = 1,
		Ram = 2,
		Grond = 3
	};

	enum class VehicleEvolution
	{
		Horse = 1,
		Chariot = 2,
		Unicorn = 3
	};

	enum class WarriorEvolution
	{
		Barbarian = 1,
		Knight = 2,
		Paladin = 3
	};

	enum class WorkerEvolution
	{
		Woodman = 1,
		Miner = 2,
		DiamondMiner = 3
	};

}

class AnyEntity
{
public:

	virtual ~AnyEntity() {};

	virtual void makeAMove() = 0;

protected:

	char getClass() const;

	int getMovementSpeed() const;

	int getAttackRange() const;

	int getUniqueID() const;

	int getPosX() const;

	int getPosY() const;

	void setPosition();

	void takeDamage(int damage);

	void attackAnotherEntity();

	bool isAlive() const;

	virtual void useMagicSkill() = 0;

	virtual void useAttack() = 0;

	virtual void travelAroundTheMap() = 0;


	struct unitStats
	{
		char classType;
		int healthPoints;
		int manaPoints;
		int movementSpeed;
		int attackRange;
		int posX;
		int posY;
		int uniqueID;
	};

	unitStats stats;

	AnyEntity(char s_classType, int s_healthPoints, int s_manaPoints, int s_movementSpeed, int s_attackRange, int s_posX, int s_posY, int s_uniqueID)
		: stats{s_classType,  s_healthPoints,  s_manaPoints,  s_movementSpeed,  s_attackRange,  s_posX, s_posY, s_uniqueID}
	{}
};


//static constexpr int m_damage_table[7][8] = {
//	// K   S   A   P   C   R   W   B
//	{ 35, 35, 35, 35, 35, 50, 35, 35 }, // K
//	{ 30, 30, 30, 20, 20, 30, 30, 30 }, // S
//	{ 15, 15, 15, 15, 10, 10, 15, 15 }, // A
//	{ 35, 15, 15, 15, 10, 10, 15, 15 }, // P
//	{ 40, 40, 40, 40 ,40, 40, 40, 50 }, // C
//	{ 10, 10, 10, 10, 10, 10, 10, 50 }, // R
//	{ 5,  5,  5,  5,  5,  5,  5,  1  }  // W
//};
//
//const std::map<char, unsigned int> m_unit_index{
//		{ 'K', 0 },
//		{ 'S', 1 },
//		{ 'A', 2 },
//		{ 'P', 3 },
//		{ 'C', 4 },
//		{ 'R', 5 },
//		{ 'W', 6 },
//		{ 'B', 7 }
//};