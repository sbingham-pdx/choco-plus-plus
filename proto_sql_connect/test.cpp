#include "cadb.h"

int
main()
{
	std::cout << "\n>> Start C++ connect mysql test example \n";

	cadb mydb;

	string s1 = "469898441";
	string s2 = "Jack Ransom";
	string s3 = "1452 Ready Room Way";
	string s4 = "Cerritos";
	string s5 = "CA";
	string s6 = "75567";
	//cout << "calling database" << endl;
	//cout << mydb.getString(s1, s2, s3, s4) << endl;
	//cout << "database call done" << endl;
	//cout << "setting cell" << endl;
	//mydb.setCell(s1, s2, s3, s4, s5);
	//cout << "set cell done" << endl;
	//cout << "calling database again:" << endl;
	//cout << mydb.getString(s1, s2, s3, s4) << endl;
	//cout << "database call done" << endl;

	int i = mydb.getRows("provider");

	cout << "The # of rows in " << "provider" << " equals: " << i << endl;

	//mydb.insertProvider(s1, s2, s3, s4, s5, s6);

	i = mydb.getRows("provider");

	cout << "The # of rows in " << "provider" << " equals: " << i << endl;

	

	//mydb.insertVisit("2022-11-1", provider_id, service_id, member_id);
	return 0;
};
