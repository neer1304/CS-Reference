all: sender receiver

sender: msgsender.c msgheader.h
	gcc -o sender msgsender.c -lrt

receiver: msgreceiver.c msgheader.h
	gcc -o receiver msgreceiver.c -lrt

clean:
	rm receiver sender
