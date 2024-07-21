
#include"AbstractCharacterFactory.h"
#include"VehicleType.h"



inline bool operator ==(const int& type2, const EntityType::VehicleEvolution& type1)
{
	return static_cast<int>(type1) == type2;
}

class VehicleFactory : public AbstractCharacterFactory
{
public:

	std::unique_ptr<AnyEntity> createCharacter(int evolution) const override;

};


