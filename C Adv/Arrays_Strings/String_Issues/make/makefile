              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for string program           |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


../bin/string: ../obj/string_main.o ../obj/string_functions.o
	gcc -o string ../obj/string_main.o ../obj/string_functions.o
	mv string ../bin/

../obj/string_main.o: ../src/string_main.c ../include/string_header.h
	gcc -c -Wall ../src/string_main.c -I../include/
	mv string_main.o ../obj/

../obj/string_functions.o: ../src/string_functions.c ../include/string_header.h
	gcc -c -Wall ../src/string_functions.c -I../include/
	mv string_functions.o ../obj/

clean:
	rm ../bin/string
	rm ../obj/*.o

