program: main.o libmem.a
	gcc -o program main.o -L. -lmem -lpthread

main.o: main.c
	gcc -c -Wall main.c -lpthread

libmem.a: mem_lib.o
	ar -r libmem.a mem_lib.o

mem_lib.o: mem_lib.c
	gcc -g -c mem_lib.c -lpthread

clean:
	rm *.o
	rm libmem.a
