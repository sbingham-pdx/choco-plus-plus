CC = g++
DEBUG = -g
DEFINES = 


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

TEST = test.cpp\
		$(NULL)

TFILES = $(CONNECTOR)\
		$(REPORTS)\
		$(STRUCTS)\
		$(TEST)\
		$(NULL)

FILES = $(CONNECTOR)\
		$(REPORTS)\
		$(STRUCTS)\
		$(TERMINAL)\
		$(NULL)
		
PROG1 = chocoplusplus
PROG2 = tests

PROGS = $(PROG1) $(PROG2)

all: $(PROGS)

$(PROG1):  $(FILES)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)
	chmod a+rx,g-w $@

$(PROG2):  $(TFILES)
	$(CC) $(CFLAGS) -DVERBOSE $(IFLAGS) -o $@ $^ $(LFLAGS)
	chmod a+rx,g-w $@

clean:
	rm -f *.o *.csv $(PROGS)
