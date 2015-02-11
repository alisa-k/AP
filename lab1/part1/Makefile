# gcc for C compilation

CC  = gcc

# Compilation options:

CFLAGS   = -g -Wall

# Linking options:

LDFLAGS = -g

# Target: executable named specified

TARGET = main

# Linking rules

$(TARGET): main.o gcd.o prime.o
	$(CC) $(LDFLAGS) main.o gcd.o prime.o -o $(TARGET) 

# Compilation rules

main.o: main.c gcd.h prime.h
	$(CC) -c $(CFLAGS) main.c

gcd.o: gcd.c gcd.h
	$(CC) -c $(CFLAGS) gcd.c

prime.o: prime.c prime.h
	$(CC) -c $(CFLAGS) prime.c

# "clean" target

.PHONY: clean
clean:
	rm -f *.o a.out core $(TARGET)

# "all" target

.PHONY: all
all: clean $(TARGET)
