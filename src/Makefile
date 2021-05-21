#FILES=main.c header_data.c decoder.c
FILES=main.c unpack/*
CC=gcc
CFLAGS=-g -Wall -Wextra -pendantic -std=gnu99

all:
	$(CC) -o doelhousedecoder $(FILES)
run:
	$(CC) -o doelhousedecoder $(FILES)
	./doelhousedecoder
clean:
	rm -rf doelhousedecoder

