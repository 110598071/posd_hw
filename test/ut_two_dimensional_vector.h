#include "../src/two_dimensional_vector.h"

#include <cmath>

TEST(CaseTwoDimensionalVector, Creation) {
    TwoDimensionalVector tdv(3, 12.433);
    ASSERT_NEAR(3.00, tdv.x(), 0.0001);
    ASSERT_NEAR(12.433, tdv.y(), 0.0001);
}

TEST(CaseTwoDimensionalVector, Length) {
    TwoDimensionalVector tdv(3, 12.433);
    ASSERT_NEAR(12.7898, tdv.length(), 0.0001);
}

TEST(CaseTwoDimensionalVector, Dot) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(7.619, -4);
    ASSERT_NEAR(-26.875, tdv1.dot(tdv2), 0.0001);
}

TEST(CaseTwoDimensionalVector, Cross) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(7.619, -4);
    ASSERT_NEAR(-106.727, tdv1.cross(tdv2), 0.0001);
}

TEST(CaseTwoDimensionalVector, Subtract) {
    TwoDimensionalVector tdv1(12, 5);
    TwoDimensionalVector tdv2(9, 12);
    TwoDimensionalVector tdv3(3, -7);
    ASSERT_NEAR(tdv3.x(), tdv1.subtract(tdv2).x(), 0.0001);
    ASSERT_NEAR(tdv3.y(), tdv1.subtract(tdv2).y(), 0.0001);
}

TEST(CaseTwoDimensionalVector, Info) {
    TwoDimensionalVector tdv(3, 12.433);
    ASSERT_EQ("[3.00,12.43]", tdv.info());
}

TEST(CaseTwoDimensionalVector, DotProductWithOrthogonalVector) {
    TwoDimensionalVector tdv1(sqrt(3), 1);
    TwoDimensionalVector tdv2(-2, 2*sqrt(3));
    ASSERT_NEAR(0, tdv1.dot(tdv2), 0.0001);
}

TEST(CaseTwoDimensionalVector, DotProductWithAcuteAngle) {
    TwoDimensionalVector tdv1(12, 5);
    TwoDimensionalVector tdv2(9, 12);
    ASSERT_TRUE(tdv1.dot(tdv2) > 0);
}

TEST(CaseTwoDimensionalVector, DotProductWithObtuseAngle) {
    TwoDimensionalVector tdv1(12, 5);
    TwoDimensionalVector tdv2(-9, -12);
    ASSERT_TRUE(tdv1.dot(tdv2) < 0);
}

TEST(CaseTwoDimensionalVector, CrossProductWithParallelVector) {
    TwoDimensionalVector tdv1(3, 4);
    TwoDimensionalVector tdv2(9, 12);
    ASSERT_NEAR(0, tdv1.cross(tdv2), 0.0001);
}

TEST(CaseTwoDimensionalVector, CrossProductWithCounterClockwise) {
    TwoDimensionalVector tdv1(3, 4);
    TwoDimensionalVector tdv2(5, 12);
    ASSERT_TRUE(tdv1.cross(tdv2) > 0);
}

TEST(CaseTwoDimensionalVector, CrossProductWithClockwise) {
    TwoDimensionalVector tdv1(3, 4);
    TwoDimensionalVector tdv2(5, 12);
    ASSERT_TRUE(tdv2.cross(tdv1) < 0);
}

TEST(CaseTwoDimensionalVector, LengthOfZeroVectorShouldBeZero) {
    TwoDimensionalVector tdv(0, 0);
    ASSERT_NEAR(0, tdv.length(), 0.0001);
}

TEST(CaseTwoDimensionalVector, DotProductWithZeroVector) {
    TwoDimensionalVector tdv1(12, 5);
    TwoDimensionalVector tdv2(0, 0);
    EXPECT_THROW(tdv1.dot(tdv2), std::invalid_argument);
}

TEST(CaseTwoDimensionalVector, CrossProductWithZeroVector) {
    TwoDimensionalVector tdv1(12, 5);
    TwoDimensionalVector tdv2(0, 0);
    EXPECT_THROW(tdv1.cross(tdv2), std::invalid_argument);
}