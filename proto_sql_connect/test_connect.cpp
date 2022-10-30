#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace sql;

int
main()
{
	std::cout << "Start C++ connect mysql test example \n";
	try {
		// Do the thing
		sql::Driver	*myDriver;
		sql::Connection	*myConn;
		sql::Statement	*myStmt;
		sql::ResultSet	*myRes;

		std::cout << ">> Getting Driver Instance " << std::endl;
		myDriver = get_driver_instance();
		std::cout << ">> Driver instance obtained " << std::endl;

		std::cout << ">> Connecting to database " << std::endl;
		myConn = myDriver->connect("db.cecs.pdx.edu", "sbingham", "x6Tcbcs5*a");
		std::cout << ">> Connected to database " << std::endl;
		std::cout << ">> Connecting to schema 'sbingham'  " << std::endl;
		myConn->setSchema("sbingham");
		std::cout << ">> Connected to schema 'sbingham'  " << std::endl;

		myStmt = myConn->createStatement();
		myRes = myStmt->executeQuery("SELECT * FROM provider");


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
		delete myConn;


	}
	catch (sql::SQLException &e) {

		std::cout << "Filed Connect to MySql database test" << std::endl;
		std::cout << "Error : " << e.what() << std::endl;
		std::cout << "Error Code : " << e.getErrorCode() << std::endl;
	}
	return 0;
};
