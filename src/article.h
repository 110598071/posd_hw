#pragma once
#include <string>

class Article {
   public:
    virtual ~Article(){};

    virtual std::string getText() const {
        return std::string("k");
    }

    virtual int getLevel() const {return 0;}

    virtual void add(Article* dpFormat){};
};