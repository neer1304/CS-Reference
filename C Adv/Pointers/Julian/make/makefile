              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for Julian program	   |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


../bin/julian: ../obj/julian_main.o ../obj/julian_functions.o
	gcc -o julian ../obj/julian_main.o ../obj/julian_functions.o
	mv julian ../bin/

../obj/julian_main.o: ../src/julian_main.c ../include/julian_header.h
	gcc -c -Wall ../src/julian_main.c -I../include/
	mv julian_main.o ../obj/

../obj/julian_functions.o: ../src/julian_functions.c ../include/julian_header.h
	gcc -c -Wall ../src/julian_functions.c -I../include/
	mv julian_functions.o ../obj/

clean:
	rm ../bin/julian
	rm ../obj/*.o


