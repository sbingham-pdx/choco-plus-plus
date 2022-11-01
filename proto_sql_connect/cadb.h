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
		string getString(const string table, const string column, const string tomatch, const string get);
		void setCell(const string table, const string column, const string tomatch, const string setcolumn, const string set);
		int findMatch(const string table, const string column, const string tomatch);
		int getRows(const string table);

		void insertVisit(const string date, const int provider_id, const int service_id, const int member_id);
		void insertProvider(const string number, const string name, const string street, const string city, const string state, const string zip);
		void insertMember(const string number, const string name, const string street, const string city, const string state, const string zip);

	private:
		sql::Driver	*caDriver;
		sql::Connection	*caConn;
		//sql::Statement	*caStmt;
		//sql::ResultSet	*caRes;

};
// LOOK HERE FOR STUFF!!!
///usr/include/cppconn/statement.h:76:24

//insert INTO sbingham.transaction (trans_date, provider_id, service_id, member_id) 
//values ('2022-09-26', '4', '6', '22');

/*
int
main()
{
	std::cout << "Start C++ connect mysql test example \n";
	try {
		// Do the thing
		sql::Driver	*caDriver;
		sql::Connection	*caConn;
		sql::Statement	*myStmt;
		sql::ResultSet	*myRes;

		std::cout << ">> Getting Driver Instance " << std::endl;
		caDriver = get_driver_instance();
		std::cout << ">> Driver instance obtained " << std::endl;

		std::cout << ">> Connecting to database " << std::endl;
		caConn = caDriver->connect("db.cecs.pdx.edu", "sbingham", "x6Tcbcs5*a");
		std::cout << ">> Connected to database " << std::endl;
		std::cout << ">> Connecting to schema 'sbingham'  " << std::endl;
		caConn->setSchema("sbingham");
		std::cout << ">> Connected to schema 'sbingham'  " << std::endl;

		myStmt = caConn->createStatement();

		std::string input = "2";
		std::string query = "SELECT * FROM provider WHERE id=";
		query += input;

		// You can modify this statement to 
		myRes = myStmt->executeQuery(query);


		while (myRes->next()){
			std::cout << myRes->getString("provider_number") << "\t| ";// << std::endl;
			std::cout << myRes->getString("provider_name") << "\t\t\t| ";//std::endl;
			std::cout << myRes->getString("provider_street") << "\t\t| ";
			std::cout << myRes->getString("provider_city") << "\t\t| ";
			std::cout << myRes->getString("provider_state") << "\t\t| ";
			std::cout << myRes->getString("provider_zip") << "\t\t| " << std::endl;
		}

		delete myRes;
		delete myStmt;
		delete caConn;


	}
	catch (sql::SQLException &e) {

		std::cout << "Filed Connect to MySql database test" << std::endl;
		std::cout << "Error : " << e.what() << std::endl;
		std::cout << "Error Code : " << e.getErrorCode() << std::endl;
	}
	return 0;
};*/
