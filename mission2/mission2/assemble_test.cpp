#include "gmock/gmock.h"
#include "DisplayMenu_Factory.h"

// Car type 범위 밖 선택
TEST(CalTest, TC_CarSelect) {
    EXPECT_EQ(1, 01);
}

// Engine type 범위 밖 선택
TEST(CalTest, TC_EngineSelect) {
    EXPECT_EQ(1, 01);
}

// brake type 범위 밖 선택
TEST(CalTest, TC_BrakeSelect) {
    EXPECT_EQ(1, 01);
}

// run, test 범위 밖 선택
TEST(CalTest, TC_RunTestSelect) {
    EXPECT_EQ(1, 0);
}

// 제동장치에Bosch 제품을 사용했다면, 조향장치도Bosch 제품을 사용해야한다
TEST(CalTest, TC_Unable_Parts) {
    EXPECT_EQ(1, 0);
}

// Continental은 Sedan용 제동장치를 만들지 않는다.(세단에 Continental 제품 사용 불가)
TEST(CalTest, TC_Unable_SedanParts) {
    EXPECT_EQ(1, 0);
}

// 도요타는SUV용엔진을만들지않는다.
TEST(CalTest, TC_Unable_SUVParts) {
    EXPECT_EQ(1, 0);
}

// WIA는 Truck용 엔진을 만들지 않는다.
TEST(CalTest, TC_Unable_TruckParts1) {
    EXPECT_EQ(1, 0);
}

// Mando는 Truck용 제동장치(brake System)을 만들지 않는다.
TEST(CalTest, TC_Unable_TruckParts2) {
    EXPECT_EQ(1, 0);
}