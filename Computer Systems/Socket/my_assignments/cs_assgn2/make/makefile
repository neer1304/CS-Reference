CC=gcc
CFLAG=-c -Wall -g
FLAG=-o
SRC=../src/
BIN=../bin/
OBJ=../obj/
HEADER=../include/
INCLUDE=-I../include/
VFLAG=valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

$(BIN)tsmk: $(OBJ)tsmk.o $(OBJ)functions.o
	$(CC) $(OBJ)tsmk.o $(OBJ)functions.o $(FLAG) $(BIN)tsmk

$(BIN)tcmk: $(OBJ)tcmk.o
	$(CC) $(OBJ)tcmk.o $(FLAG) $(BIN)tcmk

$(OBJ)tsmk.o: $(SRC)tcpserver.c $(HEADER)header.h
	$(CC) $(CFLAG) $(SRC)tcpserver.c $(INCLUDE) $(FLAG) $(OBJ)tsmk.o

$(OBJ)functions.o: $(SRC)functions.c $(HEADER)header.h
	$(CC) $(CFLAG) $(SRC)functions.c $(INCLUDE) $(FLAG) $(OBJ)functions.o

$(OBJ)tcmk.o: $(SRC)tcpclient.c $(HEADER)header.h
	$(CC) $(CFLAG) $(SRC)tcpclient.c $(INCLUDE) $(FLAG) $(OBJ)tcmk.o

all: $(BIN)tsmk $(BIN)tcmk

clean:
	rm ../obj/*.o
	rm ../bin/*

valgrind: $(BIN)tsmk
	$(VFLAG) $(BIN)tsmk
