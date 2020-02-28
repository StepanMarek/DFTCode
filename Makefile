CC=gcc
CFLAGS=-Werror -Wall -I.
CLIBS=-lm

exec : exec.o basis/basis_atomic.o
	$(CC) -o $@ exec.o basis/basis_atomic.o $(CFLAGS) $(CLIBS)

%.o : %.c
	+$(MAKE) -C basis
	$(CC) -c -o $@ $< $(CFLAGS) $(CLIBS)

clean :
	rm *.o
	rm basis/*.o
