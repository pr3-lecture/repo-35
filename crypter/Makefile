.PHONY: all clean
all: decrypt encrypt
clean:
	rm -f main.o decrypt encrypt crypto.o
main.o: main.c
	gcc -Wall -c main.c
crypto.o: crypto.c
	gcc -Wall -c crypto.c
decrypt: main.o crypto.o
	gcc -o decrypt main.o crypto.o
encrypt: main.o crypto
	gcc -o encrypt main.o crypto.o
