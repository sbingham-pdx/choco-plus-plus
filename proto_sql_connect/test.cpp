#include "cadb.h"

int
main()
{
	std::cout << "Start C++ connect mysql test example \n";

	cadb mydb;

	string s1 = "provider";
	string s2 = "id";
	string s3 = "3";
	string s4 = "provider_name";

	cout << mydb.getString(s1, s2, s3, s4) << endl;

	return 0;
};