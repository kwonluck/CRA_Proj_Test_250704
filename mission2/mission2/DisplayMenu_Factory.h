#pragma once
#include <iostream>
#include "defineEnum.h"

#define CLEAR_SCREEN "\033[H\033[2J"


class Menu {
public:
    int delayTime = 800; // �⺻ ���� �ð�

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
        printf("� ���� Ÿ���� �����ұ��?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    void show_YourSelect(const int& answer) {
        if (answer == CarType::SEDAN)
            printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
        if (answer == CarType::SUV)
            printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
        if (answer == CarType::TRUCK)
            printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
        delay(delayTime);
    }
};

class Select_EngineType : public Menu {
public:
    void show_Menu() override {
        printf("� ������ ž���ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. ���峭 ����\n");
    }
    void show_YourSelect(const int& answer) {
        if (answer == Engine::GM)
            printf("GM ������ �����ϼ̽��ϴ�.\n");
        if (answer == Engine::TOYOTA)
            printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
        if (answer == Engine::WIA)
            printf("WIA ������ �����ϼ̽��ϴ�.\n");
        delay(delayTime);
    }
};

class Select_BrakeType : public Menu {
public:
    void show_Menu() override {
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    void show_YourSelect(const int& answer) {
        if (answer == brakeSystem::MANDO)
            printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == brakeSystem::CONTINENTAL)
            printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == brakeSystem::BOSCH_B)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        delay(delayTime);
    }
};

class Select_SteeringType : public Menu {
public:
    void show_Menu() override {
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    void show_YourSelect(const int& answer) {
        if (answer == SteeringSystem::BOSCH_S)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == SteeringSystem::MOBIS)
            printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
        delay(delayTime);
    }
};

class Select_RunTestType : public Menu {
public:
    int delayTime = 1500; // RunTestType �޴��� ���� �ð��� �ø�
    void show_Menu() override {
        printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
        printf("� ������ �ұ��?\n");
        printf("0. ó�� ȭ������ ���ư���\n");
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
        // Ÿ�Կ� ���� ��ü ����
        static std::unique_ptr<Menu> createMenu(QuestionType type) {
            if (type == QuestionType::CarType_Q) return std::make_unique<Select_CarType>();
            if (type == QuestionType::Engine_Q) return std::make_unique<Select_EngineType>();
            if (type == QuestionType::brakeSystem_Q) return std::make_unique<Select_BrakeType>();
            if (type == QuestionType::SteeringSystem_Q) return std::make_unique<Select_SteeringType>();
            if (type == QuestionType::Run_Test_Q) return std::make_unique<Select_RunTestType>();
            return nullptr;
        }
};