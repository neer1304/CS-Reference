CC=gcc
CFLAGS=-c -Wall -g
FLAG=-o
SRC=../src/
BIN=../bin/
OBJ=../obj/
INCLUDE=-I ../include/
HEADER=../include/

$(BIN)msgrcvmk : $(OBJ)msgreciever.o 
	$(CC) $(OBJ)msgreciever.o $(FLAG) $(BIN)msgrcvmk

$(BIN)msgsndmk : $(OBJ)msgsender.o 
	$(CC) $(OBJ)msgsender.o $(FLAG) $(BIN)msgsndmk
 
$(OBJ)msgreciever.o : $(SRC)msgreciever.c $(HEADER)msgheader.h
	$(CC) $(CFLAGS) $(SRC)msgreciever.c $(INCLUDE) $(FLAG) $(OBJ)msgreciever.o

$(OBJ)msgsender.o : $(SRC)msgsender.c $(HEADER)msgheader.h
	$(CC) $(CFLAGS) $(SRC)msgsender.c $(INCLUDE) $(FLAG) $(OBJ)msgsender.o

run: $(BIN)msgrcvmk $(BIN)msgsndmk
