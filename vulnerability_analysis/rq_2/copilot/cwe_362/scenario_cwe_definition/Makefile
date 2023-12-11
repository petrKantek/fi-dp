SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: $(OBJS)

%.o: %.c
	gcc -g -lpthread -O -c $< -o $@

clean:
	rm -rf $(OBJS)
