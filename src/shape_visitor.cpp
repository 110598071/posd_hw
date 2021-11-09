#include "./circle.h"
#include "./compound_shape.h"
#include "./triangle.h"
#include "./rectangle.h"
#include "./shape_visitor.h"
#include "./iterator/iterator.h"

void SelectShapeVisitor::visitCompoundShape(CompoundShape* cs, int stage) {
    info.append("CompoundShape\n");

    for (int i=1; i<=stage-1; i++) {
        info.append("   ");
    }
    info.append("{\n");

    Iterator* it = cs->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        for (int i=1; i<=stage; i++) {
            info.append("   ");
        }

        if (typeid(*(it->currentItem())) == typeid(*cs)) {
            ShapeVisitor* visitor = new SelectShapeVisitor();
            it->currentItem()->accept(visitor, stage+1);
            info.append(visitor->getInfo());
        }
        else {
            info.append(it->currentItem()->info());
        }

        info.append("\n");
    }

    for (int i=1; i<=stage-1; i++) {
        info.append("   ");
    }
    info.append("}");
}
void SelectShapeVisitor::visitCircle(Circle* c) {
    info.append("Circle (");
    info.append(c->getRadius().substr(0, c->getRadius().find(".")+3));
    info.append(")");
}
void SelectShapeVisitor::visitRectangle(Rectangle* r) {
    info.append("Rectangle (");
    info.append(r->getLength().substr(0, r->getLength().find(".")+3));
    info.append(" ");
    info.append(r->getWidth().substr(0, r->getWidth().find(".")+3));
    info.append(")");
}
void SelectShapeVisitor::visitTriangle(Triangle* t) {
    info.append("Triangle (");
    info.append(t->getFirstVec().info());
    info.append(" ");
    info.append(t->getSecondVec().info());
    info.append(")");
}

std::string SelectShapeVisitor::getInfo() {
    return info;
}