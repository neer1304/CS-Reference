              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for Antonym program          |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################

../bin/antonym.out: ../obj/antonym_main.o ../obj/antonym_functions.o 
	gcc -o antonym.out  ../obj/antonym_main.o ../obj/antonym_functions.o
	mv antonym.out ../bin/

../obj/antonym_main.o: ../src/antonym_main.c ../include/antonym_header.h
	gcc -c -g -Wall ../src/antonym_main.c -I../include/
	mv antonym_main.o ../obj/

../obj/antonym_functions.o: ../src/antonym_functions.c ../include/antonym_header.h

	gcc -c -g -Wall ../src/antonym_functions.c -I../include/
	mv antonym_functions.o ../obj/

clean:
	rm ../bin/antonym
	rm ../obj/*.o

