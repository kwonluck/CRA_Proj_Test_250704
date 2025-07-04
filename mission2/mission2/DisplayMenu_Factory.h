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
    virtual ~Menu() {}

    virtual void show_Menu() = 0;
    virtual void show_YourSelect(const int& answer) = 0;
    virtual bool check_Valid_inputNum(const int& step, const int& answer) = 0;
    virtual void return_Menu(int& step) {
        step -= 1;
    }

    void show_InputPrompt() {
        printf("===============================\n");
        printf("INPUT > ");
    }

    bool isAnswer_Exit(const char* user_input)
    {
        if (!strcmp(user_input, "exit"))
        {
            printf("바이바이\n");
            return true;
        }
        return false;
    }

    bool check_AnswerIsNumber(char* user_input, int& answer) {
        char* stringAnswer;
        answer = strtol(user_input, &stringAnswer, 10); // 문자열을 10진수로 변환
        if (*stringAnswer != '\0') {
            printf("ERROR :: 숫자만 입력 가능\n");
            delay(delayTime);
            return false;
        }
        return true;
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

    void show_YourSelect(const int& answer) override {
        if (answer == CarType::SEDAN)
            printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
        if (answer == CarType::SUV)
            printf("차량 타입으로 SUV을 선택하셨습니다.\n");
        if (answer == CarType::TRUCK)
            printf("차량 타입으로 Truck을 선택하셨습니다.\n");
        delay(delayTime);
    }

    bool check_Valid_inputNum(const int& step, const int& answer) override
    {
        if (answer >= 1 && answer <= 3)
            return true;

        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        delay(delayTime);
        return false;
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

    void show_YourSelect(const int& answer) override {
        if (answer == Engine::GM)
            printf("GM 엔진을 선택하셨습니다.\n");
        if (answer == Engine::TOYOTA)
            printf("TOYOTA 엔진을 선택하셨습니다.\n");
        if (answer == Engine::WIA)
            printf("WIA 엔진을 선택하셨습니다.\n");
        delay(delayTime);
    }

    bool check_Valid_inputNum(const int& step, const int& answer) override
    {
        if (answer >= 0 && answer <= 4)
            return true;

        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        delay(delayTime);
        return false;
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

    void show_YourSelect(const int& answer) override {
        if (answer == BrakeSystem::MANDO)
            printf("MANDO 제동장치를 선택하셨습니다.\n");
        if (answer == BrakeSystem::CONTINENTAL)
            printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
        if (answer == BrakeSystem::BOSCH_B)
            printf("BOSCH 제동장치를 선택하셨습니다.\n");
        delay(delayTime);
    }

    bool check_Valid_inputNum(const int& step, const int& answer) override
    {
        if (answer >= 0 && answer <= 3)
            return true;

        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        delay(delayTime);
        return false;
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

    void show_YourSelect(const int& answer) override {
        if (answer == SteeringSystem::BOSCH_S)
            printf("BOSCH 조향장치를 선택하셨습니다.\n");
        if (answer == SteeringSystem::MOBIS)
            printf("MOBIS 조향장치를 선택하셨습니다.\n");
        delay(delayTime);
    }

    bool check_Valid_inputNum(const int& step, const int& answer) override
    {
        if (answer >= 0 && answer <= 2)
            return true;

        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        delay(delayTime);
        return false;
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

    void show_YourSelect(const int& answer) override {
        if (answer == RunTest::Test)
        {
            printf("Test...\n");
            delay(delayTime);
        }
    }

    bool check_Valid_inputNum(const int& step, const int& answer) override
    {
        if (answer >= 0 && answer <= 2)
            return true;

        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay(delayTime);
        return false;
    }

    void return_Menu(int& step) override {
        step = 0;
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