all: main

main: main.o helper.o
	g++ main.o helper.o -o main

main.o: main.cpp main.h helper.h
	g++ -c main.cpp

helper.o: helper.cpp helper.h
	g++ -c helper.cpp

clean:
	rm -f *.o main
