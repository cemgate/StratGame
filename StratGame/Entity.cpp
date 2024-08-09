#include "Entity.h"

char AnyEntity::getClass() const
{
	return stats.classType;
}

int AnyEntity::getMovementSpeed() const
{
	return stats.movementSpeed;
}

int AnyEntity::getAttackRange() const
{
	return stats.attackRange;
}

int AnyEntity::getUniqueID() const
{
	return stats.uniqueID;
}

int AnyEntity::getPosX() const
{
	return stats.posX;
}

int AnyEntity::getPosY() const
{
	return stats.posY;
}

void AnyEntity::setPosition()
{
}

void AnyEntity::takeDamage(int damage)
{
	stats.healthPoints -= damage;
}

void AnyEntity::attackAnotherEntity()
{

}

bool AnyEntity::isAlive() const
{
	return stats.healthPoints > 0;
}

