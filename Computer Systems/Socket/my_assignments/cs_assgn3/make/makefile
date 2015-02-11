CC=gcc
CFLAG=-c -Wall -g
FLAG=-o
SRC=../src/
BIN=../bin/
OBJ=../obj/
INCLUDE=-I../include/
HEADER=../include/

$(BIN)conts: $(OBJ)con_tcpserver.o $(OBJ)functions.o
	$(CC) $(OBJ)con_tcpserver.o $(OBJ)functions.o $(FLAG) $(BIN)conts

$(BIN)tc: $(OBJ)tcpclient.o
	$(CC) $(OBJ)tcpclient.o $(FLAG) $(BIN)tc

$(OBJ)con_tcpserver.o: $(SRC)con_tcpserver.c $(HEADER)header.h
	$(CC) $(CFLAG) $(SRC)con_tcpserver.c $(INCLUDE) $(FLAG) $(OBJ)con_tcpserver.o

$(OBJ)functions.o: $(SRC)functions.c $(HEADER)header.h
	$(CC) $(CFLAG) $(SRC)functions.c $(INCLUDE) $(FLAG) $(OBJ)functions.o

$(OBJ)tcpclient.o: $(SRC)tcpclient.c $(HEADER)header.h
	$(CC) $(CFLAG) $(SRC)tcpclient.c $(INCLUDE) $(FLAG) $(OBJ)tcpclient.o

clean:	
	rm $(BIN)*
	rm $(OBJ)*

all:	$(BIN)conts $(BIN)tc
