#include <fstream>
#include <forward_list>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "cadb.h"
using sysclock_t = std::chrono::system_clock;


// All classes defined in the this file are written specifically
// for the reporting functionality.
// The member_report, provider_report, and management report classes are the only 
// ones dessigned to be utilized by client/terminal. 

// The member service class handles service record
// data pulled from the database for the individual 
// member report. 
// Data Members: 
//				date: the data the service was provided
//				service_name: the name of the service
//				provider: the provider who provided the service

class member_service
{
	public:
		member_service();
		~member_service();
		void display(); 
		void write(ofstream &);
		void read(const string &, const string &, const string &);
		bool operator<(const member_service &) const;
		bool compare(const member_service &) const;
	protected: 
		string date;
		string service_name; 
		string provider;
};

// The provider service class handles service record
// data pulled from the database for the individual 
// provider report. 
// Data Members: 
//				sdate: the data the service was provided
//				rdate: the date the service was recorded
//				mname: the name of the member who received the
//						service.
//				mnumber: the member number of the member who received
//						 the service. 
//				service_code: the code of the service provided
//				fee: the cost of the service provided

class provider_service
{
	public: 
		provider_service();
		~provider_service(); 
		float display(); 
		float write(ofstream &); 
		void read(const string &, const string &, const string &, int, 
				int , float);
		bool operator<(const provider_service &) const;
		bool compare(const provider_service &) const;
	protected: 
		string sdate; 
		string rdate; 
		string mname; 
		int mnumber; 
		int service_code; 
		float fee; 
};

// The  service class handles the service option
// data pulled from the database for the service directory. 
// Data Members: 
//				name: the name of the service
//				service_code: the code of the service provided
//				fee: the cost of the service provided

class service
{
	public: 
		service(); 
		~service(); 
		 void display(); 
		 void write(ofstream &); 
		 void read(const string &, int, float);
		 bool operator<(const service &)  const;
	protected: 
		string name;
		int service_code; 
		float fee; 
};

// The provider class handles the provider payable data
// pulled from the database for the AP report/eft report. 
// Data Members: 
//				name: the provider name
//				number: the provider number
//				scount: the count of services rendered
//				total: the total owed the the provider for the week. 

class provider
{
	public: 
		provider(); 
		~provider();
		float display(char, int &);
		float write(char, ofstream &, int &);
		void read(const string&, int , int, float);
	protected:
		string name;
		int number; 
		int scount;
		float total;
};
	

// The member report class handles generating and outputing the indivudal 
// member report. 
// Client Methods: 
//				Run:   Purpose: runs the report base on the Member Number
//								 passed in by the user 
//					   Arguments: Member Number(int), the member who's weekly 
//								  service report should be run. 
//								  fname: the name of the file where the report should be 
//										 stored (.csv will automtically be added end).
//										 File will be overwritten. 
class member_report
{
	public:
		member_report();
		~member_report();
		int run(int, const string & fname = "");

	protected: 
		string name;
		int number; 

		string street; 
		string city; 
		string state; 
		string zip;	
		string start_date;
		string end_date;

		forward_list<member_service> member_service_list;

		int display();
		int write(const string &);
		void reset();
};

// The provider report class handles generating and outputing the indivudal 
// provider report, and the service directory.
// Client Methods: 
//				Run:   Purpose: runs the report base on the Provider Number
//								 passed in by the user 
//					   Arguments: Provider Number(int), the provider who's weekly 
//								  service report should be run. 
//								  fname: the name of the file where the report should be 
//										 stored (.csv will automtically be added end).
//										 File will be overwritten. 
//	provider_directory:	Purpose: generates the service directory. 
//						Arguments: fname: the name of the file where the report should be 
//										 stored (.csv will automtically be added end).
//										 File will be overwritten. 		

class provider_report
{
	public:
		provider_report();
		~provider_report();
		int run(int, const string & fname = "");
		int provider_directory(const string & fname = "");

	protected: 
		string name;
		int number; 

		string street; 
		string city; 
		string state; 
		string zip;	
		string start_date; 
		string end_date;

		forward_list<provider_service> provider_service_list;

		int display();
		int write(const string &);
		void reset();
};


// The accounting report class handles generating and outputing the AP and EFT 
// reports.
// Client Methods: None, only meant to be utilized by the management class. 
class accounting_report
{
	public: 
		accounting_report();
		~accounting_report();
		int run(char = 'B',const string & fname = ""); 
	protected:
		string start_date; 
		string end_date;
		forward_list<provider> provider_list;
		int display(char); 
		int write(char, const string &); 
};

// The service_directory class handles generating and outputing the service
// directory.
// Client Methods: None, only meant to be utilized by the management class, and 
//				   provider class. 
class service_directory
{
	public:
		service_directory();
		~service_directory(); 
		int run(const string & fname = "");
	protected: 
		forward_list<service> service_list;

		int display();
		int write(const string & fname);
};

// The management class handles generating and outputing all management reports
// Including: 
//			All_providers: 
//			individual_provider:
//			All_members:
//			individual_member: 
//			Ap_report: 
//			EFT_report: 
// 			provider_directory: 
class management_report
{
	public: 
		int all_providers(const string & fname = ""); 
		int individual_provider(int, const string & fname = "");
		int all_members(const string & fname = ""); 
		int individual_member(int,const string & fname = ""); 
		int ap_report(const string & fname = "");
		int etf_report(const string & fname = ""); 
		int provider_directory(const string & fname = "");
	protected: 
};


//used to determine report dates, based on current system date. 
string date(int offset);
