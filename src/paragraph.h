#pragma once

#include <string>
#include <stdexcept>

#include "./article.h"

class Paragraph : public Article {
public:
    Paragraph(int level, std::string text) {
        if (level <= 0 || level > 6) {
            throw std::out_of_range("error");
        }
        else {
            _level = level;
        }

        _text = "";
        for (int i=0; i<level; i++) {
            _text.append("#");
        }
        _text.append(std::string(" "));
        _text.append(text);
        _text.append("\n");
    }

    ~Paragraph() {}

    std::string getText() const override {
        return _text;
    }

    int getLevel() const override {
        return _level;
    }

    void add(Article* content) override {
        if (content->getLevel() > _level || content->getLevel() == 0) {
            if (_text.at(_text.length()-1) == '\n') {
                _text.append(content->getText());
            }
            else {
                _text.append("\n");
                _text.append(content->getText());
            }
        }
        else {
            throw std::out_of_range("error");
        }
    }

private:
    int _level;
    std::string _text;
};