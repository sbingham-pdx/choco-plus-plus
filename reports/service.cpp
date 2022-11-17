#include "reports.h" 

member_service:: member_service()
{
}

member_service:: ~member_service()
{
}

void member_service::display()
{
	cout << left << setw(13) << date << left << setw(20)<<  service_name 
	     << "\t" << provider;
	return;
}

void member_service::write(ofstream & file)
{
	if(!file) return;

	file << date << "," << service_name << "," << provider;

	return; 
}

void member_service::read(const string & ndate, const string & nservice, const string & nprovider)
{
	date = ndate;
       	service_name = nservice; 
	provider = nprovider; 
	
	return; 
}

bool member_service::operator<(const member_service & two) const
{
	return compare(two); 
}

bool member_service::compare(const member_service & two) const
{
	string dates[2][3];
	stringstream temp(date); 
	stringstream temp2(two.date);

	if(date == "") return true; 
	if(two.date == "") return false; 

	for(int i =0; i<3 && !temp.eof() && !temp2.eof(); ++i)
	{
		int d1 =0, d2 =0;
		getline(temp,dates[0][i],'-');
		getline(temp2,dates[1][i],'-');
		
		d1 = stoi(dates[0][i]);
		d2 = stoi(dates[1][i]);
		
		if(d1<d2) return true;
		else if(d1>d2) return false;	
	}
	return false;
}

/******************** provider_service *********************/

provider_service:: provider_service()
{
	fee  = 0.0;
	mnumber = service_code = 0;
}

provider_service:: ~provider_service()
{
}

float provider_service::display()
{
	cout << left << setw(13) << sdate
	     << left << setw(20) << rdate
	     << left << setw(25) << mname 
	     << left << setw(14) << mnumber
	     << left << setw(13) << service_code
	     << "$" << left << setw(10) << fee;
	return fee;
}

float provider_service::write(ofstream & file)
{
	if(!file) return 0;

	file << sdate << "," << rdate << "," << mname << "," << mnumber << "," << service_code
	     << "," << fee;
	return fee;
}

void provider_service::read(const string & nsdate, const string & nrdate, const string & nmname,
	       		int nmnumber, int sc, float nfee)
{
	sdate = nsdate; 
	rdate = nrdate;
	mname = nmname; 
	mnumber = nmnumber; 
	service_code = sc; 
	fee = nfee;
	return;
}

bool provider_service::operator<(const provider_service & two) const
{
	return compare(two); 
}

bool provider_service::compare(const provider_service & two) const
{
	string date[2][3];
	stringstream temp(sdate); 
	stringstream temp2(two.sdate);

	if(sdate == "") return true; 
	if(two.sdate == "") return false; 

	for(int i =0; i<3 && !temp.eof() && !temp2.eof(); ++i)
	{
		int d1 =0, d2 =0;
		getline(temp,date[0][i],'-');
		getline(temp2,date[1][i],'-');
		
		d1 = stoi(date[0][i]);
		d2 = stoi(date[1][i]);
		
		if(d1<d2) return true;
		else if(d1>d2) return false;	
	}
	return false;
}

/*************** date *****************************/ 

string date(int offset)
{
	char date[17]={0};

	std::time_t now = sysclock_t::to_time_t(sysclock_t::now());
	now -=(60*60*24*offset);

	std::strftime(date,sizeof(date), "%Y-%m-%d", std::localtime(&now));

	return string(date);
}

	
/************* provider *****************************/

provider:: provider()
{
	total = scount = 0;
}

provider:: ~provider()
{
}

float provider::display(char type, int & service_count)
{
	cout  << number << "\t\t" << name << "\t\t";
	if(type == 'A')
		cout << scount << "\t\t";
	cout << total; 
	service_count += scount;
	return total;
}

float provider::write(char type, ofstream & file, int & service_count)
{
	if(!file) return 0; 

	file  << number << "," << name << ",";
	if(type == 'A')
		file << scount << ",";
	file << total; 
	service_count += scount;
	return total;
}

void provider:: read(const string & nname, int nnumber, int nscount, float ntotal)
{
	name = nname; 
	number = nnumber; 
	scount = nscount;
	total = ntotal; 
	return;
}

int provider:: compare(float sum) const
{
	return compare_float(sum,total);
}

int provider:: compare_provider(int pn) const
{
	if(pn != number) return 0; 
	return 1;
}
/**************** service ***********************************/ 


service:: service()
{
}

service:: ~service()
{
}

void service:: display()
{
	cout << left << setw(24) << name
	     << left << setw(15) << service_code
	     << left << setw(14) << fee;
	return; 
}

void service:: write(ofstream & file)
{
	if(!file) return;

	file << name << ","
	     << service_code << ","
	     << fee;
	return; 
}

void service:: read(const string & nname, int nservice_code, float nfee)
{
	name = nname; 
	service_code = nservice_code; 
	fee = nfee;

	return;
}


bool service:: operator<(const service & two) const
{
	if(name < two.name) return true; 
	return false; 
}


/***************** trannsaction ID **********************/

t_id:: t_id()
{
}

t_id:: ~t_id()
{
}

float t_id:: display()
{
	cout << left << setw(24) << provider_number
	     << left << setw(15) << id
	     << left << setw(14) << fee;
	return fee;
}

float t_id:: write(ofstream & file)
{
	if(!file) return 0;

	file << provider_number<< ","
	     << id << ","
	     << fee;
	return fee;
}

void t_id:: read(int pn, int tid, float nfee)
{
	provider_number = pn;
	id = tid; 
	fee = nfee;

	return;
}


bool t_id:: operator<(const t_id & two) const
{
	if(provider_number < two.provider_number) return true; 
	return false; 
}

float t_id:: get_cost() const
{
	return fee;
}

int t_id:: compare_provider(const provider & to_comp) const
{
	return to_comp.compare_provider(provider_number);
}

bool compare_float(float x, float y, float epsilon)
{
   if(fabs(x - y) < epsilon)
      return true;
   return false;
}
