all: main test

test: AVLNode.o test.o
	g++ test.o AVLNode.o -o test

main: AVLNode.o main.o
	g++ main.o AVLNode.o -o main

test.o: test.cpp
	g++ -c test.cpp

main.o: main.cpp
	g++ -c main.cpp

AVLNode.o: AVLNode.cpp
	g++ -c AVLNode.cpp

clean:
	rm -rf *.o main test
