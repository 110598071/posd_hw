#pragma once

#include "./shape.h"
#include "./compound_shape.h"
#include "./iterator/iterator.h"

#include <iterator>
#include <list>
#include <stdexcept>
#include <typeinfo>

template<class ShapeConstraint>
// you should define a template class or type `ShapeConstraint`
Shape* selectShape(Shape* shape, ShapeConstraint constraint) {
    Iterator* it = shape->createIterator();
    Shape* result = nullptr;
    for (it->first(); !it->isDone(); it->next()) {
        if (constraint(it->currentItem())) {
            result = it->currentItem();
            break;
        }
    }
    delete it;
    return result;
}