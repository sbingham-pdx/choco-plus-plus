#include "reports.h" 

// Change file to append rather than overwrite
int management_report:: all_providers(const string & fname)
{
	sql::ResultSet *ptr = NULL; 
	string query;
	cadb db;
	provider_report obj;

	query = " SELECT DISTINCT provider_number ";
	query += "FROM provider;";

	db.queryDB(query, ptr);
	
	if(!ptr) return 0;

	while(ptr->next())
	{
		int num = ptr->getInt(1);
		if(!num) continue;
		obj.run(num, fname,1); 
	}

	if(ptr) delete ptr;

	return 1;
}

int management_report:: individual_provider(int p_id, const string & fname)
{
	provider_report obj; 
	
	return obj.run(p_id, fname);
}

// Change file to append rather than overwrite
int management_report:: all_members(const string & fname)
{
	sql::ResultSet *ptr = NULL; 
	string query;
	cadb db;
	member_report obj;

	query = " SELECT DISTINCT member_number ";
	query += "FROM member ";
	query += "WHERE member_status = 1;";

	db.queryDB(query, ptr);
	
	if(!ptr) return 0;

	while(ptr->next())
	{	
		int num = ptr->getInt(1);
		if(!num) continue;
		obj.run(num, fname,1); 
	}

	if(ptr) delete ptr;

	return 1;

}


int management_report:: individual_member(int m_id, const string & fname)
{
	member_report obj; 

	return obj.run(m_id, fname);
}


int management_report:: ap_report(const string & fname)
{
	accounting_report obj;

	return obj.run('A', fname);
}

int management_report:: eft_report(const string & fname)
{
	accounting_report  obj; 

	return obj.run('C', fname); 
}

int management_report:: provider_directory(const string & fname)
{
	service_directory obj;

	return obj.run(fname);
}

int management_report:: mark_paid(int transaction_id)
{
	cadb obj; 

	obj.setCell("transaction","id", to_string(transaction_id), "payment_status", "1");	
	return 1;
}

int management_report:: batch_mark_paid(const string & fname)
{
	ifstream file; 
	int tid =0, pn = 0;
	float cost = 0;

	file.open(fname +".csv");

	if(!file) return 0; 

	file.ignore(100,',');
	file.ignore(100,',');
	file.ignore(100,'\n');
	
	
	file >> pn;
	while(!file.eof())
	{
		file.ignore(100, ',');	
		file >> tid; 
		file.ignore(100,',');
		file >> cost;
		file.ignore(100, '\n');
		if(mark_paid(tid))
			cout << "Transaction: " << tid << " paid\n";
		file >> pn;
	}

	return 1;
}