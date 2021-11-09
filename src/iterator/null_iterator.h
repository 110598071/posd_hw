#pragma once

#include "./iterator.h"
#include <stdexcept>

class NullIterator : public Iterator {
    public:
        NullIterator() {}

        void first() override {
            throw std::out_of_range("error");
        }

        Shape* currentItem() const override {
            throw std::out_of_range("error");
        }

        void next() override {
            throw std::out_of_range("error");
        }

        bool isDone() const override {
            return true;
        }
};