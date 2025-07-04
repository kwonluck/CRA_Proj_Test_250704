#pragma once
#include <iostream>
#include "defineEnum.h"

class Engine_IF {
public:
    Engine Brand;
    virtual ~Engine_IF() {}
};


class Engine_GM : public Engine_IF {
public:
    Engine_GM() {
        Brand = Engine::GM;
    }
};

class Engine_TOYOTA : public Engine_IF {
public:
    Engine_TOYOTA() {
        Brand = Engine::TOYOTA;
    }
};

class Engine_WIA : public Engine_IF {
public:
    Engine_WIA() {
        Brand = Engine::WIA;
    }
};