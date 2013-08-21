CFLAGS=-m32 -D NDEBUG -I . -I ../../aterm/src -I ../../error-support/src -I ../../pt-support/src -I ../../sglr/src
LDFLAGS=-static -L ../../aterm/src -L ../../error-support/src -L ../../pt-support/src -L ../../sglr/src

SRC=$(sdf-wrapper.c)
OBJS=$(SRC:.c=.o)
BIN=sglr-server
all : $(BIN)
$(BIN) : main.c $(OBJS)
	gcc $(CFLAGS) $(LDFLAGS) -o $(BIN) main.c sdf-wrapper.o $(OBJS) -lsglr -lpt-support -lerror-support -lATerm -lc
clean :
	rm -f $(BIN) $(OBJS)
