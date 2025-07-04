#include <iostream>
#include "Engine_Factory.h"
#include "Brake_Factory.h"
#include "Steering_Factory.h"

// Car �������̽�
class Car_IF {
public:
    CarType carType; // �ڵ��� Ÿ��
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
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
            return;
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");

            if (part_Engine->Brand == Engine::UnableEngine)
            {
                printf("������ ���峪�ֽ��ϴ�.\n");
                printf("�ڵ����� �������� �ʽ��ϴ�.\n");
            }
            else
            {
                printCarInfo();
                printf("�ڵ����� ���۵˴ϴ�.\n");
            }
        }
    };

    void testProducedCar() override {
        if (part_Brake->Brand == BrakeSystem::CONTINENTAL)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Sedan���� Continental������ġ ��� �Ұ�\n");
        }        
        else if (part_Brake->Brand == BOSCH_B && part_Steering->Brand != BOSCH_S)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
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
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
            return;
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");

            if (part_Engine->Brand == Engine::UnableEngine)
            {
                printf("������ ���峪�ֽ��ϴ�.\n");
                printf("�ڵ����� �������� �ʽ��ϴ�.\n");
            }
            else
            {
                printCarInfo();
                printf("�ڵ����� ���۵˴ϴ�.\n");
            }
        };
    };
    void testProducedCar() override {
        if (part_Engine->Brand == Engine::TOYOTA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("SUV���� TOYOTA���� ��� �Ұ�\n");
        }
        else if (part_Brake->Brand == BOSCH_B && part_Steering->Brand != BOSCH_S)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
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
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
            return;
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");

            if (part_Engine->Brand == Engine::UnableEngine)
            {
                printf("������ ���峪�ֽ��ϴ�.\n");
                printf("�ڵ����� �������� �ʽ��ϴ�.\n");
            }
            else
            {
                printCarInfo();
                printf("�ڵ����� ���۵˴ϴ�.\n");
            }
        };
    };
    void testProducedCar() override {
        if (part_Engine->Brand == Engine::WIA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� WIA���� ��� �Ұ�\n");
        }
        else if (part_Brake->Brand == BrakeSystem::MANDO)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� Mando������ġ ��� �Ұ�\n");
        }
        else if (part_Brake->Brand == BOSCH_B && part_Steering->Brand != BOSCH_S)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
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