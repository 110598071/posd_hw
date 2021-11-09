#include "../src/circle.h"

TEST(CaseCircle, IteratorIsDone) {
    Circle c(1.0);
    Iterator* it = c.createIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}

TEST(CaseCircle, IteratorCurrentItem) {
    Circle c(1.0);
    Iterator* it = c.createIterator();
    ASSERT_THROW(it->currentItem(), std::out_of_range);
    delete it;
}

TEST(CaseCircle, IteratorAddShape) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(2.0);
    ASSERT_THROW(c1->addShape(c2), std::out_of_range);
    delete c1;
    delete c2;
}

TEST(CaseCircle, Area) {
    Circle c(1.1);
    ASSERT_NEAR(3.8013, c.area(), 0.001);
}

TEST(CaseCircle, Perimeter) {
    Circle c(1.1);
    ASSERT_NEAR(6.9115, c.perimeter(), 0.001);
}

TEST(CaseCircle, Info) {
    Circle c(1.1);
    ASSERT_EQ("Circle (1.10)", c.info());
}

TEST(CaseCircle, RadiusIsZero) {
    EXPECT_THROW(Circle c(0), std::out_of_range);
}

TEST(CaseCircle, RadiusIsNegative) {
    EXPECT_THROW(Circle c(-3.14), std::out_of_range);
}