#include "cadb.h"


cadb::cadb(void){

	myDriver = nullptr;
	myConn = nullptr;
	myStmt = nullptr;
	//myRes = nullptr;

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
}

cadb::~cadb(void){

	//delete myRes;
	delete myStmt;
	delete myConn;
}

// pass in the table, column, and string to match at that column
// and the column you want to get returned as a string
string cadb::getString(const string table, const string column, const string tomatch, const string get){

	string res;
	//sql::Statement	*myStmt;
	sql::ResultSet	*myRes = nullptr;
	//myRes = nullptr;

	string query = "SELECT * FROM";
	query += " ";
	query += table;
	query += " ";
	query += "WHERE";
	query += " ";
	query += column;
	query += " ";
	query += "=";
	query += " ";
	query += tomatch;
	//
	cout << "Calling: " << query << endl;
		//std::string input = "2";
		//shhhgggjjtd::string query = "SELECT * FROM provider WHERE id=";
		//query += input;


	// You can modify this statement to 
	myRes = myStmt->executeQuery(query);

	while (myRes->next()){
		res += myRes->getString(get);
	}

	//res = myRes->getString(get);
	//myRes = NULL;
	//myStmt = NULL;
	delete myRes;


	return res;
}
