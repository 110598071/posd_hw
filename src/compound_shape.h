#pragma once

#include <list>
#include <string>
#include <iterator>
#include <stdexcept>
#include <iostream>

#include "./shape.h"
#include "./iterator/iterator.h"
#include "./iterator/compound_iterator.h"
#include "./visitor/shape_visitor.h"

class CompoundShape : public Shape {
    public:
        ~CompoundShape() {
            // for (std::list<Shape*>::const_iterator it = shapes_list.begin(); it != shapes_list.end(); ++it) {
            //     delete *it;
            // }
        }

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
            // std::string _info = "CompoundShape\n{\n";
            // for (std::list<Shape*>::const_iterator it = shapes_list.begin(); it != shapes_list.end(); ++it) {
            //     _info.append((*it)->info());
            //     _info.append("\n");
            // }
            // _info.append("}");
            // return _info;

            std::string _info = "CompoundShape";
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
            Iterator* it = this->createIterator();

            while (!it->isDone()) {
                if (typeid(*(it->currentItem())).name() == std::string("13CompoundShape")) {
                    it->currentItem()->deleteShape(shape);
                }
                else {
                    if (it->currentItem() == shape) {
                        shape_remove = true;
                    }
                }
                it->next();
            }
            if (shape_remove) {
                shapes_list.remove(shape);
            }
        }

        void accept(ShapeVisitor* visitor) override {
            visitor->visitCompoundShape(this);
        }

    private:
        int _count;
        std::list<Shape*> shapes_list;
};