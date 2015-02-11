              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for variable argument program|   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################

output: var_main.o var_fun_def.o
	gcc -o output var_main.o var_fun_def.o

var_main.o: var_main.c var_header.h
	gcc -c -Wall var_main.c

var_fun_def.o: var_fun_def.c
	gcc -c -Wall var_fun_def.c

clean:
	rm *.o
	rm output
