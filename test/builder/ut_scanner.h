#include "../../src/builder/scanner.h"

#include <iostream>

TEST(CaseScanner, nextShouldWorkCorrectly) {
    std::string input = "I Circle eee ,tt{t3.14159aCircle2a9999.9999";
    Scanner scanner(input);
    std::string first = scanner.next();
    std::string second = scanner.next();
    std::string third = scanner.next();
    std::string fourth = scanner.next();

    EXPECT_EQ(first, "Circle");
    EXPECT_EQ(second, ",");
    EXPECT_EQ(third, "{");
    EXPECT_EQ(fourth, "Circle");
}

TEST(CaseScanner, nextDoubleShouldWorkCorrectly) {
    std::string input = "I Circle eee ,tt{t3.14159aCircle2a9999.9999";
    Scanner scanner(input);
    double first = scanner.nextDouble();
    double second = scanner.nextDouble();
    double third = scanner.nextDouble();

    EXPECT_NEAR(first, 3.14159, 0.001);
    EXPECT_NEAR(second, 2, 0.001);
    EXPECT_NEAR(third, 9999.9999, 0.001);
}

TEST(CaseScanner, WholeScannerShouldWorkCorrectly) {
    std::string input = "I Circle eee ,tt{t3.14159aCircle2a9999.9999";
    Scanner scanner(input);

    std::string first = scanner.next();
    std::string second = scanner.next();
    std::string third = scanner.next();
    std::string fourth = scanner.next();
    double firstDouble = scanner.nextDouble();
    double secondDouble = scanner.nextDouble();
    double thirdDouble = scanner.nextDouble();

    EXPECT_EQ(first, "Circle");
    EXPECT_EQ(second, ",");
    EXPECT_EQ(third, "{");
    EXPECT_EQ(fourth, "Circle");
    EXPECT_NEAR(firstDouble, 3.14159, 0.001);
    EXPECT_NEAR(secondDouble, 2, 0.001);
    EXPECT_NEAR(thirdDouble, 9999.9999, 0.001);
}

TEST(CaseScanner, IsDoneShouldWorkCorrectly) {
    std::string input = "I Circle eee ,tt{t3.14159aCircle2a9999.9999";
    Scanner scanner(input);

    std::string first = scanner.next();
    std::string second = scanner.next();
    std::string third = scanner.next();
    std::string fourth = scanner.next();
    double firstDouble = scanner.nextDouble();
    double secondDouble = scanner.nextDouble();
    double thirdDouble = scanner.nextDouble();

    ASSERT_TRUE(scanner.isDone());
}

TEST(CaseScanner, NextShouldThrowExceptionWhenIsDone) {
    std::string input = "I Circle eee ,tt{t3.14159aCircle2a9999.9999";
    Scanner scanner(input);

    std::string first = scanner.next();
    std::string second = scanner.next();
    std::string third = scanner.next();
    std::string fourth = scanner.next();
    
    ASSERT_ANY_THROW(scanner.next());
}

TEST(CaseScanner, NextDoubleShouldThrowExceptionWhenIsDone) {
    std::string input = "I Circle eee ,tt{t3.14159aCircle2a9999.9999";
    Scanner scanner(input);

    double firstDouble = scanner.nextDouble();
    double secondDouble = scanner.nextDouble();
    double thirdDouble = scanner.nextDouble();
    
    ASSERT_ANY_THROW(scanner.nextDouble());
}

TEST(CaseScanner, ScanCircle) {
    std::string input = "Circle (1.0)";
    Scanner scanner(input);

    std::string firstToken = scanner.next();
    std::string secondToken = scanner.next();
    std::string thirdToken = scanner.next();
    double firstDouble = scanner.nextDouble();

    ASSERT_EQ(firstToken, "Circle");
    ASSERT_EQ(secondToken, "(");
    ASSERT_EQ(thirdToken, ")");

    ASSERT_NEAR(firstDouble, 1.0, 0.001);
    ASSERT_TRUE(scanner.isDone());
}

TEST(CaseScanner, ScanRectangle) {
    std::string input = "Rectangle (3.14, 4.00)";
    Scanner scanner(input);

    std::string firstToken = scanner.next();
    std::string secondToken = scanner.next();
    std::string thirdToken = scanner.next();
    std::string fourthToken = scanner.next();
    double firstDouble = scanner.nextDouble();
    double secondDouble = scanner.nextDouble();

    ASSERT_EQ(firstToken, "Rectangle");
    ASSERT_EQ(secondToken, "(");
    ASSERT_EQ(thirdToken, ",");
    ASSERT_EQ(fourthToken, ")");

    ASSERT_NEAR(firstDouble, 3.14, 0.001);
    ASSERT_NEAR(secondDouble, 4.00, 0.001);
    ASSERT_TRUE(scanner.isDone());
}

