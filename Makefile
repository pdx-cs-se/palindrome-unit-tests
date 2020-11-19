CPP = g++
FLAGS = -Werror -Wall -g -std=c++11 -I/usr/include 
LIBS = -lgtest -lgtest_main -pthread

tests: tests.cpp palindrome.cpp
	$(CPP) $(FLAGS) -o tests tests.cpp $(LIBS)

test: tests
	./tests

clean:
	-rm -f tests
