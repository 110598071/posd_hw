#pragma once

#include <stack>
#include <list>

#include "../shape.h"
#include "../circle.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "../two_dimensional_vector.h"
#include "../compound_shape.h"

class ShapeBuilder {
    public:
        void buildCircle(double radius) {
            _shapes.push(new Circle(radius));
        }

        void buildRectangle(double length, double width) {
            _shapes.push(new Rectangle(length, width));
        }

        void buildTriangle(double x1, double y1, double x2, double y2) {
            TwoDimensionalVector t1(x1, y1);
            TwoDimensionalVector t2(x2, y2);
            _shapes.push(new Triangle(t1, t2));
        }

        void buildCompoundBegin() {
            _shapes.push(new CompoundShape());
        }

        void buildCompoundEnd() {
            std::list<Shape*> components;
            // while (typeid(*_shapes.top()) != typeid(CompoundShape) || 
            //     (typeid(*_shapes.top()) == typeid(CompoundShape) && !_shapes.top()->createIterator()->isDone())){
            //     components.push_back(_shapes.top());
            //     _shapes.pop();
            // }

            while (!(typeid(*_shapes.top()) == typeid(CompoundShape) && _shapes.top()->createIterator()->isDone())){
                components.push_back(_shapes.top());
                _shapes.pop();
            }
            Shape* compound = _shapes.top();

            for (auto it = components.rbegin(); it != components.rend(); it++) {
                compound->addShape(*it);
            }
        }

        Shape* getShape() {
            return _shapes.top();
        }

    private:
        Shape* _result;
        std::stack<Shape*> _shapes;
};