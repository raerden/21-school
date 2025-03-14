CC=gcc
BUILD_DIR=../build
CFLAGS=-Wall -Wextra -Werror

all: clean main

main: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o

s21_strlen_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -D STRLEN s21_string_test.c -o s21_strlen_test.o

strlen_tests: s21_string.o s21_strlen_test.o
	$(CC) $(CFLAGS) s21_string.o s21_strlen_test.o -o $(BUILD_DIR)/Quest_1


s21_strcmp_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -D STRCMP s21_string_test.c -o s21_strcmp_test.o

strcmp_tests: s21_string.o s21_strcmp_test.o
	$(CC) $(CFLAGS) s21_string.o s21_strcmp_test.o -o $(BUILD_DIR)/Quest_2


s21_strcpy_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -D STRCPY s21_string_test.c -o s21_strcpy_test.o

strcpy_tests: s21_string.o s21_strcpy_test.o
	$(CC) $(CFLAGS) s21_string.o s21_strcpy_test.o -o $(BUILD_DIR)/Quest_3


s21_strcat_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -D STRCAT s21_string_test.c -o s21_strcat_test.o

strcat_tests: s21_string.o s21_strcat_test.o
	$(CC) $(CFLAGS) s21_string.o s21_strcat_test.o -o $(BUILD_DIR)/Quest_4


s21_strchr_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -D STRCHR s21_string_test.c -o s21_strchr_test.o

strchr_tests: s21_string.o s21_strchr_test.o
	$(CC) $(CFLAGS) s21_string.o s21_strchr_test.o -o $(BUILD_DIR)/Quest_5



rebuild: clean main

clean:
	rm -f *.o || true
	rm -f $(BUILD_DIR)/Quest_* || true