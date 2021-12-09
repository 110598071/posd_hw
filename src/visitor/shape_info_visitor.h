#pragma once

#include <string>

#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"
#include "../iterator/compound_iterator.h"

class ShapeInfoVisitor : public ShapeVisitor {
    public:
        void visitCircle(Circle* circle) {
            result.append(circle->info());
            result.append("\n");
        }

        void visitRectangle(Rectangle* rectangle) {
            result.append(rectangle->info());
            result.append("\n");
        }

        void visitTriangle(Triangle* triangle) {
            result.append(triangle->info());
            result.append("\n");
        }

        void visitCompoundShape(CompoundShape* compoundShape) {
            depth += 1;

            result.append(compoundShape->info());
            result.append(" {\n");

            Iterator* it = compoundShape->createIterator();
            while (!it->isDone()){
                for (int i=1; i<=depth; i++){
                    result.append("  ");
                }

                it->currentItem()->accept(this);

                it->next();
            }

            for (int i=1; i<depth; i++){
                result.append("  ");
            }
            result.append("}\n");

            depth -= 1;
        }

        std::string getResult() {
            return result;
        }

    private:
        int depth = 0;
        std::string result = "";
};