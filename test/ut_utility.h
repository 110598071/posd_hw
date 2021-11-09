#include "../src/shape.h"
#include "../src/utility.h"
#include <stdexcept>

TEST(CasUtility, SelectShapeByArea) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(2.0);
    Shape* r1 = new Rectangle(5.0, 3.0);
    Shape* r2 = new Rectangle(3.0, 5.0);

    Shape* shapes[4] = {c1, c2, r1, r2};
    CompoundShape* cs = new CompoundShape(shapes,4);

    Shape* result = selectShape(cs, [](Shape* shape){
        if (shape->area() == 15.0) {
            return true;
        }
        else {
            return false;
        }
    });

    ASSERT_EQ(r1, result);

    delete c1;
    delete c2;
    delete r1;
    delete r2;
    delete cs;
}

TEST(CasUtility, SelectShapeByType) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(2.0);
    Shape* r1 = new Rectangle(5.0, 3.0);
    Shape* r2 = new Rectangle(3.0, 5.0);

    Shape* shapes[4] = {c1, c2, r1, r2};
    CompoundShape* cs = new CompoundShape(shapes,4);

    Shape* result = selectShape(cs, [](Shape* shape){
        if (typeid(*shape) == typeid(Circle(5.0))) {
            return true;
        }
        else {
            return false;
        }
    });

    ASSERT_EQ(c1, result);

    delete c1;
    delete c2;
    delete r1;
    delete r2;
    delete cs;
}