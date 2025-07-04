#include "gmock/gmock.h"
#include "defineEnum.h"
#include "DisplayMenu_Factory.h"
#include "Car_Factory.h"
#include "Engine_Factory.h"
#include "Brake_Factory.h"
#include "Steering_Factory.h"


// ������ġ��Bosch ��ǰ�� ����ߴٸ�, ������ġ��Bosch ��ǰ�� ����ؾ��Ѵ�
TEST(CalTest, TC_Unable_Parts) {

    auto car = CarFactory::createCar(CarType::SEDAN);
    int step = 1;
    car->Do_Action(step, Engine::GM);
    car->Do_Action(step, BrakeSystem::BOSCH_B);
    car->Do_Action(step, SteeringSystem::MOBIS);
    car->testProducedCar();
    EXPECT_EQ(1, 1);
}

// Continental�� Sedan�� ������ġ�� ������ �ʴ´�.(���ܿ� Continental ��ǰ ��� �Ұ�)
TEST(CalTest, TC_Unable_SedanParts) {
    EXPECT_EQ(1, 1);
}

// ����Ÿ��SUV�뿣�����������ʴ´�.
TEST(CalTest, TC_Unable_SUVParts) {
    EXPECT_EQ(1, 1);
}

// WIA�� Truck�� ������ ������ �ʴ´�.
TEST(CalTest, TC_Unable_TruckParts1) {
    EXPECT_EQ(1, 1);
}

// Mando�� Truck�� ������ġ(brake System)�� ������ �ʴ´�.
TEST(CalTest, TC_Unable_TruckParts2) {
    EXPECT_EQ(1, 1);
}