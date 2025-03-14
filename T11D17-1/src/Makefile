CC=gcc
BUILD_DIR=../build
CFLAGS=-Wall -Wextra -Werror


all: door_struct list_test

door_struct: door_struct.h dmanager_module.c
	$(CC) $(CFLAGS) dmanager_module.c -o $(BUILD_DIR)/Quest_1

list_test: door_struct.h list.h list.c list_test.c
	$(CC) $(CFLAGS) list.c list_test.c -o $(BUILD_DIR)/Quest_2

rebuild: clean all

clean:
	rm -f *.o || true
	rm -f ../build/Quest_*