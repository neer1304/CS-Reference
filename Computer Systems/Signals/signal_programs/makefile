all:introduction basic advanced usage caution

introduction: introductionsignal.c
	gcc -o introduction introductionsignal.c

basic: basicsignaldemo.c
	gcc -o basic basicsignaldemo.c

advanced: advancedsignaldemo.c
	gcc -o advanced advancedsignaldemo.c

usage: useofsignal.c
	gcc -o usage useofsignal.c

caution: cautionwithsignal.c
	gcc -o caution cautionwithsignal.c -lpthread

clean:
	rm introduction 
	rm basic 
	rm advanced 
	rm usage 
	rm caution
