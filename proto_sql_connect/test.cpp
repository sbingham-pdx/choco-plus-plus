#include "cadb.h"

int
main()
{
	std::cout << "\n>> Start C++ connect mysql test example \n";

	cadb mydb;

	string s1 = "provider";
	string s2 = "823677843";
	string f1 = "325.65";
	cout << "length of string is: " << f1.length();

	int i = mydb.getID(s1, s2);

	cout << "ID of " << s1 << ": " << s2 << " = " << i << endl;
	/*tring s3 = "654652 Whatsup Lanne";
	string s4 = "Peoria";
	string s5 = "IL";
	string s6 = "61525";*/
	//cout << "calling database" << endl;
	//cout << mydb.getString(s1, s2, s3, s4) << endl;
	//cout << "database call done" << endl;
	//cout << "setting cell" << endl;
	//mydb.setCell(s1, s2, s3, s4, s5);
	//cout << "set cell done" << endl;
	//cout << "calling database again:" << endl;
	//cout << mydb.getString(s1, s2, s3, s4) << endl;
	//cout << "database call done" << endl;

	//int i = mydb.findMatch("provider","provider_city", "Cerritos");

	//if (i) cout << "Found "<< i << " instances of Cerritos!" << endl;
	//else cout << "Did not find jack" << endl;

	//cout << "The # of rows in " << "provider" << " equals: " << i << endl;

	//mydb.insertService(s1, s2, f1);

	//i = mydb.getRows("provider");

	//cout << "The # of rows in " << "provider" << " equals: " << i << endl;

	

	//mydb.insertVisit("2022-11-1", provider_id, service_id, member_id);
	return 0;
};
