#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/iterator/iterator.h"
#include "../src/iterator/compound_iterator.h"
#include "../src/visitor/shape_info_visitor.h"
#include <stdexcept>

class CaseCompoundShape: public ::testing::Test {
    protected:
        Shape* c1;
        Shape* c2;
        Shape* r;

        void SetUp() override {
            c1 = new Circle(1.0);
            c2 = new Circle(1.0);
            r = new Rectangle(5.0, 3.0);
        }

        void TearDown() override {
            delete c1;
            delete c2;
            delete r;
        } 
};

TEST_F(CaseCompoundShape, Creation) {
    Shape* shapes[3] = {c1, c2, r};
    ASSERT_NO_THROW(CompoundShape cs(shapes,3));
}

TEST_F(CaseCompoundShape, CompoundShapeShouldBeAShape) {
    Shape* shapes[3] = {c1, c2, r};
    ASSERT_NO_THROW(Shape* shape = new CompoundShape(shapes,3));
}

TEST_F(CaseCompoundShape, Area) {
    Shape* shapes[3] = {c1, c2, r};
    CompoundShape cs(shapes,3);
    ASSERT_NEAR(21.283, cs.area(), 0.001);
}

TEST_F(CaseCompoundShape, Perimeter) {
    Shape* shapes[3] = {c1, c2, r};
    CompoundShape cs(shapes,3);
    ASSERT_NEAR(28.566, cs.perimeter(), 0.001);
}

TEST_F(CaseCompoundShape, AddShape) {
    CompoundShape* cs = new CompoundShape();
    ASSERT_NO_THROW(cs->addShape(new Circle(1.0)));

    delete cs;
}

TEST_F(CaseCompoundShape, Info) {
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14 ,4));

    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(12.34567));
    cs2->addShape(cs1);

    ASSERT_EQ("CompoundShape", cs2->info());

    delete cs1;
    delete cs2;
}

TEST_F(CaseCompoundShape, DeleteShapeSuccess) {
    Shape* shapes[3] = {c1, c2, r};
    CompoundShape cs(shapes,3);

    ASSERT_NO_THROW(cs.deleteShape(c2));
}

TEST_F(CaseCompoundShape, DeleteInnerShape) {
    CompoundShape* cs1 = new CompoundShape();
    CompoundShape* cs2 = new CompoundShape();
    CompoundShape* cs3 = new CompoundShape();

    cs3->addShape(r);
    cs2->addShape(c2);
    cs1->addShape(c1);

    cs2->addShape(cs3);
    cs1->addShape(cs2);

    ASSERT_NO_THROW(cs1->deleteShape(r));

    delete cs1;
    delete cs2;
    delete cs3;
}

TEST_F(CaseCompoundShape, CreateCompoundIterator) {
    Shape* shapes[3] = {c1, c2, r};
    Shape* shape = new CompoundShape(shapes,3);
    ASSERT_NO_THROW(shape->createIterator());

    delete shape;
}

TEST_F(CaseCompoundShape, Accept) {
    Shape* shapes[3] = {c1, c2, r};
    Shape* shape = new CompoundShape(shapes,3);

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    ASSERT_NO_THROW(shape->accept(visitor));

    delete shape;
    delete visitor;
}

TEST_F(CaseCompoundShape, CreateIterator) {
    Shape* shapes[3] = {c1, c2, r};
    Shape* shape = new CompoundShape(shapes,3);

    ASSERT_NO_THROW(shape->createIterator());

    delete shape;
}