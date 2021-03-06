
#ifndef UNTITLED13_FIELD_H
#define UNTITLED13_FIELD_H

#include "Landscape.h"

class Field: public Landscape {

public:

    void print(std::ostream &stream, GameObject &object) const override{

        stream << "[" << object << "]";

    }

    void print(std::ostream &stream) const override{

        stream << "[" << "." << "]";

    }

    int getDamageFactor(WeaponType type) override {
        switch (type){

            case WeaponType::PHYSIC :
            case WeaponType::FIREARMS:
            case WeaponType::FAR:
                return 1;
            case WeaponType::MAGIC:
                return 100;
        }
    }

    int getAbsorptionFactor(ArmorType type) override {
        switch (type){

            case ArmorType::MAGIC:
                return 100;
            case ArmorType::HEAVY:
            case ArmorType::LIGHT:
            case ArmorType::MEDIUM:
                return 1;
        }
    }

};


#endif //UNTITLED13_FIELD_H
