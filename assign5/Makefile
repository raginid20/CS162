CC = g++ -std=c++11

assign5_app: node.o list.o driver.o
	$(CC) node.o list.o driver.o -o assign5_app
node.o: node.cpp
	$(CC) -c node.cpp
list.o: list.cpp
	$(CC) -c list.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o assign5_app
.PHONY: clean