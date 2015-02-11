CC=gcc
OFLAG=  -o
CFLAGS= -g -c -Wall
INCLUDE= -I../include/
HEADER= ../include/
OBJ= ../obj/
SRC=../src/
BIN=../bin/
VFLAGS= valgrind --tool=memcheck --leak-check=yes --show-reachable=yes 

$(BIN)list: $(OBJ)insert_functions.o $(OBJ)delete_functions.o $(OBJ)other_functions.o $(OBJ)main.o
	$(CC) $(OFLAG) $(BIN)list $(OBJ)insert_functions.o $(OBJ)delete_functions.o $(OBJ)other_functions.o $(OBJ)main.o

$(OBJ)insert_functions.o:$(SRC)insert_functions.c $(HEADER)header.h
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC)insert_functions.c $(OFLAG) $(OBJ)insert_functions.o

$(OBJ)delete_functions.o:$(SRC)delete_functions.c $(HEADER)header.h
	$(CC) $(CFLAGS) $(INCLUDE)  $(SRC)delete_functions.c $(OFLAG) $(OBJ)delete_functions.o
 
$(OBJ)other_functions.o:$(SRC)other_functions.c $(HEADER)header.h
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC)other_functions.c $(OFLAG) $(OBJ)other_functions.o

$(OBJ)main.o:$(SRC)main.c $(HEADER)header.h
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC)main.c $(OFLAG) $(OBJ)main.o

valgrind: $(BIN)list
	$(VFLAGS) ./$(BIN)list
clean :
	rm $(OBJ)*.o
	rm $(BIN)list

	
