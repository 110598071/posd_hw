#include "../../src/builder/shape_parser.h"
#include "../../src/shape.h"

#include <string>

TEST(CaseParser, ParseCircle) {
    std::string filePath = "./test/data/circle.txt";
    ShapeParser* parser = new ShapeParser(filePath);
    parser->parse();
    Shape* result = parser->getShape();

    ASSERT_NEAR(1*1*M_PI, result->area(), 0.01);

    delete parser;
    delete result;
}

TEST(CaseParser, ParseRectangle) {
    std::string filePath = "./test/data/rectangle.txt";
    ShapeParser* parser = new ShapeParser(filePath);
    parser->parse();
    Shape* result = parser->getShape();

    ASSERT_NEAR(3.14 * 4, result->area(), 0.01);

    delete parser;
    delete result;
}

TEST(CaseParser, ParseTriangle) {
    std::string filePath = "./test/data/triangle.txt";
    ShapeParser* parser = new ShapeParser(filePath);
    parser->parse();
    Shape* result = parser->getShape();

    ASSERT_NEAR(6, result->area(), 0.01);

    delete parser;
    delete result;
}

TEST(CaseParser, ParseEmptyCompound) {
    std::string filePath = "./test/data/empty_compound.txt";
    ShapeParser* parser = new ShapeParser(filePath);
    parser->parse();
    Shape* result = parser->getShape();

    ASSERT_NEAR(0, result->area(), 0.01);

    delete parser;
    delete result;
}

TEST(CaseParser, ParseSimpleCompound) {
    std::string filePath = "./test/data/simple_compound.txt";
    ShapeParser* parser = new ShapeParser(filePath);
    parser->parse();
    Shape* result = parser->getShape();

    Iterator* it = result->createIterator();

    EXPECT_NEAR(1*1*M_PI, it->currentItem()->area(), 0.01);

    it->next();
    EXPECT_NEAR(3.14 * 4, it->currentItem()->area(), 0.01);

    it->next();
    EXPECT_NEAR(6, it->currentItem()->area(), 0.01);

    it->next();
    EXPECT_TRUE(it->isDone());

    delete parser;
    delete result;
    delete it;
}

TEST(CaseParser, ParseComplexCompound) {
    std::string filePath = "./test/data/complex_compound.txt";
    ShapeParser* parser = new ShapeParser(filePath);

    // Scanner* _scanner = parser->getScanner();
    // _scanner->printTest();

    parser->parse();
    Shape* result = parser->getShape();

    Iterator* it = result->createIterator();
    EXPECT_NEAR(1*1*M_PI, it->currentItem()->area(), 0.01);

    it->next();
    EXPECT_NEAR(6, it->currentItem()->area(), 0.01);

    it->next();
    EXPECT_NEAR(1*1*M_PI + 3.14 * 4 + 6, it->currentItem()->area(), 0.01);

    it->next();
    EXPECT_NEAR(3.14 * 4, it->currentItem()->area(), 0.01);

    it->next();
    EXPECT_TRUE(it->isDone());

    delete parser;
    delete result;
    delete it;
}