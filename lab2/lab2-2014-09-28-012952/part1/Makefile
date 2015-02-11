# gcc for C compilation

CC  = gcc

# Compilation options:

CFLAGS   = -g -Wall

# Linking options:

LDFLAGS = -g

# Target: executable named specified

TARGET = isort

# Linking rules

$(TARGET): sort.o
	$(CC) $(LDFLAGS) sort.o -o $(TARGET) 

# Compilation rules

sort.o: sort.c sort.h
	$(CC) -c $(CFLAGS) sort.c

# "clean" target

.PHONY: clean
clean:
	rm -f *.o a.out core $(TARGET)

# "all" target

.PHONY: all
all: clean $(TARGET)
