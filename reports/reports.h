#include <fstream>
#include <forward_list>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "cadb.h"
using sysclock_t = std::chrono::system_clock;


// add exception handling for db queries. 
// add exception handling for report classes
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



string date(int offset);
