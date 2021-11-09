#pragma once

#include "./shape.h"
#include "./utility.h"
#include "./iterator/iterator.h"
#include "./iterator/compound_iterator.h"
#include "./shape_visitor.h"

#include <list>
#include <string>
#include <iterator>
#include <stdexcept>
#include <iostream>

class CompoundShape : public Shape {
public:
    ~CompoundShape() { }
    CompoundShape() {}

    CompoundShape(Shape* shapes[], int count): _count(count) {
        for (int i = 0; i < _count; i++){
            shapes_list.push_back(shapes[i]);
        }
    };

    double area() const override {
        double result = 0;

        for (std::list<Shape*>::const_iterator it = shapes_list.begin(); it != shapes_list.end(); ++it) {
            result += (*it)->area();
        }
        return result;
    }

    double perimeter() const override {
        double result = 0;

        for (std::list<Shape*>::const_iterator it = shapes_list.begin(); it != shapes_list.end(); ++it) {
            result += (*it)->perimeter();
        }
        return result;
    }

    std::string info() const override {
        std::string _info = "CompoundShape\n{\n";
        for (std::list<Shape*>::const_iterator it = shapes_list.begin(); it != shapes_list.end(); ++it) {
            _info.append((*it)->info());
            _info.append("\n");
        }
        _info.append("}");
        return _info;
    }

    Iterator* createIterator() override {
        return new CompoundIterator<std::list<Shape*>::const_iterator>(shapes_list.begin(), shapes_list.end());
    }

    void addShape(Shape* shape) override {
        shapes_list.push_back(shape);
    }
    
    void deleteShape(Shape* shape) override {
        bool shape_remove = false;
        for (std::list<Shape*>::const_iterator it = shapes_list.begin(); it != shapes_list.end(); ++it) {
            if ((*it)->info() == shape->info()) {
                shape_remove = true;
            }
        }
        if (shape_remove) {
            shapes_list.remove(shape);
        }
        else {
            throw std::out_of_range("error");
        }
    }

    void accept(ShapeVisitor* visitor) override {}

    void accept(ShapeVisitor* visitor, int stage) override {
        visitor->visitCompoundShape(this, stage);
    }

private:
    int _count;
    std::list<Shape*> shapes_list;
};