SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .c .o

CC  = gcc
RM_DIR = rm -rf
OBJ = skiplist.o
EXECUTABLE = skiplist

prog: $(OBJ)
	$(CC) -o $(EXECUTABLE) $(OBJ) -lm
	$(RM_DIR) $(OBJ)

%.o: %.c
	$(CC) -c -g -Wall $<

clean :
	$(RM_DIR) $(EXECUTABLE)
