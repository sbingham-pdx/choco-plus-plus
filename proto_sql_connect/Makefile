CC = g++
DEBUG = -g
DEFINES =
DEFINES += -I/usr/include/mysqlcppconn

CFLAGS = $(DEBUG) -Wall -Wshadow -Wunreachable-code -Wredundant-decls \
        -Wmissing-declarations \
    	-Wno-return-local-addr \
		-Wuninitialized -Werror -Wunsafe-loop-optimizations $(DEFINES)

LFLAGS = 
LFLAGS += -L/usr/lib
LFLAGS += -lmysqlcppconn

FILES = \
	cadb.h\
	cadb.cpp\
	test.cpp\
	$(NULL)
		
PROG1 = cadb

PROGS = $(PROG1) 

all: $(PROGS)

#$(PROG1): $(PROG1).o
#	#$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)
#	chmod a+rx,g-w $@

$(PROG1):  $(FILES) #?akefile
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)
	chmod a+rx,g-w $@

#all: cadb.h
#	g++ -g -Wall -I/usr/include/mysqlcppconn -o cadb cadb.h cadb.cpp test.cpp -L/usr/lib -lmysqlcppconn

clean:
	rm -f *.o $(PROGS)