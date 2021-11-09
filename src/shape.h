#pragma once

#include <stdexcept>
#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include "./shape_visitor.h"

class Shape {
public:
    virtual ~Shape() {};

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    virtual Iterator* createIterator() = 0;

    virtual void accept(ShapeVisitor* visitor) = 0;

    virtual void accept(ShapeVisitor* visitor, int stage) = 0;

    virtual void addShape(Shape* shape) {
        throw std::out_of_range("error");
    }

    virtual void deleteShape(Shape* shape) {
        throw std::out_of_range("error");
    }
};