TEST(CaseScanner, ScanTriangle) {
    std::string input = "Triangle ([3, 0] [0.000, 4.0])";
    Scanner scanner(input);

    std::string firstToken = scanner.next();
    std::string secondToken = scanner.next();
    std::string thirdToken = scanner.next();
    std::string fourthToken = scanner.next();
    std::string fifthToken = scanner.next();
    std::string sixthToken = scanner.next();
    std::string seventhToken = scanner.next();
    std::string eighthToken = scanner.next();
    std::string ninethToken = scanner.next();
    double firstDouble = scanner.nextDouble();
    double secondDouble = scanner.nextDouble();
    double thirdDouble = scanner.nextDouble();
    double fourthDouble = scanner.nextDouble();

    ASSERT_EQ(firstToken, "Triangle");
    ASSERT_EQ(secondToken, "(");
    ASSERT_EQ(thirdToken, "[");
    ASSERT_EQ(fourthToken, ",");
    ASSERT_EQ(fifthToken, "]");
    ASSERT_EQ(sixthToken, "[");
    ASSERT_EQ(seventhToken, ",");
    ASSERT_EQ(eighthToken, "]");
    ASSERT_EQ(ninethToken, ")");

    ASSERT_NEAR(firstDouble, 3.00, 0.001);
    ASSERT_NEAR(secondDouble, 0, 0.001);
    ASSERT_NEAR(thirdDouble, 0, 0.001);
    ASSERT_NEAR(fourthDouble, 4.00, 0.001);
    ASSERT_TRUE(scanner.isDone());
}

TEST(CaseScanner, ScanEmptyCompound) {
    std::string input = "CompoundShape {}";
    Scanner scanner(input);

    std::string firstToken = scanner.next();
    std::string secondToken = scanner.next();
    std::string thirdToken = scanner.next();

    ASSERT_EQ(firstToken, "CompoundShape");
    ASSERT_EQ(secondToken, "{");
    ASSERT_EQ(thirdToken, "}");

    ASSERT_TRUE(scanner.isDone());
}

TEST(CaseScanner, ScanSimpleCompound) {
    std::string input = "CompoundShape {\n  Circle (1.0)\n  Rectangle (3.14 4.00)\n  Triangle ([3,0] [0,4])\n}";
    Scanner scanner(input);

    std::string firstToken = scanner.next();
    std::string secondToken = scanner.next();
    std::string thirdToken = scanner.next();
    std::string fourthToken = scanner.next();
    std::string fifthToken = scanner.next();
    std::string sixthToken = scanner.next();
    std::string seventhToken = scanner.next();
    std::string eighthToken = scanner.next();
    std::string ninethToken = scanner.next();
    std::string tenthToken = scanner.next();
    std::string eleventhToken = scanner.next();
    std::string twelfthToken = scanner.next();
    std::string thirteenthToken = scanner.next();
    std::string fourteenthToken = scanner.next();
    std::string fifteenthToken = scanner.next();
    std::string sixteenthToken = scanner.next();
    std::string seventeenthToken = scanner.next();
    std::string eighteenthToken = scanner.next();

    double firstDouble = scanner.nextDouble();
    double secondDouble = scanner.nextDouble();
    double thirdDouble = scanner.nextDouble();
    double fourthDouble = scanner.nextDouble();
    double fifthDouble = scanner.nextDouble();
    double sixthDouble = scanner.nextDouble();
    double seventhDouble = scanner.nextDouble();

    ASSERT_EQ(firstToken, "CompoundShape");
    ASSERT_EQ(secondToken, "{");
    ASSERT_EQ(thirdToken, "Circle");
    ASSERT_EQ(fourthToken, "(");
    ASSERT_EQ(fifthToken, ")");
    ASSERT_EQ(sixthToken, "Rectangle");
    ASSERT_EQ(seventhToken, "(");
    ASSERT_EQ(eighthToken, ")");
    ASSERT_EQ(ninethToken, "Triangle");
    ASSERT_EQ(tenthToken, "(");
    ASSERT_EQ(eleventhToken, "[");
    ASSERT_EQ(twelfthToken, ",");
    ASSERT_EQ(thirteenthToken, "]");
    ASSERT_EQ(fourteenthToken, "[");
    ASSERT_EQ(fifteenthToken, ",");
    ASSERT_EQ(sixteenthToken, "]");
    ASSERT_EQ(seventeenthToken, ")");
    ASSERT_EQ(eighteenthToken, "}");

    ASSERT_NEAR(firstDouble, 1.00, 0.001);
    ASSERT_NEAR(secondDouble, 3.14, 0.001);
    ASSERT_NEAR(thirdDouble, 4, 0.001);
    ASSERT_NEAR(fourthDouble, 3.00, 0.001);
    ASSERT_NEAR(fifthDouble, 0, 0.001);
    ASSERT_NEAR(sixthDouble, 0, 0.001);
    ASSERT_NEAR(seventhDouble, 4.00, 0.001);

    ASSERT_TRUE(scanner.isDone());
}

TEST(CaseScanner, ScanComplexCompound) {
    std::string input = "CompoundShape {\n  Circle (1.0)\n  Triangle ([3,0] [0,4])\n  CompoundShape {\n    Circle (1.0)\n    Rectangle (3.14 4.00)\n    Triangle ([3,0] [0,4])\n  }\n  Rectangle (3.14 4.00)\n}";
    Scanner scanner(input);

    for (int i=0; i<36; i++) {
        std::string Token = scanner.next();
    }
    for (int j=0; j<14; j++) {
        double Double = scanner.nextDouble();
    }

    ASSERT_TRUE(scanner.isDone());
}