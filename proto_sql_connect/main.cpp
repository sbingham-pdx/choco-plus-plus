#include "cadb.h"
#include <sys/time.h>
#include <ctime>

int
main()
{
	std::cout << "\n>> Start C++ connect mysql test example \n";
	cadb mydb;

	struct timeval start_time;
	gettimeofday(&start_time, NULL);

	cout << "Unix timestamp is: " << start_time.tv_usec << endl;
	srand(start_time.tv_usec);


	time_t now = time(0);

	tm *ltm = localtime(&now);

	string thisyear = to_string(1900 + ltm->tm_year);
	string thismonth = to_string(1 + ltm->tm_mon);
	string today = to_string(ltm->tm_mday);

	string date = thisyear + "-" + thismonth + "-" + today;
	//string date = "2022-11-27";

	cout << "today's date is: " << date << endl;

#ifdef TEST
	//cout << "Define test worked!" << endl;
#endif // TEST
	//int charliestatus = mydb.getStatus("member", 33);

	//cout << start_time.tv << endl;

	/*int provider_id = 0;//(rand() % 25) + 1;
	int service_id = 0; //(rand() % 15) + 1;
	int member_id = 0;//(rand() % 31) + 1;
	

	string comments = "Autogenerated test comment from Sam Bingham";
	
	int visits_per_day = (rand() % 15) + 15;
	
	for (int i = 0; i < visits_per_day; ++i){
		//date.clear();// = NULL;
		provider_id = (rand() % 25) + 2;
		service_id = (rand() % 16) + 2;
		member_id = (rand() % 31) + 2;
	
		mydb.insertVisit(date, provider_id, service_id, member_id, comments);
	}*/
	

	

	
	
	return 0;
};
