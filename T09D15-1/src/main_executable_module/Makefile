CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
DATA_LIBS=../data_libs
DATA_MODULE=../data_module
YET_DECISION=../yet_another_decision_module
BUILD=../../build

all: main

main: main_executable_module.o data_stat.o data_io.o data_process.o decision.o
	$(CC) $(CFLAGS) main_executable_module.o data_stat.o data_io.o data_process.o decision.o -o $(BUILD)/Quest_3

main_executable_module.o: main_executable_module.c $(DATA_LIBS)/data_stat.h $(DATA_LIBS)/data_io.h $(DATA_MODULE)/data_process.h $(YET_DECISION)/decision.h
	$(CC) -c main_executable_module.c

data_stat.o: $(DATA_LIBS)/data_stat.c $(DATA_LIBS)/data_stat.h
	$(CC) -c $(DATA_LIBS)/data_stat.c

data_io.o: $(DATA_LIBS)/data_io.c $(DATA_LIBS)/data_io.h
	$(CC) -c $(DATA_LIBS)/data_io.c

data_process.o: $(DATA_MODULE)/data_process.c $(DATA_MODULE)/data_process.h $(DATA_LIBS)/data_stat.h
	$(CC) -c $(DATA_MODULE)/data_process.c

decision.o: $(YET_DECISION)/decision.c $(YET_DECISION)/decision.h $(DATA_LIBS)/data_stat.h
	$(CC) -c $(YET_DECISION)/decision.c

data_stat.a: data_stat.o
	ar r data_stat.a data_stat.o

build_with_static: main_executable_module.o data_stat.a data_io.o data_process.o decision.o
	$(CC) $(CFLAGS) main_executable_module.o data_stat.a data_io.o data_process.o decision.o -o $(BUILD)/Quest_5

data_process.so: data_process.o data_stat.o
	gcc -shared data_process.o data_stat.o -o data_process.so

build_with_dynamic: main_executable_module.o data_stat.a data_io.o data_process.so decision.o
	$(CC) $(CFLAGS) main_executable_module.o data_stat.a data_io.o data_process.so decision.o -o $(BUILD)/Quest_6
	cp data_process.so $(BUILD)/

rebuild: clean all

clean:
	rm -f *.o *.a $(BUILD)/*.so
	rm $(BUILD)/Quest_*