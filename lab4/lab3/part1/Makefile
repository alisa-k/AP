#use gcc for C compilation
CC = gcc
#
# Additional include directories
INCLUDES = 
#
# Compilation options: -g debug info, -Wall enables all warnings
CFLAGS = -g -Wall $(INCLUDES)
#
# Linking options
LDFLAGS = -g 
#
TARGET = mylist-test
#
# Static library name
STATICLIB = libmylist.a
#
# link
$(TARGET) : mylist-test.o $(STATICLIB)
	$(CC) $(LDFLAGS) mylist-test.o $(STATICLIB) -o $(TARGET)
#
#
# compile mylist.c
mylist.o: mylist.c mylist.h
	$(CC) -c $(CFLAGS) mylist.c
#
#
# create library
$(STATICLIB) : mylist.o
	ar rc $(STATICLIB) mylist.o
	ranlib $(STATICLIB)
#
# compile mylist-test.c
mylist-test.o: mylist-test.c mylist.h
	$(CC) -c $(CFLAGS) mylist-test.c
#
#
# "clean" target
.PHONY: clean
clean: 
	rm -f *.o *.a a.out core $(TARGET)

# "all" target
.PHONY: all
all: clean $(TARGET) 
