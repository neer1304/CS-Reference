              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for dynamic struct  program  |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


../bin/name_det: ../obj/name_det_main.o ../obj/name_det_functions.o
	gcc -o name_det -g ../obj/name_det_main.o ../obj/name_det_functions.o
	mv name_det ../bin/

../obj/name_det_main.o: ../src/name_det_main.c ../include/name_det_header.h
	gcc -c -g -Wall ../src/name_det_main.c -I../include/
	mv name_det_main.o ../obj/

../obj/name_det_functions.o: ../src/name_det_functions.c ../include/name_det_header.h
	gcc -c -g -Wall ../src/name_det_functions.c -I../include/
	mv name_det_functions.o ../obj/

clean:
	rm ../bin/name_det
	rm ../obj/*.o

