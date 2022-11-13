#include "cadb.h"

// This function serves to initialize and begin the connection 
// to the default database. 
cadb::cadb(void){
	caDriver = nullptr;
	caConn = nullptr;
	// Initialize MySQL Driver Instance
	// Set connection to the Driver
	// And Log In
	try{
		caDriver = get_driver_instance();
		caConn = caDriver->connect("db.cecs.pdx.edu", "sbingham", "x6Tcbcs5*a");
		caConn->setSchema("sbingham");
	}
	catch (sql::SQLException &e) {
		std::cout << "Failed to Connect to MySql DB 'sbingham'" << std::endl;
		std::cout << "Error : " << e.what() << std::endl;
		std::cout << "Error Code : " << e.getErrorCode() << std::endl;
	}
}

// This function serves to delete the connection
// when the objects life has ended. 
cadb::~cadb(void){
	delete caConn;
}

// This Function serves as a primary means of 
// executing SQL commands, -NOT- queries. More specific
// functions should build their string first, then 
// call "execute(string);" 
void cadb::execute(const string statement){

	sql::Statement	*caStmt = nullptr;
	sql::ResultSet	*caRes = nullptr;

	try{
		caStmt = caConn->createStatement();
		caStmt->executeUpdate(statement);
	}
	catch (sql::SQLException &e) {
		std::cout << ">> Failed to execute statement:" << statement << std::endl;
		std::cout << ">> Error : " << e.what() << std::endl;
		std::cout << ">> Error Code : " << e.getErrorCode() << std::endl;
	}
	
	delete caRes;
	delete caStmt;
}

// This Function serves as a primary means of
// executing SQL queries, -NOT- commands. More speficic
// functions should build their string first, then call
// "queryDB(string, ResPTR)"
void cadb::queryDB(const string statement, sql::ResultSet *& foRes){
	sql::Statement	*caStmt = nullptr;
	
	try{
		caStmt = caConn->createStatement();
		foRes = caStmt->executeQuery(statement);
	}
	catch (sql::SQLException &e) {
		std::cout << ">> Failed to execute statement:" << statement << std::endl;
		std::cout << ">> Error : " << e.what() << std::endl;
		std::cout << ">> Error Code : " << e.getErrorCode() << std::endl;
	}
	
	delete caStmt;
}

// pass in the table, column, and string to match atcl that column
// and the column you want to get returned as a string
string cadb::getString(const string table, const string column, const string tomatch, const string getcolumn){

	string res;
	sql::Statement	*caStmt = nullptr;
	sql::ResultSet	*caRes = nullptr;
	//Build your query string
	string query = "SELECT * FROM ";
	query += table;
	query += " WHERE ";
	query += column;
	query += " = '";
	query += tomatch;
	query += "';";

	cout << ">> Calling: " << query << endl;
	
	// Execute the Query
	queryDB(query, caRes);
	// Load query into string.
	try{
		while (caRes->next()){
			res += caRes->getString(getcolumn);
		}
	}
	catch (sql::SQLException &e) {
		std::cout << "Failed to execute query" << std::endl;
		std::cout << "Error : " << e.what() << std::endl;
		std::cout << "Error Code : " << e.getErrorCode() << std::endl;
	}

	delete caRes;
	delete caStmt;

	return res;
}

// This function serves to set a specific cell of a table based on the 
// following SQL Call: 
// >> UPDATE table SET setcolumn = 'set' WHERE column = 'tomatch';
void cadb::setCell(const string table, const string column, const string tomatch, const string setcolumn, const string set){
	//Build your query string
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

	execute(update);
}

// This function serves to find a match on the specified column
// on the specified table. if a match is found, this function returns
// a 0 if no match is found, and the number of matches if they are found
int cadb::findMatch(const string table, const string column, const string tomatch){
	int matchfound = 0;

	sql::Statement	*caStmt = nullptr;
	sql::ResultSet	*caRes = nullptr;

	string res;

	string query = "SELECT * ";
	//query += column;
	query += " FROM ";
	query += table;
	query += " WHERE ";
	query += column;
	query += " = '";
	query += tomatch;
	query += "';";
	//query += ";";
	
	cout << ">> Calling: " << query << endl;

	queryDB(query, caRes);

	try{
		while (caRes->next()){
			res.clear();
			res = caRes->getString(column);
			if (!strcmp(res.c_str(), tomatch.c_str())) matchfound += 1;
		}
	}
	catch (sql::SQLException &e) {
		std::cout << ">> Failed to execute statement:" << query << std::endl;
		std::cout << ">> Error : " << e.what() << std::endl;
		std::cout << ">> Error Code : " << e.getErrorCode() << std::endl;
	}
	delete caRes;
	delete caStmt;

	return matchfound;

}

