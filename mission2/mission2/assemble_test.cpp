#include "gmock/gmock.h"
#include "DisplayMenu_Factory.h"

// Car type ���� �� ����
TEST(CalTest, TC_CarSelect) {
    EXPECT_EQ(1, 01);
}

// Engine type ���� �� ����
TEST(CalTest, TC_EngineSelect) {
    EXPECT_EQ(1, 01);
}

// brake type ���� �� ����
TEST(CalTest, TC_BrakeSelect) {
    EXPECT_EQ(1, 01);
}

// run, test ���� �� ����
TEST(CalTest, TC_RunTestSelect) {
    EXPECT_EQ(1, 0);
}

// ������ġ��Bosch ��ǰ�� ����ߴٸ�, ������ġ��Bosch ��ǰ�� ����ؾ��Ѵ�
TEST(CalTest, TC_Unable_Parts) {
    EXPECT_EQ(1, 0);
}

// Continental�� Sedan�� ������ġ�� ������ �ʴ´�.(���ܿ� Continental ��ǰ ��� �Ұ�)
TEST(CalTest, TC_Unable_SedanParts) {
    EXPECT_EQ(1, 0);
}

// ����Ÿ��SUV�뿣�����������ʴ´�.
TEST(CalTest, TC_Unable_SUVParts) {
    EXPECT_EQ(1, 0);
}

// WIA�� Truck�� ������ ������ �ʴ´�.
TEST(CalTest, TC_Unable_TruckParts1) {
    EXPECT_EQ(1, 0);
}

// Mando�� Truck�� ������ġ(brake System)�� ������ �ʴ´�.
TEST(CalTest, TC_Unable_TruckParts2) {
    EXPECT_EQ(1, 0);
}