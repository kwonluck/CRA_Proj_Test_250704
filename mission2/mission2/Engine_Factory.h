#pragma once
#include "Engine_IF.h"

class EngineFactory {
public:
    // Ÿ�Կ� ���� ��ü ����
    static std::unique_ptr<Engine_IF> createEngine(Engine type) {
        if (type == Engine::GM) return std::make_unique<Engine_GM>();
        if (type == Engine::TOYOTA) return std::make_unique<Engine_TOYOTA>();
        if (type == Engine::WIA) return std::make_unique<Engine_WIA>();
        return nullptr;
    }
};