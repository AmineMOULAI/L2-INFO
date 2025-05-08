CC = gcc
CFLAGS = -Wall -g -Wextra -I../../TD1/exercice1 -I../../TD1/exercice2 
OBJS = main.o exo1.o transformation.o exo2.o
BIN = main.exe


all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN) -lm

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

transformation.o: transformation.c
	$(CC) $(CFLAGS) -c transformation.c -o transformation.o

exo1.o: ../../TD1/exercice1/exo1.c
	$(CC) $(CFLAGS) -c -I../../TD1/exercice1 ../../TD1/exercice1/exo1.c -o exo1.o

exo2.o: ../../TD1/exercice2/exo2.c
	$(CC) $(CFLAGS) -c -I../../TD1/exercice2 ../../TD1/exercice2/exo2.c -o exo2.o

clean:
	rm -f $(BIN) *.o

run: all
	./$(BIN)