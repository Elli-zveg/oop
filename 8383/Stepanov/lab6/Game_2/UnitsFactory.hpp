//
//  UnitsFactory.hpp
//  Game_2
//
//  Created by Владислав  Степанов on 25.03.2020.
//  Copyright © 2020 Владислав  Степанов. All rights reserved.
//

#ifndef UnitsFactory_hpp
#define UnitsFactory_hpp

#include "Unit.hpp"

class UnitsFactory {

public:
    
    virtual Unit* CreateUnit (char name, bool isProtected);
};

#endif /* UnitsFactory_hpp */
