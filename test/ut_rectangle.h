#include "../src/rectangle.h"

TEST(CaseRectangle, IteratorIsDone) {
    Rectangle r(1.0, 2.0);
    Iterator* it = r.createIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}

TEST(CaseRectangle, IteratorCurrentItem) {
    Rectangle r(1.0, 2.0);
    Iterator* it = r.createIterator();
    ASSERT_THROW(it->currentItem(), std::out_of_range);
    delete it;
}

TEST(CaseRectangle, IteratorAddShape) {
    Shape* r1 = new Rectangle(1.0, 2.0);
    Shape* r2 = new Rectangle(3.0, 4.0);
    ASSERT_THROW(r1->addShape(r2), std::out_of_range);
    delete r1;
    delete r2;
}

TEST(CaseRectangle, Area) {
    Rectangle r(3.14, 4.00);
    ASSERT_NEAR(12.56, r.area(), 0.0001);
}

TEST(CaseRectangle, Perimeter) {
    Rectangle r(3.14, 4.00);
    ASSERT_NEAR(14.28, r.perimeter(), 0.0001);
}

TEST(CaseRectangle, Info) {
    Rectangle r(3.14, 4.00);
    ASSERT_EQ("Rectangle (3.14 4.00)", r.info());
}

TEST(CaseRectangle, LengthIsZero) {
    EXPECT_THROW(Rectangle r(0, 3.14), std::out_of_range);
}

TEST(CaseRectangle, WidthIsZero) {
    EXPECT_THROW(Rectangle r(3.14, 0), std::out_of_range);
}

TEST(CaseRectangle, LengthIsNegative) {
    EXPECT_THROW(Rectangle r(-3.14, 4), std::out_of_range);
}

TEST(CaseRectangle, WidthIsNegative) {
    EXPECT_THROW(Rectangle r(3.14, -4), std::out_of_range);
}