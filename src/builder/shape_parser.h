#pragma once

#include "../shape.h"
#include "./shape_builder.h"
#include "./scanner.h"
#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class ShapeParser{
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath) {
        builder = new ShapeBuilder();

        std::ifstream ifs(filePath, std::ios::in);
        if (!ifs.is_open()) {
            std::cout << "Not Found" << std::endl;
        }

        std::stringstream ss;
        ss << ifs.rdbuf();
        std::string fileContent(ss.str());
        ifs.close();

        scanner = new Scanner(fileContent);
    }

    ~ShapeParser() {}

    void parse() {
        while (!scanner->isDone()) {
            std::string token = scanner->next();
            if (token == "Circle") {
                // ignorToken(2);
                builder->buildCircle(scanner->nextDouble());
            }
            else if (token == "Rectangle") {
                // ignorToken(2);
                builder->buildRectangle(scanner->nextDouble(), scanner->nextDouble());
            }
            else if (token == "Triangle") {
                // ignorToken(8);
                builder->buildTriangle(scanner->nextDouble(), scanner->nextDouble(), scanner->nextDouble(), scanner->nextDouble());
            }
            else if (token == "CompoundShape") {
                // ignorToken(1);
                builder->buildCompoundBegin();
            }
            else if (token == "}") {
                builder->buildCompoundEnd();
            }
        }
        result = builder->getShape();
    }

    Shape* getShape() {
        return result;
    }

    // Scanner* getScanner() {
    //     return scanner;
    // }

private:
    Shape* result;
    ShapeBuilder* builder;
    Scanner* scanner;

    // void ignorToken(int _count) {
    //     for (int i=0; i<_count; i++) {
    //         std::string _ignorToken = scanner->next();
    //     }
    // }
};
