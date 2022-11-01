#include "cadb.h"

int
main()
{
	std::cout << "\n>> Start C++ connect mysql test example \n";

	cadb mydb;

	string s1 = "provider";
	string s2 = "id";
	string s3 = "2";
	string s4 = "provider_city";
	string s5 = "Delta Flyer";
	//cout << "calling database" << endl;
	cout << mydb.getString(s1, s2, s3, s4) << endl;
	//cout << "database call done" << endl;
	//cout << "setting cell" << endl;
	mydb.setCell(s1, s2, s3, s4, s5);
	//cout << "set cell done" << endl;
	//cout << "calling database again:" << endl;
	cout << mydb.getString(s1, s2, s3, s4) << endl;
	//cout << "database call done" << endl;

	int provider_id = 6;
	int service_id = 7;
	int member_id = 13;

	//mydb.insertVisit("2022-10-17", provider_id, service_id, member_id);
	return 0;
};
