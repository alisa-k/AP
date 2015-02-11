# gcc for C compilation

CC  = gcc

# Compilation options:

CFLAGS   = -g -Wall

# Linking options:

LDFLAGS = -g

# Target: executable named specified

TARGET = twecho

# Linking rules

$(TARGET): twecho.o
	$(CC) $(LDFLAGS) twecho.o -o $(TARGET) 

# Compilation rules

twecho.o: twecho.c
	$(CC) -c $(CFLAGS) twecho.c

# "clean" target

.PHONY: clean
clean:
	rm -f *.o a.out core $(TARGET)

# "all" target

.PHONY: all
all: clean $(TARGET)
