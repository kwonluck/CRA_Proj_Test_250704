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
            printf("���̹���\n");
            return true;
        }
        return false;
    }

    bool check_AnswerIsNumber(char* user_input, int& answer) {
        char* stringAnswer;
        answer = strtol(user_input, &stringAnswer, 10); // ���ڿ��� 10������ ��ȯ
        if (*stringAnswer != '\0') {
            printf("ERROR :: ���ڸ� �Է� ����\n");
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
        printf("� ���� Ÿ���� �����ұ��?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }

    void show_YourSelect(const int& answer) override {
        if (answer == CarType::SEDAN)
            printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
        if (answer == CarType::SUV)
            printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
        if (answer == CarType::TRUCK)
            printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
        delay(delayTime);
    }

    bool check_Valid_inputNum(const int& step, const int& answer) override
    {
        if (answer >= 1 && answer <= 3)
            return true;

        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        delay(delayTime);
        return false;
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

    void show_YourSelect(const int& answer) override {
        if (answer == Engine::GM)
            printf("GM ������ �����ϼ̽��ϴ�.\n");
        if (answer == Engine::TOYOTA)
            printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
        if (answer == Engine::WIA)
            printf("WIA ������ �����ϼ̽��ϴ�.\n");
        delay(delayTime);
    }

    bool check_Valid_inputNum(const int& step, const int& answer) override
    {
        if (answer >= 0 && answer <= 4)
            return true;

        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
        delay(delayTime);
        return false;
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

    void show_YourSelect(const int& answer) override {
        if (answer == BrakeSystem::MANDO)
            printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == BrakeSystem::CONTINENTAL)
            printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == BrakeSystem::BOSCH_B)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        delay(delayTime);
    }

    bool check_Valid_inputNum(const int& step, const int& answer) override
    {
        if (answer >= 0 && answer <= 3)
            return true;

        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
        delay(delayTime);
        return false;
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

    void show_YourSelect(const int& answer) override {
        if (answer == SteeringSystem::BOSCH_S)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == SteeringSystem::MOBIS)
            printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
        delay(delayTime);
    }

    bool check_Valid_inputNum(const int& step, const int& answer) override
    {
        if (answer >= 0 && answer <= 2)
            return true;

        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
        delay(delayTime);
        return false;
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

        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
        delay(delayTime);
        return false;
    }

    void return_Menu(int& step) override {
        step = 0;
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