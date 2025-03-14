CC = gcc
CFLAGS = -Wall -g -Wextra -I../exercice1
OBJS = exo1.o jpeg.o
BIN = jpeg

exe : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I../exercice1 -o $(BIN) -lm
	./jpeg

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

jpeg.o : jpeg.c
	$(CC) $(CFLAGS) -c jpeg.c

exo1.o : ../exercice1/exo1.c 
	$(CC) $(CFLAGS) -c -I../exercice1 ../exercice1/exo1.c

clean:
	rm -f $(BIN) *.o
