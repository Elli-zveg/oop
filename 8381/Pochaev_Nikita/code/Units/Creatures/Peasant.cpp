#include "Peasant.h"

Peasant::Peasant()
{
    health = 10;
    armor = 5;
    meleeAttackStrength = 5;
    actionTokens = 1;
    movementRange = PEASANT_MOVEMENT_RANGE;
}

Peasant::Peasant(std::string inputName) : Peasant()
{
    name = std::move(inputName);
}

Peasant* Peasant::clone() const
{
    return new Peasant(*this);
}

bool Peasant::meleeAttack(size_t x, size_t y) const
{
    return false;
}

void Peasant::describeYourself()
{
    std::cout << "Peasant:" << std::endl;
    Unit::describeYourself();
}

void Peasant::train()
{

}

bool Peasant::cowardice()
{
    return false;
}

Peasant::~Peasant()
{

}

std::string Peasant::getType()
{
    return "Cannon fodder";
}
