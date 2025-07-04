#pragma once
#include <iostream>
#include "defineEnum.h"

#define CLEAR_SCREEN "\033[H\033[2J"


class Menu {
public:
    int delayTime = 800; // 기본 지연 시간

    Menu() {
        printf(CLEAR_SCREEN);
    }
    virtual void show_Menu() = 0;
    virtual void show_YourSelect(const int& answer) = 0;
    virtual ~Menu() {}

    void show_InputPrompt() {
        printf("===============================\n");
        printf("INPUT > ");
    }
};

class Select_CarType : public Menu {
public:
    void show_Menu() override {
        printf("        ______________\n");
        printf("       /|            | \n");
        printf("  ____/_|_____________|____\n");
        printf(" |                      O  |\n");
        printf(" '-(@)----------------(@)--'\n");
        printf("===============================\n");
        printf("어떤 차량 타입을 선택할까요?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    void show_YourSelect(const int& answer) {
        if (answer == CarType::SEDAN)
            printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
        if (answer == CarType::SUV)
            printf("차량 타입으로 SUV을 선택하셨습니다.\n");
        if (answer == CarType::TRUCK)
            printf("차량 타입으로 Truck을 선택하셨습니다.\n");
        delay(delayTime);
    }
};

class Select_EngineType : public Menu {
public:
    void show_Menu() override {
        printf("어떤 엔진을 탑재할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. 고장난 엔진\n");
    }
    void show_YourSelect(const int& answer) {
        if (answer == Engine::GM)
            printf("GM 엔진을 선택하셨습니다.\n");
        if (answer == Engine::TOYOTA)
            printf("TOYOTA 엔진을 선택하셨습니다.\n");
        if (answer == Engine::WIA)
            printf("WIA 엔진을 선택하셨습니다.\n");
        delay(delayTime);
    }
};

class Select_BrakeType : public Menu {
public:
    void show_Menu() override {
        printf("어떤 제동장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    void show_YourSelect(const int& answer) {
        if (answer == brakeSystem::MANDO)
            printf("MANDO 제동장치를 선택하셨습니다.\n");
        if (answer == brakeSystem::CONTINENTAL)
            printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
        if (answer == brakeSystem::BOSCH_B)
            printf("BOSCH 제동장치를 선택하셨습니다.\n");
        delay(delayTime);
    }
};

class Select_SteeringType : public Menu {
public:
    void show_Menu() override {
        printf("어떤 조향장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    void show_YourSelect(const int& answer) {
        if (answer == SteeringSystem::BOSCH_S)
            printf("BOSCH 조향장치를 선택하셨습니다.\n");
        if (answer == SteeringSystem::MOBIS)
            printf("MOBIS 조향장치를 선택하셨습니다.\n");
        delay(delayTime);
    }
};

class Select_RunTestType : public Menu {
public:
    int delayTime = 1500; // RunTestType 메뉴는 지연 시간을 늘림
    void show_Menu() override {
        printf("멋진 차량이 완성되었습니다.\n");
        printf("어떤 동작을 할까요?\n");
        printf("0. 처음 화면으로 돌아가기\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    void show_YourSelect(const int& answer) {
        if (answer == RunTest::Test)
        {
            printf("Test...\n");
            delay(delayTime);
        }
    }
};


class DisplayMenu_Factory {
    public:
        // 타입에 따라 객체 생성
        static std::unique_ptr<Menu> createMenu(QuestionType type) {
            if (type == QuestionType::CarType_Q) return std::make_unique<Select_CarType>();
            if (type == QuestionType::Engine_Q) return std::make_unique<Select_EngineType>();
            if (type == QuestionType::brakeSystem_Q) return std::make_unique<Select_BrakeType>();
            if (type == QuestionType::SteeringSystem_Q) return std::make_unique<Select_SteeringType>();
            if (type == QuestionType::Run_Test_Q) return std::make_unique<Select_RunTestType>();
            return nullptr;
        }
};