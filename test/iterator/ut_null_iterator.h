#include "../../src/compound_shape.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"
#include "../../src/iterator/iterator.h"
#include <stdexcept>

TEST(CaseNullIterator, CreationNullIterator) {
    Shape* c = new Circle(1.0);
    ASSERT_NO_THROW(Iterator* it = c->createIterator());
    delete c;
}

TEST(CaseNullIterator, NullIteratorFirst) {
    Shape* c = new Circle(1.0);
    Iterator* it = c->createIterator();
    ASSERT_THROW(it->first(), std::out_of_range);
    delete c;
    delete it;
}

TEST(CaseNullIterator, NullIteratorCurrentItem) {
    Shape* c = new Circle(1.0);
    Iterator* it = c->createIterator();
    ASSERT_THROW(it->currentItem(), std::out_of_range);
    delete c;
    delete it;
}

TEST(CaseNullIterator, NullIteratorNext) {
    Shape* c = new Circle(1.0);
    Iterator* it = c->createIterator();
    ASSERT_THROW(it->next(), std::out_of_range);
    delete c;
    delete it;
}

TEST(CaseNullIterator, NullIteratorisDone) {
    Shape* c = new Circle(1.0);
    Iterator* it = c->createIterator();
    ASSERT_TRUE(it->isDone());
    delete c;
    delete it;
}