//#include <assert.h>
//#include <cassert>
#include "cadb.h"
#include <iostream>
#include <cassert>
#include <sys/time.h>
#include <ctime>

using namespace sql;
using namespace std;

void Connector_getString_Success();
void Connector_getString_Failure();
///void Connector_queryDB_Success();
void Connector_getID_Success();
void Connector_getID_Failure();
void Connector_getStatus_Success();
void Connector_getStatus_Failure();
void Connector_setCell_Success();

//void Connector_insertVisit_Success();


void Connector_getString_Success(){
	cout << "Testing valid getString() data..." << endl;
	string compare = "Charlie Day";
	cadb mydb;// new cadb();
	string result = mydb.getString("member", "member_number", "519007290", "member_name");
	assert(!strcmp(compare.c_str(), result.c_str()));
	cout << "Passed!"<< endl;
}

void Connector_getString_Failure(){
	cout << "Testing invalid getString() data..." << endl;
	string compare = "Charlie Day";
	cadb mydb;
	string result = mydb.getString("service", "service_number", "519007290", "member_name");
	assert(result.empty());
	cout << "Passed!"<< endl;
}

/*void Connector_query_Success(){
	cout << "Testing valid query() data..." << endl;
	string compare = "Charlie Day";
	cadb mydb;// new cadb();
	string result = mydb.getString("member", "member_number", "519007290", "member_name");
	assert(!strcmp(compare.c_str(), result.c_str()));
	cout << "Passed!"<< endl;
}*/

void Connector_getID_Success(){
	cout << "Testing valid getID() data..." << endl;
	int compare = 33;
	cadb mydb;// new cadb();
	int result = mydb.getID("member", "519007290");
	assert(compare == result);
	cout << "Passed!"<< endl;
}

void Connector_getID_Failure(){
	cout << "Testing invalid getID() data..." << endl;
	int compare = 0;
	cadb mydb;// new cadb();
	int result = mydb.getID("member", "000000000");
	assert(compare == result);
	cout << "Passed!"<< endl;
}

void Connector_getStatus_Success(){
	cout << "Testing valid getStatus() data..." << endl;
	int compare = 1;
	cadb mydb;
	int result = mydb.getStatus("member", 33);
	assert(compare == result);
	cout << "Passed!"<< endl;
}

void Connector_getStatus_Failure(){
	cout << "Testing invalid getStatus() data..." << endl;
	int compare = -1;
	cadb mydb;
	int result = mydb.getStatus("member", 0);
	assert(compare == result);
	cout << "Passed!"<< endl;
}

void Connector_setCell_Success(){
	cout << "Testing valid setCell() data..." << endl;
	int compare = -3;
	cadb mydb;
	mydb.setCell("member", "id", "33", "isDeleted", "1");
	int result = mydb.getStatus("member", 33);
	assert(compare == result);
	cout << "Passed part 1!"<< endl;
	compare = 1;
	mydb.setCell("member", "id", "33", "isDeleted", "0");
	result = mydb.getStatus("member", 33);
	assert(compare == result);
	cout << "Passed part 2!" << endl;
}

//void Connector_insertVisit_Success(){

//}


int
main()
{
	Connector_getString_Success();
	Connector_getString_Failure();
	Connector_getID_Success();
	Connector_getID_Failure();
	Connector_getStatus_Success();
	Connector_getStatus_Failure();
	Connector_setCell_Success();
	return 0;
};
