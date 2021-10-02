CC = g++ -std=c++11

assign1_app: catalog.o prog.o
	$(CC) catalog.o prog.o -o assign1_app
catalog.o: catalog.cpp
	$(CC) -c catalog.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm -f *.out *.o assign1_app
.PHONY: clean