#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"
#include "../src/visitor/shape_info_visitor.h"

TEST(CaseTriangle, Accept) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(7.619, -4);
    Shape* t1 = new Triangle(tdv1, tdv2);
    
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    ASSERT_NO_THROW(t1->accept(visitor));
    
    delete t1;
}

TEST(CaseTriangle, Delete) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(7.619, -4);
    Shape* t1 = new Triangle(tdv1, tdv2);
    Shape* t2 = new Triangle(tdv2, tdv1);
    
    ASSERT_THROW(t1->deleteShape(t2), std::out_of_range);
    delete t1;
    delete t2;
}

TEST(CaseTriangle, IteratorIsDone) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(7.619, -4);
    Triangle t(tdv1, tdv2);
    Iterator* it = t.createIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}

TEST(CaseTriangle, IteratorCurrentItem) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(7.619, -4);
    Triangle t(tdv1, tdv2);
    Iterator* it = t.createIterator();
    ASSERT_THROW(it->currentItem(), std::out_of_range);
    delete it;
}

TEST(CaseTriangle, IteratorAddShape) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(7.619, -4);
    Shape* t1 = new Triangle(tdv1, tdv2);
    Shape* t2 = new Triangle(tdv2, tdv1);
    ASSERT_THROW(t1->addShape(t2), std::out_of_range);
    delete t1;
    delete t2;
}

TEST(CaseTriangle, Area) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(7.619, -4);
    Triangle t(tdv1, tdv2);
    ASSERT_NEAR(53.363, t.area(), 0.001);
}

TEST(CaseTriangle, Perimeter) {
    TwoDimensionalVector tdv1(8, 0);
    TwoDimensionalVector tdv2(4, 3);
    Triangle t(tdv1, tdv2);
    ASSERT_NEAR(18, t.perimeter(), 0.001);
}

TEST(CaseTriangle, Info) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(17.57, -4);
    Triangle t(tdv1, tdv2);
    ASSERT_EQ("Triangle ([3.00,12.43] [17.57,-4.00])", t.info());
}

TEST(CaseTriangle, CreateWithParallelVector) {
    TwoDimensionalVector tdv1(3, 4);
    TwoDimensionalVector tdv2(9, 12);
    EXPECT_THROW(Triangle t(tdv1, tdv2), std::invalid_argument);
}

TEST(CaseTriangle, CreateWithZeroVector) {
    TwoDimensionalVector tdv1(3, 4);
    TwoDimensionalVector tdv2(0, 0);
    EXPECT_THROW(Triangle t(tdv1, tdv2), std::invalid_argument);
}

TEST(CaseTriangle, BothVectorAreXAxialVector) {
    TwoDimensionalVector tdv1(3, 0);
    TwoDimensionalVector tdv2(9, 0);
    EXPECT_THROW(Triangle t(tdv1, tdv2), std::invalid_argument);
}

TEST(CaseTriangle, BothVectorAreYAxialVector) {
    TwoDimensionalVector tdv1(0, 7);
    TwoDimensionalVector tdv2(0, 9);
    EXPECT_THROW(Triangle t(tdv1, tdv2), std::invalid_argument);
}