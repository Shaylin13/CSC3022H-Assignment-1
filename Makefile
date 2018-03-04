CC=g++

main: main.o studentDB.o
	$(CC) main.o studentDB.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

database.o: studentDB.cpp studentDb.h
	$(CC) -c studentDB.cpp

clean:
	rm *.o main

run:
	make
	./main
