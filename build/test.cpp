//#include <assert.h>
//#include <cassert>
#include "structures.h"
#include <iostream>
#include <cassert>

using namespace sql;
using namespace std;

int counter;

void test_Out();

void Connector_getString_Success();
void Connector_getString_Failure();
//void Connector_queryDB_Success();
void Connector_getID_Success();
void Connector_getID_Failure();
void Connector_getStatus_Success();
void Connector_getStatus_Failure();
void Connector_setCell_Success();

void readVisit();
void readService();

// REPORTS CLASS TESTs
void Reports_All_Providers_Success();
void Reports_Ind_Provider_Success();
void Reports_All_Members_Success();
void Reports_Ind_Member_Success();
void Reports_Ind_Member_Bad_ID();
void Reports_Ind_Provider_Bad_ID();
void AP_Report_Success();
void EFT_Report_Success();
void Directory_Sucess();
void Batch_Paid_Success();
void Batch_Unpaid_Success();
void Batch_Paid_Bad_File();

void test_Out(){
	counter += 1;
	cout << "\n\n\n\n\n=================================================" << endl;
	cout << "\t\tTEST NUMBER: " << counter << endl;
	cout << "=================================================" << endl; 
}

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


//READ TESTS
void readVisit()
{
	cout << "Feeding visit structs with junk data" << endl;
	visit testVisit;
	assert(!testVisit.read("01/20/22", -111, -1, -3221, "Junk", 1.0));
	cout << "Passed!"<< endl;
}

void readService()
{
	cout << "Feeding service structs with junk data" << endl;
	service testService;
	assert(!testService.read("1234", "Random", -1.0));
	cout << "Passed!"<< endl;
}

//REPORTS TESTS
void Reports_All_Providers_Success()
{
    ifstream file;
    management_report obj;

    obj.all_providers(); 
    
    file.open(date(0)+"_all_providers.csv");

    assert(file);

    file.peek();

    assert(!file.eof());

    file.close();

    cout << "Passed" << endl; 
}

void Reports_Ind_Provider_Success()
{

    ifstream file;
    management_report obj;

    obj.individual_provider(158452334); 
    
    file.open(date(0)+"_158452334_report.csv");

    assert(file); 
    
    file.peek();

    assert(!file.eof());

    file.close();

    cout << "Passed" << endl; 
}

void Reports_All_Members_Success()
{
    ifstream file;
    management_report obj;

    obj.all_members(); 
    
    file.open(date(0)+"_all_members.csv");

    assert(file);

    file.peek();

    assert(!file.eof());

    file.close();

    cout << "Passed" << endl; 

}

void Reports_Ind_Member_Success()
{
    ifstream file;
    management_report obj;

    obj.individual_member(631375719); 
    
    file.open(date(0)+"_631375719_report.csv");

    assert(file);

    file.peek();

    assert(!file.eof());

    file.close();

    cout << "Passed" << endl; 

}

void Reports_Ind_Member_Bad_ID()
{
    ifstream file;
    management_report obj;

    obj.individual_member(631375); 
    
    file.open(date(0)+"_6313757190_report.csv");

    assert(!file);

    file.close();

    cout << "Passed" << endl; 
}

void Reports_Ind_Provider_Bad_ID()
{
    ifstream file;
    management_report obj;

    obj.individual_provider(631); 
    
    file.open(date(0)+"_6313757190_report.csv");

    assert(!file);

    file.close();

    cout << "Passed" << endl; 
}

void AP_Report_Success()
{
    ifstream file;
    management_report obj;

    obj.ap_report();
    
    file.open(date(0)+"_ap_report.csv");

    assert(file);

    file.peek();

    assert(!file.eof());

    file.close();

    cout << "Passed" << endl; 
}

void EFT_Report_Success()
{
    ifstream file;
    ifstream file2;
    management_report obj;

    obj.eft_report();
    
    file.open(date(0)+"_eft_report.csv");
    file.open(date(0)+"_eft_detailed_report.csv");

    assert(file && file2);

    file.peek(); 
    file2.peek();

    assert(!file.eof() && !file.eof());

    file.close();
    file2.close();

    cout << "Passed" << endl; 
}

void Directory_Sucess()
{
    ifstream file;
    management_report obj;

    obj.provider_directory();
    
    file.open(date(0)+"_provider_directory.csv");

    assert(file);

    file.peek();

    assert(!file.eof());

    file.close();

    cout << "Passed" << endl; 

}

void Batch_Paid_Success()
{
    ifstream f1, f2;
    management_report obj;

    obj.eft_report();

    assert(obj.batch_mark_paid(date(0)+"_eft_detailed_report"));

    f1.open(date(0) + "_eft_detailed_report_payment_status_updated.csv");
    f2.open(date(0) + "_eft_detailed_report.csv");

    assert(f1 && f2);

    assert(comparefiles(f1, f2));

    f1.close(); 
    f2.close();

    cout << "Passed" << endl;
}

void Batch_Unpaid_Success()
{
    ifstream f1, f2;
    management_report obj;

    assert(obj.batch_mark_paid(date(0)+"_eft_detailed_report",0));

    f1.open(date(0) + "_eft_detailed_report_payment_status_updated.csv");
    f2.open(date(0) + "_eft_detailed_report.csv");

    assert(f1 && f2);

    assert(comparefiles(f1, f2));

    f1.close(); 
    f2.close();

    cout << "Passed" << endl;
}

void Batch_Paid_Bad_File()
{
    management_report obj;

    assert(!obj.batch_mark_paid(date(0)+"eft_detailed_report"));
    assert(!obj.batch_mark_paid("1900-12-21_eft_detailed_report"));
    assert(!obj.batch_mark_paid("2022-14-21_eft_detailed_report"));
    assert(!obj.batch_mark_paid("2022-14-51_eft_detailed_report"));

    cout << "Passed" << endl;
}

int
main()
{
	counter = 0;
	
	test_Out();
	Connector_getString_Success();
	test_Out();
	Connector_getString_Failure();
	test_Out();
	Connector_getID_Success();
	test_Out();
	Connector_getID_Failure();
	test_Out();
	Connector_getStatus_Success();
	test_Out();
	Connector_getStatus_Failure();
	test_Out();
	Connector_setCell_Success();
	
	test_Out();
	readVisit();
	test_Out();
	readService();

	test_Out();
	Reports_All_Providers_Success();
	test_Out();
   	Reports_Ind_Provider_Success();
	test_Out();
  	Reports_All_Members_Success();
	test_Out();
	Reports_Ind_Member_Success();
	test_Out();
	Reports_Ind_Member_Bad_ID();
	test_Out();
	Reports_Ind_Provider_Bad_ID();
	test_Out();
	AP_Report_Success();
	test_Out();
	EFT_Report_Success();
	test_Out();
	Directory_Sucess();
	
	
	//bellow two tests need to be run together and in order.
	test_Out();
	Batch_Paid_Success();
	
	test_Out();
	Batch_Unpaid_Success();
	
	
	test_Out();
	Batch_Paid_Bad_File();

	cout << "Cleaning up generated files..." << endl;
	system("rm -fv *.csv");
		
	return 0;
};
