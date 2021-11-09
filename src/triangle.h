#pragma once

#include "shape.h"
#include "two_dimensional_vector.h"
#include "./shape_visitor.h"

#include <cmath>
#include <stdexcept>

class Triangle: public Shape {
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) {
        if (vec1.x() != 0 && vec1.y() != 0 && vec2.x() != 0 && vec2.y() != 0) {
            if (vec1.y() / vec1.x() == vec2.y() / vec2.x()) {
                throw std::invalid_argument("parallel vector");
            }
            else {
                _vec1 = vec1;
                _vec2 = vec2;
            }
        }
        else if (vec1.x() == 0 || vec1.y() == 0 || vec2.x() == 0 || vec2.y() == 0) {
            if (vec1.x() == 0 && vec2.x() == 0) {
                throw std::invalid_argument("parallel vector");
            }
            else if (vec1.y() == 0 && vec2.y() == 0) {
                throw std::invalid_argument("parallel vector");
            }
            else if ((vec1.x() == 0 && vec1.y() == 0) || (vec2.x() == 0 && vec2.y() == 0)) {
                throw std::invalid_argument("invalid side");
            }
            else {
            _vec1 = vec1;
            _vec2 = vec2;
            }
        }
    }

    double area() const override {
        return fabs(_vec1.cross(_vec2))/2;
    }

    double perimeter() const override {
        double triangle_perimeter = 0;
        triangle_perimeter += _vec1.length();
        triangle_perimeter += _vec2.length();

        double _c = pow(_vec1.length(), 2) + pow(_vec2.length(), 2) - 2*_vec1.dot(_vec2);
        triangle_perimeter += sqrt(_c);
        return triangle_perimeter;
    }

    std::string info() const override {
        std::string _info = "Triangle (";
        _info.append(_vec1.info());
        _info.append(" ");
        _info.append(_vec2.info());
        _info.append(")");
        return _info;
    }

    Iterator* createIterator() override {
        return new NullIterator();
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitTriangle(this);
    }

    void accept(ShapeVisitor* visitor, int stage) override {}

    TwoDimensionalVector getFirstVec() {
        return _vec1;
    }

    TwoDimensionalVector getSecondVec() {
        return _vec2;
    }

private:
    TwoDimensionalVector _vec1;
    TwoDimensionalVector _vec2;
};
