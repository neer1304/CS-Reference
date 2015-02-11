              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for array program            |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


../bin/array: ../obj/array_main.o ../obj/array_functions.o
	gcc -o array -g ../obj/array_main.o ../obj/array_functions.o
	mv array ../bin/

../obj/array_main.o: ../src/array_main.c ../include/array_header.h
	gcc -c -g -Wall ../src/array_main.c -I../include/
	mv array_main.o ../obj/

../obj/array_functions.o: ../src/array_functions.c ../include/array_header.h
	gcc -c -g -Wall ../src/array_functions.c -I../include/
	mv array_functions.o ../obj/

clean:
	rm ../bin/array
	rm ../obj/*.o

