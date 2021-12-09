#pragma once

#include <cmath>
#include <stdexcept>

#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./visitor/shape_visitor.h"

class Circle : public Shape {
    public:
        Circle(double radius) {
            if (radius <= 0) {
                throw std::out_of_range("out of range");
            }
            else {
                _radius = radius;
            }
        }

        double area() const override {
            return _radius * _radius * M_PI;
        }

        double perimeter() const override {
            return 2*M_PI*_radius;
        }

        std::string info() const override {
            // std::string info_radius = std::to_string(_radius);

            // std::string _info = "Circle (";
            // _info.append(info_radius.substr(0, info_radius.find(".")+3));
            // _info.append(")");

            char _info[50];
            sprintf(_info, "Circle (%.2lf)", _radius);
            return _info;
        }

        Iterator* createIterator() override {
            return new NullIterator();
        }

        void accept(ShapeVisitor* visitor) override {
            visitor->visitCircle(this);
        }

    private:
        double _radius;
};