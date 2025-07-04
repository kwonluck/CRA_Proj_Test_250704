#ifdef NDEBUG
#pragma once
#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defineEnum.h"
#include "DisplayMenu_Factory.h"

int stack[10];

void clear_UserInput(char  user_input[100]);
bool isAnswer_Exit(const char* user_input);
bool check_AnswerIsNumber(char* user_input, int& answer);
bool check_Invalid_inputNum(const int& step, const int& answer);

void do_Answer(int& step, const int& answer);
void runProducedCar();
void testProducedCar();

int main()
{
    char user_input[100];
    int step = CarType_Q;

    while (1)
    {
        auto menu = DisplayMenu_Factory::createMenu(static_cast<QuestionType>(step));
        menu->show_Menu();
        menu->show_InputPrompt();
        fgets(user_input, sizeof(user_input), stdin);

        // 엔터 개행문자 제거
        clear_UserInput(user_input);

        // exit 명령어 확인
        if (isAnswer_Exit(user_input))
            break;

        // 숫자로 된 대답인지 확인 및 숫자로 변환
        int answer = 0;
        if (check_AnswerIsNumber(user_input, answer) == false)
            continue;

        if (check_Invalid_inputNum(step, answer))
            continue;

        if (answer == 0)
        {
            // 처음으로 돌아가기
            if (step == Run_Test_Q)
                step = CarType_Q;
            // 이전으로 돌아가기
            if (step >= 1)
                step -= 1;
            continue;
        }

        menu->show_YourSelect(answer);
        do_Answer(step, answer);
    }
}


void clear_UserInput(char user_input[100])
{
    char* context = nullptr;
    user_input = strtok_s(user_input, "\r", &context);
    if (user_input != nullptr)
    {
        user_input = strtok_s(user_input, "\n", &context);
    }
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

bool check_AnswerIsNumber(char* user_input, int& answer)
{
    char* stringAnswer;
    answer = strtol(user_input, &stringAnswer, 10); // 문자열을 10진수로 변환
    if (*stringAnswer != '\0')
    {
        printf("ERROR :: 숫자만 입력 가능\n");
        delay(800);
        return false;
    }
    return true;
}

bool check_Invalid_inputNum(const int& step, const int& answer)
{
    if (step == CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return true;
    }

    if (step == Engine_Q && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        delay(800);
        return true;
    }

    if (step == brakeSystem_Q && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return true;
    }

    if (step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        delay(800);
        return true;
    }

    if (step == Run_Test_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay(800);
        return true;
    }
    return false;
}


void do_Answer(int& step, const int& answer)
{
    int delayTime = 800;
    switch (step)
    {
    case CarType_Q:
        stack[CarType_Q] = answer;
        step = Engine_Q;
        break;
    case Engine_Q:
        stack[Engine_Q] = answer;
        step = brakeSystem_Q;
        break;
    case brakeSystem_Q:
        stack[brakeSystem_Q] = answer;
        step = SteeringSystem_Q;
        break;
    case SteeringSystem_Q:
        stack[SteeringSystem_Q] = answer;
        step = Run_Test_Q;
        break;
    case Run_Test_Q:
        if (answer == RunTest::Run)
            runProducedCar();
        else if (answer == RunTest::Test)
            testProducedCar();
        delay(2000);
        break;
    default:
        break;
    }
}
int isValidCheck()
{
    if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }

    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }

    if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        return false;
    }

    if (stack[CarType_Q] == TRUCK && (stack[Engine_Q] == WIA || stack[brakeSystem_Q] == MANDO))
    {
        return false;
    }

    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (stack[Engine_Q] == 4)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            if (stack[CarType_Q] == CarType::SEDAN)
                printf("Car Type : Sedan\n");
            if (stack[CarType_Q] == CarType::SUV)
                printf("Car Type : SUV\n");
            if (stack[CarType_Q] == CarType::TRUCK)
                printf("Car Type : Truck\n");
            if (stack[Engine_Q] == Engine::GM)
                printf("Engine : GM\n");
            if (stack[Engine_Q] == Engine::TOYOTA)
                printf("Engine : TOYOTA\n");
            if (stack[Engine_Q] == Engine::WIA)
                printf("Engine : WIA\n");
            if (stack[brakeSystem_Q] == brakeSystem::MANDO)
                printf("Brake System : Mando");
            if (stack[brakeSystem_Q] == brakeSystem::CONTINENTAL)
                printf("Brake System : Continental\n");
            if (stack[brakeSystem_Q] == brakeSystem::BOSCH_B)
                printf("Brake System : Bosch\n");
            if (stack[SteeringSystem_Q] == SteeringSystem::BOSCH_S)
                printf("SteeringSystem : Bosch\n");
            if (stack[SteeringSystem_Q] == SteeringSystem::MOBIS)
                printf("SteeringSystem : Mobis\n");

            printf("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}

#endif