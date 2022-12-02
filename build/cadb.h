#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <string>

using namespace sql;
using namespace std;

class cadb{
	public:
		cadb(void);
		virtual ~cadb(void);

		void execute(const string statement);
		void queryDB(const string statment, sql::ResultSet *& foRes);
		string getString(const string table, const string column, const string tomatch, const string getcolumn);
		void setCell(const string table, const string tocolumn, const string tomatch, const string setcolumn, const string set);
		int findMatch(const string table, const string tocolumn, const string tomatch);
		int getRows(const string table);
		int getID(const string table, string tomatch);
		int getStatus(const string table, const int id);

		void insertVisit(const string date, const int provider_id, const int service_id, const int member_id, const string comments);
		void insertProvider(const string number, const string name, const string street, const string city, const string state, const string zip);
		void insertMember(const string number, const string name, const string street, const string city, const string state, const string zip);
		void insertService(const string number, const string name, const string cost);

	private:
		sql::Driver	*caDriver;
		sql::Connection	*caConn;
};