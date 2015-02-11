program: main.o libmem.a
	gcc -o program main.o -L. -lmem

anotherprg : anothermain.o libmem.a
	gcc -o anotherprg anothermain.o -L. -lmem

anothermain.o: anothermain.c
	gcc -c -Wall anothermain.c

main.o: main.c
	gcc -c -Wall main.c

libmem.a: mem_lib.o
	ar -r libmem.a mem_lib.o

mem_lib.o:mem_lib.c
	gcc -c mem_lib.c

clean:
	rm *.o
	rm *.a
	rm program

