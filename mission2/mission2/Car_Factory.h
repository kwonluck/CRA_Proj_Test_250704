#pragma once
#include <iostream>
#include "defineEnum.h"
#include "Engine_Factory.h"
#include "Brake_Factory.h"
#include "Steering_Factory.h"
#include "Car_IF.h"

class CarFactory {
public:
    // 타입에 따라 객체 생성
    static std::unique_ptr<Car_IF> createCar(CarType type) {
        if (type == CarType::SEDAN) return std::make_unique<Sedan>();
        if (type == CarType::SUV) return std::make_unique<Suv>();
        if (type == CarType::TRUCK) return std::make_unique<Truck>();
        return nullptr;
    }
};