#pragma once
#include "Brake_IF.h"

class BrakeFactory {
public:
    // Ÿ�Կ� ���� ��ü ����
    static std::unique_ptr<Brake_IF> createBrake(BrakeSystem type) {
        if (type == BrakeSystem::MANDO) return std::make_unique<Brake_MANDO>();
        if (type == BrakeSystem::CONTINENTAL) return std::make_unique<Brake_CONTINENTAL>();
        if (type == BrakeSystem::BOSCH_B) return std::make_unique<Brake_BOSCH_B>();
        return nullptr;
    }
};