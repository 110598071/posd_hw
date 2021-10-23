#pragma once

#include <string>
#include <stdexcept>

#include "./article.h"

class ListItem : public Article {
public:
    ListItem(std::string text) {
        _text = std::string("- ").append(text);
    }

    std::string getText() const override {
        return _text;
    }

    int getLevel() const override {return 0;}

    void add(Article* dpFormat) override {
        throw std::out_of_range("error");
    }

private:
    std::string _text;
};