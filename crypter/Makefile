.PHONY: all clean
all: crypter
clean:
	rm -f main.o crypter
main.o: main.c
	cc -Wall -c main.c
decrypt: main.o
	cc -o decrypt main.o
encrypt:
	cc -o encrypt main.o
