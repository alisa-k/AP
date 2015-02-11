# Use gcc for C compilation

CC  = gcc

# Compilation options:
# -g for debugging info and -Wall enables all warnings

CFLAGS   = -g -Wall

# Linking options:
# -g for debugging info

LDFLAGS = -g

# Target: specifies name of executable

TARGET = convert

# Linking rules

$(TARGET): main.o
	$(CC) $(LDFLAGS) main.o -o $(TARGET) 

# Compiling rules

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

# "clean" target

.PHONY: clean
clean:
	rm -f *.o a.out core $(TARGET)

# "all" target

.PHONY: all
all: clean $(TARGET)
