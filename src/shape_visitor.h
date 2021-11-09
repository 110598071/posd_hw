#pragma once

#include <string>

class CompoundShape;
class Circle;
class Rectangle;
class Triangle;

class ShapeVisitor {
    public:
        ShapeVisitor(){}
        virtual ~ShapeVisitor(){}
        virtual void visitCompoundShape(CompoundShape* cs, int stage) = 0;
        virtual void visitCircle(Circle* c) = 0;
        virtual void visitRectangle(Rectangle* r) = 0;
        virtual void visitTriangle(Triangle* t) = 0;
        virtual std::string getInfo() = 0;
};

class SelectShapeVisitor: public ShapeVisitor {
    public:
        SelectShapeVisitor(){}
        void visitCompoundShape(CompoundShape* cs, int stage);
        void visitCircle(Circle* c);
        void visitRectangle(Rectangle* r);
        void visitTriangle(Triangle* t);
        std::string getInfo(); 
    private:
        std::string info;
};