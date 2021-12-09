#pragma once

#include <string>
#include <stdexcept>

class Iterator;
class ShapeVisitor;

class Shape {
   public:
    virtual ~Shape(){};

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    virtual Iterator* createIterator() = 0;

    virtual void accept(ShapeVisitor* visitor) = 0;

    virtual void addShape(Shape* shape) { throw std::out_of_range("error"); }

    virtual void deleteShape(Shape* shape) { throw std::out_of_range("error"); }
};