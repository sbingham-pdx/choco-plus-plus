#include <fstream>
#include <forward_list>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "cadb.h"
using sysclock_t = std::chrono::system_clock;

class m_service
{
	public:
		m_service();
		~m_service();
		void display(); 
		void write(ofstream &);
		void read(const string &, const string &, const string &);
		bool operator<(const m_service &) const;
		bool compare(const m_service &) const;
	protected: 
		string date;
		string service_name; 
		string provider;
};

class p_service
{
	public: 
		p_service();
		~p_service(); 
		float display(); 
		float write(ofstream &); 
		void read(const string &, const string &, const string &, int, 
				int , float);
		bool operator<(const p_service &) const;
		bool compare(const p_service &) const;
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
	

class member_week
{
	public:
		member_week();
		~member_week();
		int run(int, const string & fname = "");

	protected: 
		string name;
		int number; 

		string street; 
		string city; 
		string state; 
		string zip;	
		string begin;
		string end;

		forward_list<m_service> data;

		int display();
		int write(const string &);
		void reset();
};


class provider_week
{
	public:
		provider_week();
		~provider_week();
		int run(int, const string & fname = "");
		int provider_directory(const string & fname = "");

	protected: 
		string name;
		int number; 

		string street; 
		string city; 
		string state; 
		string zip;	
		string begin; 
		string end;

		forward_list<p_service> data;

		int display();
		int write(const string &);
		void reset();
};

class etf_week
{
	public: 
		etf_week();
		~etf_week();
		int run(char = 'B',const string & fname = ""); 
	protected:
		string begin; 
		string end;
		forward_list<provider> data;
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
		forward_list<service> data;

		int display();
		int write(const string & fname);
};

class management
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
