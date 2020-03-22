#ifndef OOP_GAMEBASE_H
#define OOP_GAMEBASE_H

#include <cstddef>

#include "GameBase.h"
#include "../Units/ObjectFactory.h"
#include "../Information headers/constPar.h"
#include "../Units/CompositeUnit.h"
#include "UnitStorekeeper.h"

typedef cds::ObjectFactory<Unit, std::string> UnitFabric;

class GameBase : public UnitObserver, public std::enable_shared_from_this<GameBase>
{
protected:
    const size_t health{BASE_HEALTH};
    UnitFabric unitFabric;
    std::unique_ptr<UnitStorekeeper> unitCount{};
    std::vector<std::shared_ptr<CompositeUnit>> army{};

public:
    virtual ~GameBase() = default;
    void initUnitCount();
    template<class T>
    void registerNewUnitType(const std::string &typeID)
    {
        unitFabric.add<T>(typeID);
    }
    virtual void describeYourself();
    std::shared_ptr<Unit> getUnit(const std::string &typeID);
    std::shared_ptr<CompositeUnit> createLegion();
    std::shared_ptr<CompositeUnit> createSquad(const std::string &type, size_t quantity);
    void updateAfterDeath(std::shared_ptr<Unit> corpse, size_t x, size_t y) override;
};

#endif //OOP_GAMEBASE_H
