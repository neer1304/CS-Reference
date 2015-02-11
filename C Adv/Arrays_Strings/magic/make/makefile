../bin/run:../obj/main.o ../obj/magic_functions.o
	gcc ../obj/main.o ../obj/magic_functions.o -o ../bin/run

../obj/main.o: ../src/main.c ../include/header.h
	gcc -c -Wall -g ../src/main.c -I../include/ -o ../obj/main.o

../obj/magic_functions.o: ../src/magic_functions.c ../include/header.h
	gcc -c -Wall -g ../src/magic_functions.c -I../include/ -o ../obj/magic_functions.o

clean:
	rm ../obj/*.o
	rm ../bin/run

