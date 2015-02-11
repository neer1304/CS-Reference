CC=gcc
CFLAGS=-c -Wall -g
FLAG=-o
SRC=../src/
BIN=../bin/
OBJ=../obj/
VFLAGS:valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

$(BIN)clfmk: $(OBJ)clientfifo.o
	$(CC) $(OBJ)clientfifo.o $(FLAG) $(BIN)clfmk

$(BIN)srfmk: $(OBJ)serverfifo.o
	$(CC) $(OBJ)serverfifo.o $(FLAG) $(BIN)srfmk

$(OBJ)clientfifo.o: $(SRC)clientfifo.c
	$(CC) $(CFLAGS) $(SRC)clientfifo.c $(FLAG) $(OBJ)clientfifo.o

$(OBJ)serverfifo.o: $(SRC)serverfifo.c
	$(CC) $(CFLAGS) $(SRC)serverfifo.c $(FLAG) $(OBJ)serverfifo.o

run: $(BIN)clfmk $(BIN)srfmk
	
valgrind: $(BIN)clfmk
	$(VFLAGS) ./$(BIN)clfmk

valgrind1: $(BIN)srfmk
	$(VFLAGS) ./$(BIN)srfmk
