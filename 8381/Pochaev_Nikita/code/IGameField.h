#ifndef OOP_IGAMEFIELD_H
#define OOP_IGAMEFIELD_H

#include <utility>

#include "Information headers/constPar.h"
#include "Auxiliary functionality/Array2D.h"
#include "Auxiliary functionality/GameFieldIterator.h"
#include "Units/ObjectFactory.h"
#include "Cell.h"

class IGameField
{
public:
    [[nodiscard]] virtual size_t getWidth() const = 0;
    [[nodiscard]] virtual size_t getHeight() const = 0;

    virtual void addUnit(const std::shared_ptr<Unit> &unit, size_t x, size_t y) = 0;
    virtual void addBase(const std::shared_ptr<GameBase> &base, size_t x, size_t y) = 0;
    virtual void delUnit(size_t x, size_t y) = 0;
    virtual bool isCellFreeForUnit(size_t x, size_t y) = 0;
    virtual bool isCellFreeForBase(size_t x, size_t y) = 0;
    virtual void informationAboutCell(size_t x, size_t y) = 0;

    virtual void moveUnit(std::shared_ptr<Unit> &sender, size_t x, size_t y) = 0;
    virtual void meleeAttackUnit(std::shared_ptr<Unit> &sender, size_t x, size_t y) = 0;

    virtual void getTotalInformation() = 0;
};


#endif //OOP_IGAMEFIELD_H
