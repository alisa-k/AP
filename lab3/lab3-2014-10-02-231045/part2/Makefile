#use gcc for C compilation
CC = gcc
#
# Additional include directories
INCLUDES = -I../part1
#
# Compilation options: -g debug info, -Wall enables all warnings
CFLAGS = -g -Wall $(INCLUDES)
#
# Linking options
LDFLAGS = -g -L../part1 
#
LDLIBS = -lmylist
#
TARGET = revecho
#
# Static library name
STATICLIB = libmylist.a
#
# link
$(TARGET) : revecho.o
	$(CC) $(LDFLAGS) revecho.o $(LDLIBS) -o $(TARGET)
#
# compile revecho.c
revecho.o: revecho.c
	$(CC) -c $(CFLAGS) revecho.c
#
# "clean" target
.PHONY: clean
clean: 
	rm -f *.o *.a a.out core $(TARGET)

# "all" target
.PHONY: all
all: clean $(TARGET) 
