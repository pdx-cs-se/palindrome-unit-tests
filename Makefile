CPP = g++
FLAGS = -Werror -Wall -g -std=c++11 -I/usr/include 
LIBS = -lgtest -lgtest_main -pthread

test: tests
	./tests

tests: tests.cpp
	$(CPP) $(FLAGS) -o tests tests.cpp $(LIBS)

clean:
	-rm -f tests
