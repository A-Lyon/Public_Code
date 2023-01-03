
CC = g++

CFLAGS = -Wall -g

TARGET = link

link: main.o ll.o
	$(CC) $(CFLAGS) main.o ll.o -o link 
 
# The main.o target can be written more simply
 
main.o: main.cc ll.h
	$(CC) $(CFLAGS) -c main.cc
 
ll.o: ll.cc ll.h
	$(CXX) $(CXXFLAGS) -c ll.cc 

clean:
	-rm -f link *.o
 