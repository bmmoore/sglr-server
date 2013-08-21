CFLAGS=-m32 -D NDEBUG -I . -I ../../aterm/src

SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)
LIB=liberror-support.a
all : $(LIB) 
$(LIB) : $(OBJS)
	ar rcs $(LIB) $(OBJS)
clean :
	rm -f $(LIB) $(OBJS)
