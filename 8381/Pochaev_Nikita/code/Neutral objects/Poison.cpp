#include "Poison.h"

void Poison::operator+=(const std::shared_ptr<Unit> &unit)
{
    unit->takeDamage(POISON_LOSS);
}
