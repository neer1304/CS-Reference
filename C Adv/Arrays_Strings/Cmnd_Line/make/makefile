              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for cmd line program         |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


../bin/cmd_line: ../obj/cmd_line_main.o ../obj/cmd_line_functions.o
	gcc -o cmd_line  ../obj/cmd_line_main.o ../obj/cmd_line_functions.o
	mv cmd_line ../bin/

../obj/cmd_line_main.o: ../src/cmd_line_main.c ../include/cmd_line_header.h
	gcc -c  -Wall ../src/cmd_line_main.c -I../include/
	mv cmd_line_main.o ../obj/

../obj/cmd_line_functions.o: ../src/cmd_line_functions.c ../include/cmd_line_header.h
	gcc -c  -Wall ../src/cmd_line_functions.c -I../include/
	mv cmd_line_functions.o ../obj/

clean:
	rm ../bin/cmd_line
	rm ../obj/*.o

