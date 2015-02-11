CC=gcc
CFLAGS=-c -Wall -g
FLAG=-o
SRC=../src/
BIN=../bin/
OBJ=../obj/

all: $(BIN)tcmk $(BIN)tsmk

$(BIN)tcmk: $(OBJ)tcpclient.o
	$(CC) $(OBJ)tcpclient.o $(FLAG) $(BIN)tcmk 

$(BIN)tsmk: $(OBJ)tcpserver.o
	$(CC) $(OBJ)tcpserver.o $(FLAG) $(BIN)tsmk

$(OBJ)tcpclient.o: $(SRC)tcpclient.c
	$(CC) $(CFLAGS) $(SRC)tcpclient.c $(FLAG) $(OBJ)tcpclient.o

$(OBJ)tcpserver.o: $(SRC)tcpserver.c
	$(CC) $(CFLAGS) $(SRC)tcpserver.c $(FLAG) $(OBJ)tcpserver.o

