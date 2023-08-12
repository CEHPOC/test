all: main

main: AVLNode.o main.o
	g++ main.o AVLNode.o -o main

main.o: main.cpp
	g++ -c main.cpp

AVLNode.o: AVLNode.h AVLNode.cpp
	g++ -c AVLNode.h AVLNode.cpp

clean:
	rm -rf *.o main
