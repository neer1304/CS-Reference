CFLAGS=-DDEBUG

all: rw_array_mutex rw_array_semaphore rw_singlevar_mutex_i rw_singlevar_mutex_ii rw_singlevar_semaphore rw_array_mutex_broadcast rw_account_mutex rw_account_mutex_condvar


rw_array_mutex: rw_array_mutex.c
	gcc -o rw_array_mutex $(CFLAGS) rw_array_mutex.c -lpthread

rw_array_mutex_broadcast: rw_array_mutex_broadcast.c
	gcc -o rw_array_mutex_broadcast $(CFLAGS) rw_array_mutex_broadcast.c -lpthread

rw_account_mutex: rw_account_mutex.c
	gcc -o rw_account_mutex $(CFLAGS) rw_account_mutex.c -lpthread

rw_account_mutex_condvar: rw_account_mutex_condvar.c
	gcc -o rw_account_mutex_condvar $(CFLAGS) rw_account_mutex_condvar.c -lpthread

rw_array_semaphore: rw_array_semaphore.c
	gcc -o rw_array_semaphore $(CFLAGS) rw_array_semaphore.c -lpthread

rw_singlevar_mutex_i: rw_singlevar_mutex_i.c
	gcc -o rw_singlevar_mutex_i $(CFLAGS) rw_singlevar_mutex_i.c -lpthread

rw_singlevar_mutex_ii: rw_singlevar_mutex_ii.c
	gcc -o rw_singlevar_mutex_ii $(CFLAGS) rw_singlevar_mutex_ii.c -lpthread

rw_singlevar_semaphore: rw_singlevar_semaphore.c
	gcc -o rw_singlevar_semaphore $(CFLAGS) rw_singlevar_semaphore.c -lpthread

clean:
	rm rw_array_mutex
	rm rw_account_mutex
	rm rw_account_mutex_condvar
	rm rw_array_mutex_broadcast
	rm rw_array_semaphore
	rm rw_singlevar_mutex_i
	rm rw_singlevar_mutex_ii
	rm rw_singlevar_semaphore

