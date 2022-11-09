#include "reports.h"


accounting_report:: accounting_report()
{
}

accounting_report:: ~accounting_report()
{
}

int accounting_report::run(char type, const string & fname)
{
	string query; 
	sql::ResultSet *res; 
	cadb db;
	provider temp;

	provider_list.clear();

	start_date = date(6); 
	end_date = date(0); 

	query = "SElECT a.provider_name, a.provider_number, SUM(c.service_cost), COUNT(c.service_cost) ";
	query+= "FROM provider a JOIN transaction b ON a.id = b.provider_id ";
	query+= "JOIN service c ON b.service_id = c.id ";
	query+= "WHERE b.payment_status = 0 ";
	query+= "AND b.trans_date <= '" + end_date + "' ";
	query+= "AND b.trans_date >= '" + start_date + "' ";
	query+= "GROUP BY a.provider_name, a.provider_number;";

	db.queryDB(query, res); 

	while(res && res->next())
	{
		temp.read(res->getString(1), res->getInt(2), res->getInt(4), res->getDouble(3));
		provider_list.push_front(temp); 
	}

	if(res)
		delete res; 

	//sort provider_list?
	
	if(fname == "") display(type); 
	else write(type, fname);

	return 1; 
}


int accounting_report::display(char type)
{
	int pcount = 0, scount = 0; 
	float sfee = 0.0;

	if(type == 'A')
		cout << "Provider Number\t\tProvider\t\tService Count\t\tFee Total" << endl;
	else 
		cout << "Provider Number\t\tProvider\t\tFee Total" << endl; 
	for(auto it = provider_list.begin(); it != provider_list.end(); ++it)
	{	
		++pcount;
		sfee += it->display(type, scount);
		cout << endl;
	}

	if(type == 'A')	
	{
		cout << "Provider Count: " << pcount << endl;
		cout << "Service Count: " << scount << endl;
		cout << "Service Fee Total: " << sfee << endl;
	}

	return 1;
}


int accounting_report::write(char type, const string & fname)
{
	ofstream file;
	int pcount = 0, scount = 0; 
	float sfee = 0.0;

	file.open(fname +".csv");
	
	if(!file) return 0;
	if(type == 'A')
		cout << "Provider Number,Provider,Service Count,tFee Total" << endl; 
	else 
		file << "Provider Number,Provider,Fee Total" << endl; 
	for(auto it = provider_list.begin(); it != provider_list.end(); ++it)
	{	
		++pcount;
		sfee += it->write(type, file, scount);
		file << endl;
	}
	if(type == 'A')	
	{
		file << "Provider Count: " << pcount << endl;
		file << "Service Count: " << scount << endl;
		file << "Service Fee Total: " << sfee << endl;
	}

	file.close();
	return 1;
}




