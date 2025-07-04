#include <iostream>
#include "Engine_Factory.h"
#include "Brake_Factory.h"
#include "Steering_Factory.h"

// Car 인터페이스
class Car_IF {
public:
    CarType carType; // 자동차 타입
    std::unique_ptr<Engine_IF> part_Engine; // Use std::unique_ptr
    std::unique_ptr<Brake_IF> part_Brake;  // Use std::unique_ptr
    std::unique_ptr<Steering_IF> part_Steering; // Use std::unique_ptr

    virtual void runProducedCar() = 0;
    virtual void testProducedCar() = 0;
    virtual ~Car_IF() {}

    void Do_Action(int& step, const int& answer) {
        if (step < QuestionType::Run_Test_Q) {
            Add_Parts(step, answer);
            step++;
        }
        else if (step == QuestionType::Run_Test_Q) {
            if (answer == RunTest::Run)
                runProducedCar();
            else if (answer == RunTest::Test)
                testProducedCar();
            delay(2000);
        }
    }

    void Add_Parts(const int& step, const int& answer) {
        if (step == Engine_Q) {
            part_Engine = EngineFactory::createEngine(static_cast<Engine>(answer));
        }
        else if (step == brakeSystem_Q) {
            part_Brake = BrakeFactory::createBrake(static_cast<BrakeSystem>(answer));
        }
        else if (step == SteeringSystem_Q) {
            part_Steering = SteeringFactory::createSteering(static_cast<SteeringSystem>(answer));
            part_Steering = SteeringFactory::createSteering(static_cast<SteeringSystem>(answer));
        }
    }

    bool isValidCheck() {
        if (part_Brake->Brand == BrakeSystem::BOSCH_B && part_Steering->Brand != SteeringSystem::BOSCH_S)
            return false;
        return true;
    }
    
    void printCarInfo() {
        if (carType == CarType::SEDAN)
            printf("Car Type : Sedan\n");
        if (carType == CarType::SUV)
            printf("Car Type : SUV\n");
        if (carType == CarType::TRUCK)
            printf("Car Type : Truck\n");
        if (part_Engine->Brand == Engine::GM)
            printf("Engine : GM\n");
        if (part_Engine->Brand == Engine::TOYOTA)
            printf("Engine : TOYOTA\n");
        if (part_Engine->Brand == Engine::WIA)
            printf("Engine : WIA\n");
        if (part_Brake->Brand == BrakeSystem::MANDO)
            printf("Brake System : Mando\n");
        if (part_Brake->Brand == BrakeSystem::CONTINENTAL)
            printf("Brake System : Continental\n");
        if (part_Brake->Brand == BrakeSystem::BOSCH_B)
            printf("Brake System : Bosch\n");
        if (part_Steering->Brand == SteeringSystem::BOSCH_S)
            printf("SteeringSystem : Bosch\n");
        if (part_Steering->Brand == SteeringSystem::MOBIS)
            printf("SteeringSystem : Mobis\n");
    }
};

class Sedan : public Car_IF {
public:
    Sedan() {
        carType = CarType::SEDAN;
    }

    void runProducedCar() override {
        if (isValidCheck() == false)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("자동차가 동작되지 않습니다\n");
            return;
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");

            if (part_Engine->Brand == Engine::UnableEngine)
            {
                printf("엔진이 고장나있습니다.\n");
                printf("자동차가 움직이지 않습니다.\n");
            }
            else
            {
                printCarInfo();
                printf("자동차가 동작됩니다.\n");
            }
        }
    };

    void testProducedCar() override {
        if (part_Brake->Brand == BrakeSystem::CONTINENTAL)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Sedan에는 Continental제동장치 사용 불가\n");
        }        
        else if (part_Brake->Brand == BOSCH_B && part_Steering->Brand != BOSCH_S)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");
        }
    
    };

    bool isValidCheck() {
        if (Car_IF::isValidCheck() == false)
            return false;
        if (part_Brake->Brand == BrakeSystem::CONTINENTAL) 
            return false;
        return true;
    }

    void testCar() {
    }
};

class Suv : public Car_IF {
public:
    Suv() {
        carType = CarType::SUV;
    }
    void runProducedCar() override {
        if (isValidCheck() == false)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("자동차가 동작되지 않습니다\n");
            return;
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");

            if (part_Engine->Brand == Engine::UnableEngine)
            {
                printf("엔진이 고장나있습니다.\n");
                printf("자동차가 움직이지 않습니다.\n");
            }
            else
            {
                printCarInfo();
                printf("자동차가 동작됩니다.\n");
            }
        };
    };
    void testProducedCar() override {
        if (part_Engine->Brand == Engine::TOYOTA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("SUV에는 TOYOTA엔진 사용 불가\n");
        }
        else if (part_Brake->Brand == BOSCH_B && part_Steering->Brand != BOSCH_S)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");
        }
    };

    bool isValidCheck() {
        if (Car_IF::isValidCheck() == false)
            return false;
        if (part_Engine->Brand == Engine::TOYOTA)
            return false;
        return true;
    }
};

class Truck : public Car_IF {
public:
    Truck() {
        carType = CarType::TRUCK;
    }
    void runProducedCar() override {
        if (isValidCheck() == false)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("자동차가 동작되지 않습니다\n");
            return;
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");

            if (part_Engine->Brand == Engine::UnableEngine)
            {
                printf("엔진이 고장나있습니다.\n");
                printf("자동차가 움직이지 않습니다.\n");
            }
            else
            {
                printCarInfo();
                printf("자동차가 동작됩니다.\n");
            }
        };
    };
    void testProducedCar() override {
        if (part_Engine->Brand == Engine::WIA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 WIA엔진 사용 불가\n");
        }
        else if (part_Brake->Brand == BrakeSystem::MANDO)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 Mando제동장치 사용 불가\n");
        }
        else if (part_Brake->Brand == BOSCH_B && part_Steering->Brand != BOSCH_S)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");
        }
    };

    bool isValidCheck() {
        if (Car_IF::isValidCheck() == false)
            return false;
        if (part_Engine->Brand == Engine::WIA || part_Brake->Brand == BrakeSystem::MANDO)
            return false;
        return true;
    }
};