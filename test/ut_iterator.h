#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/iterator/iterator.h"
#include <stdexcept>

TEST(CaseIterator, CreationNullIterator) {
    Shape* c = new Circle(1.0);
    ASSERT_NO_THROW(Iterator* it = c->createIterator());
    delete c;
}

TEST(CaseIterator, NullIteratorFirst) {
    Shape* c = new Circle(1.0);
    Iterator* it = c->createIterator();
    ASSERT_THROW(it->first(), std::out_of_range);
    delete c;
    delete it;
}

TEST(CaseIterator, NullIteratorCurrentItem) {
    Shape* c = new Circle(1.0);
    Iterator* it = c->createIterator();
    ASSERT_THROW(it->currentItem(), std::out_of_range);
    delete c;
    delete it;
}

TEST(CaseIterator, NullIteratorNext) {
    Shape* c = new Circle(1.0);
    Iterator* it = c->createIterator();
    ASSERT_THROW(it->next(), std::out_of_range);
    delete c;
    delete it;
}

TEST(CaseIterator, NullIteratorisDone) {
    Shape* c = new Circle(1.0);
    Iterator* it = c->createIterator();
    ASSERT_TRUE(it->isDone());
    delete c;
    delete it;
}

TEST(CaseIterator, CreateCompoundIterator) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* r = new Rectangle(5.0, 3.0);

    Shape* shapes[3] = {c1, c2, r};
    CompoundShape cs(shapes,3);

    ASSERT_NO_THROW(Iterator* it = cs.createIterator());

    delete c1;
    delete c2;
    delete r;
}

TEST(CaseIterator, CompoundIteratorFirst) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* r = new Rectangle(5.0, 3.0);

    Shape* shapes[3] = {c1, c2, r};
    CompoundShape cs(shapes,3);

    Iterator* it = cs.createIterator();
    ASSERT_NO_THROW(it->first());

    delete c1;
    delete c2;
    delete r;
    delete it;
}

TEST(CaseIterator, CompoundIteratorCurrentItem) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* r = new Rectangle(5.0, 3.0);

    Shape* shapes[3] = {c1, c2, r};
    CompoundShape cs(shapes,3);

    Iterator* it = cs.createIterator();
    ASSERT_EQ(c1, it->currentItem());

    delete c1;
    delete c2;
    delete r;
    delete it;
}

TEST(CaseIterator, CompoundIteratorFirstAfterNextShouldBeCorrect) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* r = new Rectangle(5.0, 3.0);

    Shape* shapes[3] = {c1, c2, r};
    CompoundShape cs(shapes,3);

    Iterator* it = cs.createIterator();
    it->next();
    it->next();
    it->first();
    ASSERT_EQ(c1, it->currentItem());

    delete c1;
    delete c2;
    delete r;
    delete it;
}

TEST(CaseIterator, CompoundIteratorNext) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* r = new Rectangle(5.0, 3.0);

    Shape* shapes[3] = {c1, c2, r};
    CompoundShape cs(shapes,3);

    Iterator* it = cs.createIterator();
    it->first();
    it->next();
    ASSERT_EQ(c2, it->currentItem());

    delete c1;
    delete c2;
    delete r;
    delete it;
}

TEST(CaseIterator, CompoundIteratorIsDone) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* r = new Rectangle(5.0, 3.0);

    Shape* shapes[3] = {c1, c2, r};
    CompoundShape cs(shapes,3);

    Iterator* it = cs.createIterator();
    it->first();
    it->next();
    it->next();
    it->next();
    ASSERT_TRUE(it->isDone());

    delete c1;
    delete c2;
    delete r;
    delete it;
}

TEST(CaseIterator, CompoundIteratorCurrentItemShouldThrowExceptionWhenIsDone) {
    Shape* c = new Circle(1.0);

    Shape* shapes[1] = {c};
    CompoundShape cs(shapes,1);

    Iterator* it = cs.createIterator();
    it->next();
    ASSERT_THROW(it->currentItem(), std::out_of_range);

    delete c;
    delete it;
}

TEST(CaseIterator, CompoundIteratorNextShouldThrowExceptionWhenIsDone) {
    Shape* c = new Circle(1.0);

    Shape* shapes[1] = {c};
    CompoundShape cs(shapes,1);

    Iterator* it = cs.createIterator();
    it->next();
    ASSERT_THROW(it->next(), std::out_of_range);

    delete c;
    delete it;
}