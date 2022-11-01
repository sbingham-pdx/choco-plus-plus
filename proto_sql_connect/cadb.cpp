#include "cadb.h"


cadb::cadb(void){

	myDriver = nullptr;
	myConn = nullptr;
	//myStmt = nullptr;
	//myRes = nullptr;

	try{
		//std::cout << ">> Getting Driver Instance " << std::endl;
		myDriver = get_driver_instance();
		//std::cout << ">> Driver instance obtained " << std::endl;

		//std::cout << ">> Connecting to database " << std::endl;
		myConn = myDriver->connect("db.cecs.pdx.edu", "sbingham", "x6Tcbcs5*a");
		//std::cout << ">> Connected to database " << std::endl;
		//std::cout << ">> Connecting to schema 'sbingham'  " << std::endl;
		myConn->setSchema("sbingham");
		//std::cout << ">> Connected to schema 'sbingham'  " << std::endl;
	}
	catch (sql::SQLException &e) {
		std::cout << "Failed to Connect to MySql DB 'sbingham'" << std::endl;
		std::cout << "Error : " << e.what() << std::endl;
		std::cout << "Error Code : " << e.getErrorCode() << std::endl;
	}

}

cadb::~cadb(void){

	//myConn = nullptr;
	delete myConn;
}

// pass in the table, column, and string to match at that column
// and the column you want to get returned as a string
string cadb::getString(const string table, const string column, const string tomatch, const string get){

	string res;
	sql::Statement	*myStmt = nullptr;
	sql::ResultSet	*myRes = nullptr;

	string query = "SELECT * FROM ";
	query += table;
	query += " WHERE ";
	query += column;
	query += " = '";
	query += tomatch;
	query += "';";

	cout << ">> Calling: " << query << endl;

	try{
		myStmt = myConn->createStatement();
		myRes = myStmt->executeQuery(query);

		while (myRes->next()){
			res += myRes->getString(get);
		}
	
	}
	catch (sql::SQLException &e) {

		std::cout << "Failed to execute query" << std::endl;
		std::cout << "Error : " << e.what() << std::endl;
		std::cout << "Error Code : " << e.getErrorCode() << std::endl;
	}

	delete myRes;
	delete myStmt;
	return res;
}


void cadb::setCell(const string table, const string column, const string tomatch, const string setcolumn, const string set){

	sql::Statement	*myStmt = nullptr;
	sql::ResultSet	*myRes = nullptr;
	
	string update = "UPDATE ";
	update += table;
	update += " SET ";
	update += setcolumn;
	update += " = '";
	update += set;
	update += "' WHERE ";
	update += column;
	update += " = '";
	update += tomatch;
	update += "';";
	
	cout << ">> Calling: " << update << endl;
	try{
		myStmt = myConn->createStatement();
		myStmt->executeUpdate(update);
	}
	catch (sql::SQLException &e) {
		std::cout << ">> Failed to execute update" << std::endl;
		std::cout << ">> Error : " << e.what() << std::endl;
		std::cout << ">> Error Code : " << e.getErrorCode() << std::endl;
	}
	delete myRes;
	delete myStmt;
}

//insert INTO sbingham.transaction (trans_date, provider_id, service_id, member_id) 
//values ('2022-09-26', '4', '6', '22');
void cadb::insertVisit(const string date, const int provider_id, const int service_id, const int member_id){
	
	sql::Statement	*myStmt = nullptr;
	sql::ResultSet	*myRes = nullptr;
	
	string insert = "INSERT INTO transaction (trans_date, provider_id, service_id, member_id) VALUES ('";
	insert += date;
	insert += "', '";
	insert += to_string(provider_id);
	insert += "', '";
	insert += to_string(service_id);
	insert += "', '";
	insert += to_string(member_id);
	insert += "');";
		
	cout << ">> Calling: " << insert << endl;
	try{
		myStmt = myConn->createStatement();
		myStmt->executeUpdate(insert);
	}
	catch (sql::SQLException &e) {
		std::cout << ">> Failed to execute update" << std::endl;
		std::cout << ">> Error : " << e.what() << std::endl;
		std::cout << ">> Error Code : " << e.getErrorCode() << std::endl;
	}
	delete myRes;
	delete myStmt;
}
