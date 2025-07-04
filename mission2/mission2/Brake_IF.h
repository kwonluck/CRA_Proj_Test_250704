#pragma once
#include <iostream>
#include "defineEnum.h"

class Brake_IF {
public:
    BrakeSystem Brand;

    virtual ~Brake_IF() {}
};


class Brake_MANDO : public Brake_IF {
public:
    Brake_MANDO() {
        Brand = BrakeSystem::MANDO;
    }
};

class Brake_CONTINENTAL : public Brake_IF {
public:
    Brake_CONTINENTAL() {
        Brand = BrakeSystem::CONTINENTAL;
    }
};

class Brake_BOSCH_B : public Brake_IF {
public:
    Brake_BOSCH_B() {
        Brand = BrakeSystem::BOSCH_B;
    }
};