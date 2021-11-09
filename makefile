.PHONY: clean test

TEST = test/ut_rectangle.h test/ut_circle.h test/ut_triangle.h \
	  test/ut_two_dimensional_vector.h test/ut_compound_shape.h test/ut_iterator.h \
	  test/ut_utility.h test/ut_visitor.h

SHAPE = src/shape.h src/rectangle.h src/circle.h src/triangle.h \
	   src/two_dimensional_vector.h src/compound_shape.h src/utility.h

ITERATOR = src/iterator/iterator.h src/iterator/null_iterator.h src/iterator/compound_iterator.h

OBJ = obj/shape_visitor.o

SRC = $(SHAPE) $(ITERATOR)

bin/ut_all: test/ut_main.cpp $(TEST) $(SRC) $(OBJ)
	g++ -std=c++11 test/ut_main.cpp $(OBJ) -o bin/ut_all -lgtest -lpthread

obj/shape_visitor.o: src/shape_visitor.cpp src/shape_visitor.h
	g++ -std=c++11 -Wfatal-errors -Wall -c src/shape_visitor.cpp -o obj/shape_visitor.o

clean:
	rm -rf bin/ut_all obj/shape_visitor.os
