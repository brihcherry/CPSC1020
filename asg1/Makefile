# store variables
CC = g++
CFLAGS = -I. -Wall -c
EXEC = main
OBJECTS = main.o Date.o calcDays.o
EXTENSION = --std=c++11

all: $(EXEC).out

run: $(EXEC)
	./$(EXEC).out

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) 

.c.o:
	$(CC) $(CFLAGS) -c $< 

# list dependencies for object files
Date.o: Date.cpp Date.h
calcDays.o: calcDays.cpp calcDays.h

tidy:
	rm *.o $(EXEC)

clean:
	rm *.o $(EXEC).out $(EXEC)
