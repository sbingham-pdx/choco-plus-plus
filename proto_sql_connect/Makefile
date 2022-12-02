CC = g++
DEBUG = -g
DEFINES =
#DEFINES += -DTEST

CFLAGS = $(DEBUG) -Wall -Wshadow -Wunreachable-code -Wredundant-decls \
        -Wmissing-declarations\
    	-Wno-return-local-addr \
		-Wuninitialized -Werror -Wunsafe-loop-optimizations $(DEFINES)

IFLAGS = 
IFLAGS += -I/usr/include/mysqlcppconn

LFLAGS = 
LFLAGS += -L/usr/lib
LFLAGS += -lmysqlcppconn

HFILES = \
		cadb.h\
		$(NULL)

CFILES = cadb.cpp\
		main.cpp\
		$(NULL)

FILES = \
	$(HFILES)\
	$(CFILES)\
	$(NULL)

TFILES = $(HFILES)\
		cadb.cpp\
		test.cpp\
		$(NULL)
		
PROG1 = cadb
PROG2 = unit_tests

PROGS = $(PROG1) $(PROG2)

all: $(PROGS)


$(PROG1):  $(FILES)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)
	chmod a+rx,g-w $@

$(PROG2): $(TFILES)
	$(CC) $(CFLAGS) -DVERBOSE $(IFLAGS) -o $@ $^ $(LFLAGS)
	chmod a+rx,g-w $@

clean:
	rm -f *.o $(PROGS)