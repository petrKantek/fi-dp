SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: $(OBJS)

%.o: %.c
	gcc -g -O -lcurl -c $< -o $@

clean:
	rm -rf $(OBJS)
