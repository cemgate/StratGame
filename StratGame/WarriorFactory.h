#include"AbstractCharacterFactory.h"
#include"WarriorType.h"


inline bool operator ==(const int& type2, const EntityType::WarriorEvolution& type1)
{
	return static_cast<int>(type1) == type2;
}

class WarriorFactory : public AbstractCharacterFactory
{
public:

	std::unique_ptr<AnyEntity> createCharacter(int evolution) const override;

};



