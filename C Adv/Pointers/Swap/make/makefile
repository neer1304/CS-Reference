              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for swap program             |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


../bin/swap: ../obj/pbv_pbr_main.o ../obj/pbv_pbr_functions.o
	gcc -o swap ../obj/pbv_pbr_main.o ../obj/pbv_pbr_functions.o
	mv swap ../bin/

../obj/pbv_pbr_main.o: ../src/pbv_pbr_main.c ../include/pbv_pbr_header.h
	gcc -c -Wall ../src/pbv_pbr_main.c -I../include/
	mv pbv_pbr_main.o ../obj/

../obj/pbv_pbr_functions.o: ../src/pbv_pbr_functions.c ../include/pbv_pbr_header.h
	gcc -c -Wall ../src/pbv_pbr_functions.c -I../include/
	mv pbv_pbr_functions.o ../obj/

clean:
	rm ../bin/swap
	rm ../obj/*.o

