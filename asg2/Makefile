# store variables
CC = g++
CC_EXTENSION = -std=c++11
CFLAGS = -I. -Wall -c
EXEC = main
SOURCES.cpp = main.cpp Quiz.cpp printResult.cpp
OBJECTS = $(SOURCES.cpp:.cpp=.o)

all: $(EXEC).out

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(CC_EXTENSION)

.c.o:
	$(CC) $(CFLAGS) -c $<

tidy:
	rm *.o $(EXEC)

run: $(EXEC)
	./$(EXEC).out

clean:
	rm *.o $(EXEC).out $(EXEC)

