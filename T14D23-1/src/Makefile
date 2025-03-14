CC=gcc
BUILD_DIR=../build
CFLAGS=-Wall -Wextra -Werror

all: cipher logging_cipher

cipher: cipher.o
	$(CC) $(CFLAGS) cipher.o -o $(BUILD_DIR)/cipher

cipher.o: cipher.h cipher.c
	$(CC) $(CFLAGS) -c cipher.c -o cipher.o

logging_cipher: cipher.c logger.c
	$(CC) $(CFLAGS) -D LOG cipher.c logger.c -o $(BUILD_DIR)/logging_cipher

rebuild: clean all

clean:
	rm -f ../build/cipher
	rm -f ../build/logging_cipher
	rm -f *.o