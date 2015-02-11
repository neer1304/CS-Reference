              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for struct function program  |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


struct_fun: main.o display.o
	gcc -o struct_fun main.o display.o

main.o: main.c header.h
	gcc -Wall -c main.c

display.o: display.c header.h
	gcc -Wall -c display.c

clean:
	rm *.o
	rm struct_fun


