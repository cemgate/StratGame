#include"AbstractCharacterFactory.h"
#include"WorkerType.h"



inline bool operator ==(const int& type2, const EntityType::WorkerEvolution& type1)
{
	return static_cast<int>(type1) == type2;
}

class WorkerFactory : public AbstractCharacterFactory
{
public:

	std::unique_ptr<AnyEntity> createCharacter(int evolution) const override;

};



