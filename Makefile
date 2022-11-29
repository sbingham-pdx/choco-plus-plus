CC = g++
DEBUG = -g
DEFINES =
#DEFINES += -DTEST

CFLAGS = $(DEBUG) -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wno-return-local-addr -Wuninitialized -Wunsafe-loop-optimizations $(DEFINES)

IFLAGS = 
IFLAGS += -I/usr/include/mysqlcppconn

LFLAGS = 
LFLAGS += -L/usr/lib
LFLAGS += -lmysqlcppconn

FILES = \
	cadb.h\
	cadb.cpp\
	eft.cpp\
	management.cpp\
	mweek.cpp\
  pterminal.h\
  provider.cpp\
	pterminal.cpp\
	reports.h\
	service_directory.cpp\
	service.cpp\
	structures.cpp\
	structures.h\
	chocoplusplus.cpp\
	$(NULL)
		
PROG1 = chocoplusplus

PROGS = $(PROG1) 

all: $(PROGS)

#$(PROG1): $(PROG1).o
#	#$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)
#	chmod a+rx,g-w $@

$(PROG1):  $(FILES) #?akefile
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)
	chmod a+rx,g-w $@

#all: cadb.h
#	g++ -g -Wall -I/usr/include/mysqlcppconn -o cadb cadb.h cadb.cpp test.cpp -L/usr/lib -lmysqlcppconn

clean:
	rm -f *.o $(PROGS)
