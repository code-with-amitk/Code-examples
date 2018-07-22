IDIR=.
CC=gcc
CFLAGS=-I$(IDIR)	#List of flags to pass to compilation command
LDFLAGS=-L/usr/lib64

OBJ= init.o main.o

make: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) -lssl -lcrypto
