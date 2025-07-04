#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CLEAR_SCREEN "\033[H\033[2J"

int stack[10];

void show_SelectMenu(const int& step);
void printMenu_SelectCarType();
void printMenu_SelectEngine();
void printMenu_SelectBrake();
void printMenu_SelectSteering();
void printMenu_RunTest();

void clear_UserInput(char  user_input[100]);
bool isAnswer_Exit(const char* user_input);
bool check_AnswerIsNumber(char* user_input, int& answer);
bool check_Invalid_inputNum(const int& step, const int& answer);

void do_Answer(int& step, const int& answer);
void selectCarType(const int& answer);
void selectEngine(const int& answer);
void selectbrakeSystem(const int& answer);
void selectSteeringSystem(const int& answer);
void runProducedCar();
void testProducedCar();

void delay(const int& ms);

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test_Q,
};

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA
};

enum brakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

enum RunTest
{
    Run = 1,
    Test
};

void delay(const int& ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

int main()
{
    char user_input[100];
    int step = CarType_Q;

    while (1)
    {
        show_SelectMenu(step);

        printf("===============================\n");
        printf("INPUT > ");
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

        do_Answer(step, answer);
    }
}


void show_SelectMenu(const int& step)
{
    printf(CLEAR_SCREEN);
    switch (step)
    {
    case CarType_Q:
        printMenu_SelectCarType();
        break;
    case Engine_Q:
        printMenu_SelectEngine();
        break;
    case brakeSystem_Q:
        printMenu_SelectBrake();
        break;
    case SteeringSystem_Q:
        printMenu_SelectSteering();
        break;
    case Run_Test_Q:
        printMenu_RunTest();
        break;
    default:
        break;
    }
}

void printMenu_SelectCarType()
{
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

void printMenu_SelectEngine()
{
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. 고장난 엔진\n");
}

void printMenu_SelectBrake()
{
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void printMenu_SelectSteering()
{
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void printMenu_RunTest()
{
    printf("멋진 차량이 완성되었습니다.\n");
    printf("어떤 동작을 할까요?\n");
    printf("0. 처음 화면으로 돌아가기\n");
    printf("1. RUN\n");
    printf("2. Test\n");
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
        selectCarType(answer);
        step = Engine_Q;
        break;
    case Engine_Q:
        selectEngine(answer);
        step = brakeSystem_Q;
        break;
    case brakeSystem_Q:
        selectbrakeSystem(answer);
        step = SteeringSystem_Q;
        break;
    case SteeringSystem_Q:
        selectSteeringSystem(answer);
        step = Run_Test_Q;
        break;
    case Run_Test_Q:
        if (answer == RunTest::Run)
            runProducedCar();
        else if (answer == RunTest::Test)
        {
            printf("Test...\n");
            delay(1500);
            testProducedCar();
        }
        delayTime = 2000;
        break;
    default:
        break;
    }
    delay(delayTime);
}

void selectCarType(const int& answer)
{
    stack[CarType_Q] = answer;
    if (answer == CarType::SEDAN)
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    if (answer == CarType::SUV)
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    if (answer == CarType::TRUCK)
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
}

void selectEngine(const int& answer)
{
    stack[Engine_Q] = answer;
    if (answer == Engine::GM)
        printf("GM 엔진을 선택하셨습니다.\n");
    if (answer == Engine::TOYOTA)
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
    if (answer == Engine::WIA)
        printf("WIA 엔진을 선택하셨습니다.\n");
}

void selectbrakeSystem(const int& answer)
{
    stack[brakeSystem_Q] = answer;
    if (answer == brakeSystem::MANDO)
        printf("MANDO 제동장치를 선택하셨습니다.\n");
    if (answer == brakeSystem::CONTINENTAL)
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    if (answer == brakeSystem::BOSCH_B)
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
}

void selectSteeringSystem(const int& answer)
{
    stack[SteeringSystem_Q] = answer;
    if (answer == SteeringSystem::BOSCH_S)
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
    if (answer == SteeringSystem::MOBIS)
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
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