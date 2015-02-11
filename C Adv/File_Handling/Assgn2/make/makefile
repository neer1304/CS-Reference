CC=gcc
CFLAGS=-c -Wall -g
VFLAGS=valgrind --tool=memcheck --leak-check=yes --show-reachable=yes
DFLAGS=-DERROR -DTRACE
FLAGS=-o
INCLUDE=-I../include/
HEADER=../include/
OBJ=../obj/
SRC=../src/
OUTPUT=../bin/

$(OUTPUT)strucbf : $(OBJ)main.o $(OBJ)functions.o 
	$(CC) $(OBJ)main.o $(OBJ)functions.o $(FLAGS) $(OUTPUT)structbf

$(OBJ)main.o: $(SRC)main.c $(HEADER)header.h
	$(CC) $(CFLAGS) $(SRC)main.c $(INCLUDE) $(FLAGS) $(OBJ)main.o

$(OBJ)functions.o: $(SRC)functions.c $(HEADER)header.h
	$(CC) $(CFLAGS) $(SRC)functions.c $(INCLUDE) $(FLAGS) $(OBJ)functions.o

valgrind: $(OUTPUT)structbf
	$(VFLAGS) ./$(OUTPUT)structbf

clean:
	rm $(OBJ)*.o
	rm $(OUTPUT)structbf


