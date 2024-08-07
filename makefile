run: main
	./main

main: main.o nextfit.o
	g++ main.o nextfit.o -o main

main.o: main.cpp
	g++ -c main.cpp

nextfit.o: nextfit.cpp nextfit.hpp
	g++ -c nextfit.cpp

clean:
	rm *.o main