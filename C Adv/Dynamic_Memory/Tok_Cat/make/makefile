              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for tok cat program          |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


../bin/tok_cat: ../obj/tok_cat_main.o ../obj/tok_cat_functions.o
	gcc -o tok_cat -g ../obj/tok_cat_main.o ../obj/tok_cat_functions.o
	mv tok_cat ../bin/

../obj/tok_cat_main.o: ../src/tok_cat_main.c ../include/tok_cat_header.h
	gcc -c -g -Wall ../src/tok_cat_main.c -I../include/
	mv tok_cat_main.o ../obj/

../obj/tok_cat_functions.o: ../src/tok_cat_functions.c ../include/tok_cat_header.h
	gcc -c -g -Wall ../src/tok_cat_functions.c -I../include/
	mv tok_cat_functions.o ../obj/

clean:
	rm ../bin/tok_cat
	rm ../obj/*.o

