#
# Makefile for lab 6, part 2
#

# use gcc for compiling
CC  = gcc

INCLUDES =

# compiling options
CFLAGS   = -g -Wall $(INCLUDES)

# linking options
LDFLAGS = -g

# linking rules
http-client: http-client.o
	$(CC) $(LDFLAGS) http-client.o -o http-client

# compiling rules
http-client.o: http-client.c
	$(CC) -c $(CFLAGS) http-client.c

.PHONY: clean
clean:
	rm -f *.o *~ a.out core http-client

.PHONY: all
all: clean http-client
