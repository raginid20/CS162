CC = g++ -std=c++11

assign2_app: deck.o prog.o player.o
	$(CC) deck.o prog.o player.o -o assign2_app
deck.o: deck.cpp
	$(CC) -c deck.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
player.o: player.cpp
	$(CC) -c player.cpp
clean:
	rm -f *.out *.o assign2_app
.PHONY: clean