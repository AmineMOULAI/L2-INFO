CC = gcc
CFLAGS = -Wall -g -Wextra -I.


exe : 
	$(CC) $(CFLAGS) jpeg.c -I../exercice1 -o jpeg
	./jpeg

exo1.o : exo1.c 
	$(CC) $(CFLAGS) -c -I../exercice1
clean:
	rm -f jpeg
