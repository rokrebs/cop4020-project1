#CC = clang
#override CFLAGS += -g -Wno-everything

#SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
#OBJS = $(patsubst %.c, %.o, $(SRCS))

#main: $(OBJS)
#	$(CC) $(CFLAGS) $(OBJS) -o main

#clean:
#	rm -f $(OBJS) main

# Student Name:Rocio Krebs
CC = gcc
CFLAGS  = -g -Wall

all: lexer.o parser.o table.o main.o main

lexer.o: lexer.h 
	$(CC) $(CFLAGS) -c lexer.c

parser.o: parser.h
	$(CC) $(CFLAGS) -c parser.c

table.o: table.h
	$(CC) $(CFLAGS) -c table.c

main.o: lexer.h parser.h
	$(CC) $(CFLAGS) -c main.c

main: lexer.o parser.o table.o main.o 
	$(CC) $(CFLAGS) lexer.o parser.o table.o main.o -o main

clean: 
	$(RM) *.o *~ main