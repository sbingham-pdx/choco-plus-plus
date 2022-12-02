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
		structures.cpp\
		cadb.cpp\
		test.cpp\
		$(NULL)
		
PROG1 = cadb

PROGS = $(PROG1) 

all: $(PROGS) test

#$(PROG1): $(PROG1).o
#	#$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)
#	chmod a+rx,g-w $@

$(PROG1):  $(FILES) #?akefile
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)
	chmod a+rx,g-w $@

test: $(TFILES) #?akefile
	$(CC) $(CFLAGS) -DVERBOSE $(IFLAGS) -o $@ $^ $(LFLAGS)
	chmod a+rx,g-w $@

#all: cadb.h
#	g++ -g -Wall -I/usr/include/mysqlcppconn -o cadb cadb.h cadb.cpp test.cpp -L/usr/lib -lmysqlcppconn

clean:
	rm -f *.o $(PROGS) test
