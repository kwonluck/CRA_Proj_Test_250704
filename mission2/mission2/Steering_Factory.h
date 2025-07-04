#pragma once
#include "Steering_IF.h"

class SteeringFactory {
public:
    // Ÿ�Կ� ���� ��ü ����
    static std::unique_ptr<Steering_IF> createSteering(SteeringSystem type) {
        if (type == SteeringSystem::BOSCH_S) return std::make_unique<Steering_BOSCH_B>();
        if (type == SteeringSystem::MOBIS) return std::make_unique<Steering_MOBIS>();
        return nullptr;
    }
};