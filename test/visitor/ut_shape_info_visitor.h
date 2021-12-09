#include "../../src/visitor/shape_info_visitor.h"
#include "../../src/compound_shape.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/shape.h"
#include "../../src/triangle.h"
#include "../../src/two_dimensional_vector.h"

#include <iostream>

TEST(CaseVisitor, VisitCircle) {
    Shape* c = new Circle(1.1);
    ShapeVisitor* visitor = new ShapeInfoVisitor();
    c->accept(visitor);
    std::string _info = visitor->getResult();

    // std::cout << _info << std::endl;

    ASSERT_EQ("Circle (1.10)\n", _info);

    delete c;
    delete visitor;
}

TEST(CaseVisitor, VisitRectangle) {
    Shape* r = new Rectangle(3.14, 4.00);
    ShapeVisitor* visitor = new ShapeInfoVisitor();
    r->accept(visitor);
    std::string _info = visitor->getResult();

    ASSERT_EQ("Rectangle (3.14 4.00)\n", _info);

    delete r;
    delete visitor;
}

TEST(CaseVisitor, VisitTriangle) {
    TwoDimensionalVector tdv1(3, 12.433);
    TwoDimensionalVector tdv2(17.57, -4);
    Shape* t = new Triangle(tdv1, tdv2);
    ShapeVisitor* visitor = new ShapeInfoVisitor();
    t->accept(visitor);
    std::string _info = visitor->getResult();

    ASSERT_EQ("Triangle ([3.00,12.43] [17.57,-4.00])\n", _info);

    delete t;
    delete visitor;
}

TEST(CaseVisitor, VisitCompoundShape) {
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14 ,4));

    // CompoundShape* cs2 = new CompoundShape();
    // cs2->addShape(new Circle(12.34567));
    // cs2->addShape(cs1);

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    cs1->accept(visitor);

    std::string _info = visitor->getResult();
    ASSERT_EQ("CompoundShape {\n  Circle (1.10)\n  Rectangle (3.14 4.00)\n}\n", _info);

    delete cs1;
    delete visitor;
}

TEST(CaseVisitor, VisitCompoundShapeWithComplexShape) {
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14 ,4));

    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(12.34567));
    cs2->addShape(cs1);

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    cs2->accept(visitor);

    std::string _info = visitor->getResult();
    ASSERT_EQ("CompoundShape {\n  Circle (12.35)\n  CompoundShape {\n    Circle (1.10)\n    Rectangle (3.14 4.00)\n  }\n}\n", _info);

    delete cs1;
    delete cs2;
    delete visitor;
}

TEST(CaseVisitor, VisitCompoundShapeWithDepthThree) {
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));

    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(2.2));

    CompoundShape* cs3 = new CompoundShape();
    cs3->addShape(new Circle(3.3));

    cs2->addShape(cs3);
    cs1->addShape(cs2);

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    cs1->accept(visitor);

    std::string _info = visitor->getResult();
    ASSERT_EQ("CompoundShape {\n  Circle (1.10)\n  CompoundShape {\n    Circle (2.20)\n    CompoundShape {\n      Circle (3.30)\n    }\n  }\n}\n", _info);

    delete cs1;
    delete cs2;
    delete cs3;
    delete visitor;
}