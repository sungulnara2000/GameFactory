#ifndef ABSTRACT_FACTORY_UNITS_H
#define ABSTRACT_FACTORY_UNITS_H

#include <string>

struct Cavalry {
    std::string name = "Cavalry";
};

struct Infantry {
    std::string name = "Infantry";
};

struct Archer {
    std::string name = "Archer";
};

using GameUnits = MakeTypeList<Infantry, Archer, Cavalry>::Result;

#endif //ABSTRACT_FACTORY_UNITS_H
