CC = g++ -std=c++11

assign4_app: event.o room.o bats.o pit.o gold.o wumpus.o rope.o game.o driver.o
	$(CC) event.o room.o bats.o pit.o gold.o wumpus.o rope.o game.o driver.o -o assign4_app
event.o:
	$(CC) -c event.cpp
room.o: room.cpp
	$(CC) -c room.cpp
bats.o: bats.cpp
	$(CC) -c bats.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
rope.o: rope.cpp
	$(CC) -c rope.cpp
game.o: game.cpp
	$(CC) -c game.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o assign4_app
.PHONY: clean