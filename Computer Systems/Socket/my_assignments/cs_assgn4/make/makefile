CC=gcc
CFLAG=-c -Wall -g
FLAG=-o
SRC=../src/
OBJ=../obj/
BIN=../bin/
INCLUDE=-I../include/
HEADER=../include/
VFLAG=valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

$(BIN)conths: $(OBJ)conthserver.o
	$(CC) $(OBJ)conthserver.o $(FLAG) $(BIN)conths -lpthread

$(BIN)thcl: $(OBJ)thclient.o
	$(CC) $(OBJ)thclient.o $(FLAG) $(BIN)thcl 

$(OBJ)conthserver.o: $(SRC)conthserver.c $(HEADER)header.h
	$(CC) $(CFLAG) $(SRC)conthserver.c $(INCLUDE) $(FLAG) $(OBJ)conthserver.o

$(OBJ)thclient.o: $(SRC)thclient.c $(HEADER)header.h
	$(CC) $(CFLAG) $(SRC)thclient.c $(INCLUDE) $(FLAG) $(OBJ)thclient.o

clean:
	rm $(BIN)*
	rm $(OBJ)*

valgrind: $(BIN)conths
	$(VFLAG) $(BIN)conths

all: $(BIN)conths $(BIN)thcl

