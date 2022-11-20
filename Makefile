CC=gcc
CFLAGS=-Wall
DFLAGS=-g
PROGS=chocoplusplus

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< $(LDFLAGS) -o $@

clean:
	rm -f $(PROGS) *.o ~*


