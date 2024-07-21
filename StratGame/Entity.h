#pragma once
#include <map>
#include<memory>

using USI = unsigned short int;

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

	virtual void makeNewType() = 0;

	char getClass() const
	{
		return classType;
	}

	USI getMovementSpeed() const
	{
		return movementSpeed;
	}

	USI getAttackRange() const
	{
		return attackRange;
	}

	USI getBuildTime() const
	{
		return buildTime;
	}

	USI getPurchasePrice() const
	{
		return purchasePrice;
	}

	USI getUniqueID() const
	{
		return uniqueID;
	}

	USI getPosX() const
	{
		return posX;
	}

	USI getPosY() const
	{
		return posY;
	}

protected:

	char classType;
	USI health;
	USI movementSpeed;
	USI attackRange;
	USI buildTime;
	USI purchasePrice;
	USI uniqueID;
	USI posX;
	USI posY;
};


class Entity
{
	std::unique_ptr<AnyEntity> unit;

public:

	char getClass()
	{
		return unit->getClass();
	};

	/**
	 * @brief Get the current health of the unit.
	 * @return Current health of the unit.
	 */
	int getHealth();

	/**
	 * @brief Get the movement speed of the unit.
	 * @return Movement speed of the unit.
	 */
	int getMovementSpeed();

	/**
	 * @brief Get the attack range of the unit.
	 * @return Attack range of the unit.
	 */
	int getAttackRange();

	/**
	 * @brief Get the build time of the unit.
	 * @return Build time of the unit.
	 */
	int getBuildTime();

	/**
	 * @brief Get the purchase price of the unit.
	 * @return Purchase price of the unit.
	 */
	int getBuyPrice();

	/**
	 * @brief Get the unique ID of the unit.
	 * @return Unique ID of the unit.
	 */
	int getEntityUniqueID();

	/**
	 * @brief Get the X position of the unit.
	 * @return X position of the unit.
	 */
	int getPosX();

	/**
	 * @brief Get the Y position of the unit.
	 * @return Y position of the unit.
	 */
	int getPosY();

	/**
	 * @brief Set the health of the unit to the given value.
	 * @param health New health value for the unit.
	 */
	void setHealth(int health);

	/**
	 * @brief Set the position of the unit to the given coordinates.
	 * @param posX X coordinate of the unit's position.
	 * @param posY Y coordinate of the unit's position.
	 */
	void setPosition(int posX, int posY);

	/**
	 * @brief Set the unique ID of the unit.
	 * @param ID Unique ID to set for the unit.
	 */
	void setEntityUniqueID(int ID);

	/**
	 * @brief Attack the specified target.
	 * @param target Target of the attack.
	 */
	void attack(Entity* target);

	/**
	 * @brief Receive the given amount of damage.
	 * @param damage Amount of damage to receive.
	 */
	void takeDamage(int damage);

	/**
	 * @brief Check if the unit is still alive.
	 * @return true if the unit is alive; false if not.
	 */
	bool isAlive();

	/**
	 * @brief   destructor.
	 */
	~Entity() {};

protected:
	/**
	 * @brief Damage table array between different unit classes.
	 */
	static constexpr int m_damage_table[7][8] = {
		// K   S   A   P   C   R   W   B
		{ 35, 35, 35, 35, 35, 50, 35, 35 }, // K
		{ 30, 30, 30, 20, 20, 30, 30, 30 }, // S
		{ 15, 15, 15, 15, 10, 10, 15, 15 }, // A
		{ 35, 15, 15, 15, 10, 10, 15, 15 }, // P
		{ 40, 40, 40, 40 ,40, 40, 40, 50 }, // C
		{ 10, 10, 10, 10, 10, 10, 10, 50 }, // R
		{ 5,  5,  5,  5,  5,  5,  5,  1  }  // W
	};

	/**
	 * @brief Map of unit indexes by their types.
	 */
	const std::map<char, unsigned int> m_unit_index{
		{ 'K', 0 },
		{ 'S', 1 },
		{ 'A', 2 },
		{ 'P', 3 },
		{ 'C', 4 },
		{ 'R', 5 },
		{ 'W', 6 },
		{ 'B', 7 }
	};
};

