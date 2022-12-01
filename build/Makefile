CC = g++
DEBUG = -g
#DEBUG += --verbose
DEFINES = 
#DEFINES += -DVERBOSE


CFLAGS = $(DEBUG) -Wall -Wshadow -Wunreachable-code -Wredundant-decls \
        -Wmissing-declarations \
    	-Wno-return-local-addr \
		-Wuninitialized -Wunsafe-loop-optimizations $(DEFINES)

IFLAGS = 
IFLAGS += -I/usr/include/mysqlcppconn

LFLAGS = 
LFLAGS += -L/usr/lib
LFLAGS += -lmysqlcppconn

CONNECTOR = cadb.h\
			cadb.cpp\
			$(NULL)

REPORTS = reports.h\
		accounting_report.cpp\
		general_report_classes.cpp\
		management.cpp\
		member_report.cpp\
		provider_report.cpp\
		service_directory.cpp\
		$(NULL)

STRUCTS = structures.h\
		structures.cpp\
		$(NULL)


TERMINAL = oterminal.h\
		oterminal.cpp\
		mterminal.cpp\
		pterminal.cpp\
		chocoplusplus.cpp\
		$(NULL)

FILES = $(CONNECTOR)\
		$(REPORTS)\
		$(STRUCTS)\
		$(TERMINAL)\
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
	rm -f *.o *.csv $(PROGS)