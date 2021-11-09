#pragma once

#include <iterator>
#include <stdexcept>
#include "./iterator.h"
#include "../shape.h"

// you should define a template class or type `ForwardIterator`
template<class ForwardIterator>
class CompoundIterator : public Iterator{
public:
    CompoundIterator() {}

    CompoundIterator(ForwardIterator begin, ForwardIterator end) {
        begin_pos = begin;
        end_pos = end;
        move_pos = begin;
        current_shape = *begin_pos;
    }

    void first() override {
        current_shape = *begin_pos;
        move_pos = begin_pos;
    }

    Shape* currentItem() const override {
        if (current_shape == *end_pos) {
            throw std::out_of_range("error");
        }
        else{
            return current_shape;
        }
    }

    void next() override {
        if (current_shape == *end_pos) {
            throw std::out_of_range("error");
        }
        else {
            current_shape = *(++move_pos);
        }
    }

    bool isDone() const override {
        return current_shape == *end_pos;
    }
private:
    Shape* current_shape;
    ForwardIterator move_pos;
    ForwardIterator begin_pos;
    ForwardIterator end_pos;
};