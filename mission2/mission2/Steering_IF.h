#pragma once
#include <iostream>
#include "defineEnum.h"

class Steering_IF {
public:
    SteeringSystem Brand;
    virtual ~Steering_IF() {}
};


class Steering_BOSCH_B : public Steering_IF {
public:
    Steering_BOSCH_B() {
        Brand = SteeringSystem::BOSCH_S;
    }
};

class Steering_MOBIS : public Steering_IF {
public:
    Steering_MOBIS() {
        Brand = SteeringSystem::MOBIS;
    }
};