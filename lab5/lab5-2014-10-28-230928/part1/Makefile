# gcc for C compilation
C = gcc

# Additional include directories
INCLUDES =

# Compilation options
CFLAGS = -g -Wall $(INCLUDES)

# Linking options
LDFLAGS = -g

# Targets
TARGET1 = mdb-lookup-server-nc-1

TARGET2 = mdb-lookup-server-nc-2

# Linking
#$(TARGET1): mdb-lookup-server-nc-1.o
#	$(CC) $(LDFLAGS) mdb-lookup-server-nc-1.o -o $(TARGET1)

#$(TARGET2): mdb-lookup-server-nc-2.o
#	$(CC) $(LDFLAGS) mdb-lookup-server-nc-2.o -o $(TARGET2)

# Compiling
#mdb-lookup-server-nc-1.o: mdb-lookup-server-nc-1.c
#	$(CC) -c $(CFLAGS) mdb-lookup-server-nc-1.c

#mdb-lookup-server-nc-2.o: mdb-lookup-server-nc-2.c
#	$(CC) -c $(CFLAGS) mdb-lookup-server-nc-2.c


# 'default' target
.PHONY: default
default: $(TARGET1) $(TARGET2)

$(TARGET1): mdb-lookup-server-nc-1.c

$(TARGET2): mdb-lookup-server-nc-2.c

# 'clean' target
.PHONY: clean
clean:
	rm -f *.o *~ a.out core $(TARGET1) $(TARGET2) mypipe*

# 'all' target
.PHONY: all
all: clean default
