              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for day program		   |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


../bin/day: ../obj/day_main.o ../obj/day_functions.o
	gcc -o day ../obj/day_main.o ../obj/day_functions.o
	mv day ../bin/

../obj/day_main.o: ../src/day_main.c ../include/day_header.h
	gcc -c -Wall ../src/day_main.c -I../include/
	mv day_main.o ../obj/

../obj/day_functions.o: ../src/day_functions.c ../include/day_header.h
	gcc -c -Wall ../src/day_functions.c -I../include/
	mv day_functions.o ../obj/

clean:
	rm ../bin/day
	rm ../obj/*.o


