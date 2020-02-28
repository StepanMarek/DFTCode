CC=gcc
CFLAGS=-Werror -Wall -I.
LIBS=-lm
DEPS=basis_atomic.h
TARGETS=basis_atomic.o

basis_atomic.o : basis_atomic.c $(DEPS)
	$(CC) $(CFLASG) -c -o $@ $< $(LIBS)

clean :
	rm *.o