// This function serves to count the # of rows in 
// the table passed to it as a string.
int cadb::getRows(const string table){

	sql::Statement	*caStmt = nullptr;
	sql::ResultSet	*caRes = nullptr;
	string query = "SELECT id FROM ";
	query += table;
	query += ";";
	int ret = 0;
	int biggest = 0;

	cout << ">> Calling: " << query << endl;

	queryDB(query, caRes);
	try{
		while (caRes->next()){
			ret = caRes->getInt(1);
			if (ret > biggest) biggest = ret;
		}
		}
	catch (sql::SQLException &e) {
		std::cout << ">> Failed to execute statement:" << query << std::endl;
		std::cout << ">> Error : " << e.what() << std::endl;
		std::cout << ">> Error Code : " << e.getErrorCode() << std::endl;
	}
	delete caRes;
	delete caStmt;
	return biggest;
}

int cadb::getID(const string table, const string tomatch){

	int id = 0;

	if (table.empty() || tomatch.empty()) return id;

	if (strcmp(table.c_str(), "provider") && strcmp(table.c_str(), "member") && strcmp(table.c_str(), "service")) return id;
	
	if (!strcmp(table.c_str(), "provider") || !strcmp(table.c_str(), "member")){
		if (tomatch.length() != 9 || tomatch.empty()) {
			std::cout << ">> ERROR: Identity Number must be 9 digits. Identity Number: " << tomatch << " is invalid." << std::endl;
			return id;
		}
	}
	if (!strcmp(table.c_str(), "service")){
		if (tomatch.length() != 6 || tomatch.empty()) {
			std::cout << ">> ERROR: Service Number must be 9 digits. Service Number: " << tomatch << " is invalid." << std::endl;
			return id;
		}
	}
	

	sql::Statement	*caStmt = nullptr;
	sql::ResultSet	*caRes = nullptr;

	string query = "SELECT * FROM ";
	query += table;
	query += " WHERE ";
	query += table;
	query += "_number = '";
	query += tomatch;
	query += "';";

	cout << ">> Calling: " << query << endl;

	queryDB(query, caRes);

	try{
		while (caRes->next()){
			id = caRes->getInt(1);
		}
	}
	catch (sql::SQLException &e) {
		std::cout << ">> Failed to execute statement:" << query << std::endl;
		std::cout << ">> Error : " << e.what() << std::endl;
		std::cout << ">> Error Code : " << e.getErrorCode() << std::endl;
	}
	delete caRes;
	delete caStmt;
	return id;
}















// This function serves to input a visit to the transaction table
//>> INSERT INTO transaction (trans_date, provider_id, service_id, member_id) 
//>> VALUES ('date', 'provider_id', 'service_id', 'member_id');
void cadb::insertVisit(const string date, const int provider_id, const int service_id, const int member_id, const string comments){

	// Error checking in here to make sure that transactions map to correct bounds of other tables.
	if ( provider_id <= 1 || provider_id > getRows("provider") ){
		std::cout << "ERROR: Provider ID outside of range:" << provider_id << std::endl;
		return;
	}

	if ( service_id <= 1 || service_id > getRows("service") ){
		std::cout << "ERROR: Service ID outside of range:" << service_id << std::endl;
		return;
	}

	if ( member_id <= 1 || member_id > getRows("member") ){
		std::cout << "ERROR: Member ID outside of range:" << member_id << std::endl;
		return;
	}
	if (comments.length() > 100 || comments.empty()) {
		std::cout << ">> ERROR: Comments must be 100 characters or less. Comments entered: " << comments << " is invalid." << std::endl;
		return;
	}
	
	//Build your query string
	string insert = "INSERT INTO transaction (trans_date, provider_id, service_id, member_id, comments) VALUES ('";
	insert += date;
	insert += "', '";
	insert += to_string(provider_id);
	insert += "', '";
	insert += to_string(service_id);
	insert += "', '";
	insert += to_string(member_id);
	insert += "', '";
	insert += comments;
	insert += "');";

	cout << ">> Calling: " << insert << endl;
	
	execute(insert);
}

