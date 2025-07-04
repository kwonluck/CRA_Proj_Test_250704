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
#include "Car_Factory.h"


int stack[10];
void clear_UserInput(char  user_input[100]);

int main()
{
    char user_input[100];
    int step = CarType_Q;
    std::unique_ptr<Car_IF> car;
    while (1)
    {
        auto menu = DisplayMenu_Factory::createMenu(static_cast<QuestionType>(step));
        menu->show_Menu();
        menu->show_InputPrompt();

        fgets(user_input, sizeof(user_input), stdin);
        // 엔터 개행문자 제거
        clear_UserInput(user_input);

        // exit 명령어 확인
        if (menu->isAnswer_Exit(user_input))
            break;

        // 숫자로 된 대답인지 확인 및 숫자로 변환
        int answer = 0;
        if (menu->check_AnswerIsNumber(user_input, answer) == false)
            continue;
        if (menu->check_Valid_inputNum(step, answer) == false)
            continue;

        if (answer == 0) {
            menu->return_Menu(step);
            continue;
        }

        menu->show_YourSelect(answer);
        if (step == CarType_Q) {
            car = CarFactory::createCar(static_cast<CarType>(answer));
            stack[step] = answer;
            step++;
        }
        else {
            stack[step] = answer;
            car->Do_Action(step, answer);
        }
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

#endif