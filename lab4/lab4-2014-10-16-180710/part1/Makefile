#use gcc for C compilation
CC = gcc
#
# Additional include directories
INCLUDES = -I../../lab3/part1
#
# Compilation options: -g debug info, -Wall enables all warnings
CFLAGS = -g -Wall $(INCLUDES)
#
# Linking options
LDFLAGS = -g -L../../lab3/part1 
#
LDLIBS = -lmylist
#
TARGET = mdb-lookup
#
# Static library name
STATICLIB = libmylist.a
#
# link
$(TARGET) : mdb.o
	$(CC) $(LDFLAGS) mdb.o $(LDLIBS) -o $(TARGET)
#
# compile revecho.c
mdb.o: mdb.c mdb.h
	$(CC) -c $(CFLAGS) mdb.c
#
# "clean" target
.PHONY: clean
clean: 
	rm -f *.o *.a a.out core $(TARGET)

# "all" target
.PHONY: all
all: clean $(TARGET) 