// This function will error check the inputs provided 
// before building the execute statement, then calling execute(statement);
void cadb::insertProvider(const string number, const string name, const string street, const string city, const string state, const string zip){
	if (number.length() != 9 || number.empty()) {
		std::cout << ">> ERROR: Provider Number must be 9 digits. Provider Number: " << number << " is invalid." << std::endl;
		return;
	}
	if (name.length() > 25 || name.empty()) {
		std::cout << ">> ERROR: Provider Name must be less than 25 characters. Provider Name: " << name << " is invalid." << std::endl;
		return;
	}
	if (street.length() > 25 || street.empty()) {
		std::cout << ">> ERROR: Provider Street address must be less than 25 characters. Provider Steet Address: " << street << " is invalid." << std::endl;
		return;
	}
	if (city.length() > 14 || city.empty()) {
		std::cout << ">> ERROR: Provider City must be less than 14 characters. Provider City: " << city << " is invalid." << std::endl;
		return;
	}
	if (state.length() != 2 || state.empty()) {
		std::cout << ">> ERROR: Provider State must be 2 characters. Provider State: " << state << " is invalid." << std::endl;
		return;
	}
	if (zip.length() != 5 || zip.empty()) {
		std::cout << ">> ERROR: Provider Zipcode must be 5 characters. Provider Zipcode: " << zip << " is invalid." << std::endl;
		return;
	}
	// Put in error check for matching provider_number here - make universal
	// check for match
	if (findMatch("provider", "provider_number", number)){
		std::cout << ">> ERROR: Provider Number:" << number << " is already in use." << std::endl;
		return;
	}

	//Build your query string
	string insert = "INSERT INTO provider (provider_number, provider_name, provider_street, provider_city, provider_state, provider_zip) VALUES ('";
	insert += number;
	insert += "', '";
	insert += name;
	insert += "', '";
	insert += street;
	insert += "', '";
	insert += city;
	insert += "', '";
	insert += state;
	insert += "', '";
	insert += zip;
	insert += "');";

	cout << ">> Calling: " << insert << endl;
	execute(insert);

}

// This function will error check the inputs provided 
// before building the execute statement, then calling execute(statement);
void cadb::insertMember(const string number, const string name, const string street, const string city, const string state, const string zip){
	if (number.length() != 9 || number.empty()) {
		std::cout << ">> ERROR: Member Number must be 9 digits. Member Number: " << number << " is invalid." << std::endl;
		return;
	}
	if (name.length() > 25 || name.empty()) {
		std::cout << ">> ERROR: Member Name must be less than 25 characters. Member Name: " << name << " is invalid." << std::endl;
		return;
	}
	if (street.length() > 25 || street.empty()) {
		std::cout << ">> ERROR: Member Street address must be less than 25 characters. Member Steet Address: " << street << " is invalid." << std::endl;
		return;
	}
	if (city.length() > 14 || city.empty()) {
		std::cout << ">> ERROR: Member City must be less than 14 characters. Member City: " << city << " is invalid." << std::endl;
		return;
	}
	if (state.length() != 2 || state.empty()) {
		std::cout << ">> ERROR: Member State must be 2 characters. Member State: " << state << " is invalid." << std::endl;
		return;
	}
	if (zip.length() != 5 || zip.empty()) {
		std::cout << ">> ERROR: Member Zipcode must be 5 characters. Member Zipcode: " << zip << " is invalid." << std::endl;
		return;
	}
	
	// check for matching number
	if (findMatch("member", "member_number", number)){
		std::cout << ">> ERROR: Member Number:" << number << " is already in use." << std::endl;
		return;
	}

	//Build your query string
	string insert = "INSERT INTO member (member_number, member_name, member_street, member_city, member_state, member_zip) VALUES ('";
	insert += number;
	insert += "', '";
	insert += name;
	insert += "', '";
	insert += street;
	insert += "', '";
	insert += city;
	insert += "', '";
	insert += state;
	insert += "', '";
	insert += zip;
	insert += "');";

	cout << ">> Calling: " << insert << endl;
	execute(insert);

}

void cadb::insertService(const string number, const string name, const string cost){
	if (number.length() != 6 || number.empty()) {
		std::cout << ">> ERROR: Service Number must be 6 digits. Service Number: " << number << " is invalid." << std::endl;
		return;
	}
	if (name.length() > 20 || name.empty()) {
		std::cout << ">> ERROR: Service Name must be 20 characaters or less. Service Name: " << name << " is invalid." << std::endl;
		return;
	}
	if (cost.length() > 6 || cost.empty()) {
		std::cout << ">> ERROR: Service Name must be 20 characaters or less. Service Name: " << name << " is invalid." << std::endl;
		return;
	}
	/*if (cost >= 1000 || !cost) {
		std::cout << ">> ERROR: Service cost must be between $0 and $999.99. Service cost: " << cost << " is invalid." << std::endl;
		return;
	}*/
	// check for matching number
	if (findMatch("service", "service_number", number)){
		std::cout << ">> ERROR: Service Number:" << number << " is already in use." << std::endl;
		return;
	}
	//Build your query string
	string insert = "INSERT INTO service (service_number, service_name, service_cost) VALUES ('";
	insert += number;
	insert += "', '";
	insert += name;
	insert += "', '";
	insert += cost;
	insert += "');";
	cout << ">> Calling: " << insert << endl;
	execute(insert);
}


