CC = g++ -std=c++11

assign3_app: zoo.o animal.o lemur.o tiger.o blackbear.o game.o driver.o
	$(CC) zoo.o animal.o lemur.o tiger.o blackbear.o game.o driver.o -o assign3_app
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
animal.o: animal.cpp
	$(CC) -c animal.cpp
lemur.o: lemur.cpp
	$(CC) -c lemur.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
blackbear.o: blackbear.cpp
	$(CC) -c blackbear.cpp
game.o: game.cpp
	$(CC) -c game.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o assign3_app
.PHONY: clean