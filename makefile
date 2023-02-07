all: warmup

warmup: warmup.o 
	gcc warmup.o -o run

warmup.o: warmup.c
	gcc warmup.c -c

clean:
	rm -f *.o warmup run
