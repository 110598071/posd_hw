#include "../../src/compound_shape.h"
#include "../../src/builder/shape_builder.h"

class CaseBuilder: public ::testing::Test {
    protected:
        const double delta = 0.001;
        ShapeBuilder* builder;

        void SetUp() override {
            builder = new ShapeBuilder();
        }

        void TearDown() override {
            delete builder;
        } 
};

TEST_F(CaseBuilder, BuildCircle) {
    builder->buildCircle(1.0);
    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI, result->area(), delta);
    delete result;
}

TEST_F(CaseBuilder, BuildRectangle) {
    builder->buildRectangle(3.0, 2.0);
    Shape* result = builder->getShape();

    ASSERT_NEAR(6, result->area(), delta);
    delete result;
}

TEST_F(CaseBuilder, BuildTriangle) {
    builder->buildTriangle(0, 4.0, 3.0, 0);
    Shape* result = builder->getShape();

    ASSERT_NEAR(6, result->area(), delta);
    delete result;
}

TEST_F(CaseBuilder, BuildEmptyCompound) {
    builder->buildCompoundBegin();
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(0, result->area(), delta);
    delete result;
}

TEST_F(CaseBuilder, BuildSimpleCompound) {
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();

    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, result->area(), delta);
    delete result;
}

TEST_F(CaseBuilder, BuildComplexCompound) {
    builder->buildCompoundBegin();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();
    builder->buildRectangle(3.0, 5.0);
    builder->buildCompoundEnd();

    Shape* result = builder->getShape();

    Iterator *it = result->createIterator();

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, it->currentItem()->area(), delta);

    it->next();
    ASSERT_NEAR(15, it->currentItem()->area(), delta);
    delete result;
}