#pragma once

#include <string>
#include <stdexcept>

#include "./article.h"

class Text : public Article {
public:
    Text(std::string text) {
        _text = text;
    }

    std::string getText() const override{
        return _text;
    }

    int getLevel() const override {return 0;}

    void add(Article* dpFormat) override {
        throw std::out_of_range("error");
    }

private:
    std::string _text;
};