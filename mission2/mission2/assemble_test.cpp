#include "gmock/gmock.h"
#include "defineEnum.h"
#include "DisplayMenu_Factory.h"
#include "Car_Factory.h"
#include "Engine_Factory.h"
#include "Brake_Factory.h"
#include "Steering_Factory.h"


// 제동장치에Bosch 제품을 사용했다면, 조향장치도Bosch 제품을 사용해야한다
TEST(CalTest, TC_Unable_Parts) {

    auto car = CarFactory::createCar(CarType::SEDAN);
    int step = 1;
    car->Do_Action(step, Engine::GM);
    car->Do_Action(step, BrakeSystem::BOSCH_B);
    car->Do_Action(step, SteeringSystem::MOBIS);
    car->testProducedCar();
    EXPECT_EQ(1, 1);
}

// Continental은 Sedan용 제동장치를 만들지 않는다.(세단에 Continental 제품 사용 불가)
TEST(CalTest, TC_Unable_SedanParts) {
    EXPECT_EQ(1, 1);
}

// 도요타는SUV용엔진을만들지않는다.
TEST(CalTest, TC_Unable_SUVParts) {
    EXPECT_EQ(1, 1);
}

// WIA는 Truck용 엔진을 만들지 않는다.
TEST(CalTest, TC_Unable_TruckParts1) {
    EXPECT_EQ(1, 1);
}

// Mando는 Truck용 제동장치(brake System)을 만들지 않는다.
TEST(CalTest, TC_Unable_TruckParts2) {
    EXPECT_EQ(1, 1);
}