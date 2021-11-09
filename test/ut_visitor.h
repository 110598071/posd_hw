#include "../src/shape_visitor.h"
#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/shape.h"
#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"

#include <iostream>

TEST(CaseVisitor, VisitCompoundShape) {
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14 ,4));

    CompoundShape* cs3 = new CompoundShape();
    cs3->addShape(new Rectangle(9 ,9));
    cs1->addShape(cs3);

    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(12.35467));
    cs2->addShape(cs1);

    ShapeVisitor* visitor = new SelectShapeVisitor();
    cs2->accept(visitor,1);
    std::string _info = visitor->getInfo();

    std::cout << _info << std::endl;

    ASSERT_EQ("CompoundShape\n{\n   Circle (12.35)\n   CompoundShape\n   {\n      Circle (1.10)\n      Rectangle (3.14 4.00)\n      CompoundShape\n      {\n         Rectangle (9.00 9.00)\n      }\n   }\n}", _info);

    delete cs1;
    delete cs2;
    delete visitor;
}

TEST(CaseVisitor, VisitCircle) {
    Shape* c = new Circle(1.1);
    ShapeVisitor* visitor = new SelectShapeVisitor();
    c->accept(visitor);
    std::string _info = visitor->getInfo();

    // std::cout << _info << std::endl;

    ASSERT_EQ("Circle (1.10)", _info);

    delete c;
    delete visitor;
}

TEST(CaseVisitor, VisitRectangle) {
    Shape* r = new Rectangle(3.14, 4.00);
    ShapeVisitor* visitor = new SelectShapeVisitor();
    r->accept(visitor);
    std::string _info = visitor->getInfo();

    ASSERT_EQ("Rectangle (3.14 4.00)", _info);

    delete r;
    delete visitor;
}

TEST(CaseVisitor, VisitTriangle) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(17.57, -4);
    Shape* t = new Triangle(tdv1, tdv2);
    ShapeVisitor* visitor = new SelectShapeVisitor();
    t->accept(visitor);
    std::string _info = visitor->getInfo();

    ASSERT_EQ("Triangle ([3.00,12.43] [17.57,-4.00])", _info);

    delete t;
    delete visitor;
}