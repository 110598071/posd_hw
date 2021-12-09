#pragma once

#include <iostream>
#include <stdexcept>

#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./visitor/shape_visitor.h"

class Rectangle : public Shape {
    public:
        Rectangle(double length, double width) {
            if (length <= 0 || width <= 0) {
                throw std::out_of_range("out of range");
            }
            else {
                _length = length;
                _width = width;
            }
        }

        double area() const override {
            return _length * _width;
        }

        double perimeter() const override {
            return _length*2 + _width*2;
        }
        
        std::string info() const override {
            std::string info_length = std::to_string(_length);
            std::string info_width = std::to_string(_width);

            std::string _info = "Rectangle (";
            _info.append(info_length.substr(0, info_length.find(".")+3));
            _info.append(" ");
            _info.append(info_width.substr(0, info_width.find(".")+3));
            _info.append(")");
            return _info;
        }

        Iterator* createIterator() override {
            return new NullIterator();
        }

        void accept(ShapeVisitor* visitor) override {
            visitor->visitRectangle(this);
        }

    private:
        double _length, _width;
};