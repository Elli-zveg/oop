#include "attackmediator.h"
#include "unit.h"
#include "playingfield.h"
AttackMediator::AttackMediator(PlayingField *f):field(f)
{}

void AttackMediator::addUnit(Unit *u)
{
    units.push_back(u);
    u->setAttackMediator(this);
}

void AttackMediator::deleteUnit(Unit *u)
{
    for(std::vector<Unit*>::iterator iter = units.begin(); iter != units.end(); iter++){
        if(*iter == u){
            units.erase(iter);
            return;
        }
    }
}

void AttackMediator::attack(Unit *attaker, int x, int y)
{
    bool attakerExist{};
    unsigned recivePosX{};
    unsigned recivePosY{};
    for(unsigned i = 0; i<field->getWidth(); i++){
        for(unsigned j = 0; j<field->getHeight(); j++){
            if(field->getCell(i, j)->getUnit() == attaker){
                attakerExist = true;
                recivePosX = i;
                recivePosY = j;
            }
        }
    }
    if(!attakerExist){
        throw std::invalid_argument("there is not such attack unit");
    }
    Unit* reciver = field->getCell(recivePosX+static_cast<unsigned>(x), recivePosY+static_cast<unsigned>(y))->getUnit();
    if(!reciver){
        throw std::invalid_argument("there is no unit on position "+to_string(x)+", "+to_string(y));
    }
    for(Unit* u : units){
        if(u == reciver){
            if(u->getBaseNumber() == attaker->getBaseNumber()){
                throw std::invalid_argument("units from one base");
            }
            if(!u->recieveAttack(attaker)){
                field->deleteUnit(recivePosX+static_cast<unsigned>(x), recivePosY+static_cast<unsigned>(y));
            }
            return;
        }
    }
}

std::vector<Unit *> AttackMediator::getUnits() const
{
    return units;
}
