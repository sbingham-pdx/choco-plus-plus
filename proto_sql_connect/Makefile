all: test_connect.cpp
	g++ -g -Wall -I/usr/include/mysqlcppconn -o sqltest test_connect.cpp -L/usr/lib -lmysqlcppconn
	#g++ -g -o0 -I/usr/local/include -I/usr/local/boost/include -c test_connect.cpp -o test_connect.o
	#g++ -g -o0 -L/usr/local/lib -L/usr/local/mysql/lib -lmysqlcppconn test_connect.o -o sqltest

header: cadb.h
	g++ -g -Wall -I/usr/include/mysqlcppconn -o cadb cadb.h cadb.cpp test.cpp -L/usr/lib -lmysqlcppconn

clean:
	rm sqltest cadb
