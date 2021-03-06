#ifndef mediumarmorfactory_hpp
#define mediumarmorfactory_hpp

#include "armorfactory.hpp"

#include <stdio.h>

class MediumArmorFactory : public ArmorFactory
{
public:

    virtual std::shared_ptr<Armor> createArmor() const override;
};

#endif /* mediumarmorfactory_hpp */
