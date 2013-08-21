CFLAGS=-m32 -D NDEBUG -I . -I ../../aterm/src -I ../../error-support/src -I ../../pt-support/src

SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)
LIB=libsglr.a
all : $(LIB) 
$(LIB) : $(OBJS)
	ar rcs $(LIB) $(OBJS)
clean :
	rm -f $(LIB) $(OBJS)
