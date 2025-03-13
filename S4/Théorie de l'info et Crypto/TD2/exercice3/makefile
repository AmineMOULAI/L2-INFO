CC = gcc
CFLAGS = -Wall -g -Wextra -I../exercice2
OBJS = exo2.o exo3.o
BIN = exo3

exe : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I../exercice2 -o $(BIN)
	@./exo3

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

exo3.o : exo3.c
	$(CC) $(CFLAGS) -c exo3.c

exo2.o : ../exercice2/exo2.c 
	$(CC) $(CFLAGS) -c -I../exercice2 ../exercice2/exo2.c

clean:
	rm -f $(BIN) *.o