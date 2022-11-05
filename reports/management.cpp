#include "reports.h" 

int management:: all_providers(const string & fname)
{
	sql::ResultSet *ptr = NULL; 
	string query;
	cadb db;
	provider_week obj;

	query = " SELECT DISTINCT provider_number ";
	query += "FROM provider;";

	db.queryDB(query, ptr);
	
	if(!ptr) return 0;

	while(ptr->next())
	{
		int num = ptr->getInt(1);
		if(!num) continue;
		obj.run(num, fname); 
	}

	return 1;
}

int management:: individual_provider(int p_id, const string & fname)
{
	provider_week obj; 
	
	return obj.run(p_id, fname);
}

int all_members(const string & fname)
{
	sql::ResultSet *ptr = NULL; 
	string query;
	cadb db;
	member_week obj;

	query = " SELECT DISTINCT member_number ";
	query += "FROM member ";
	query += "WHERE member_status = 1;";

	db.queryDB(query, ptr);
	
	if(!ptr) return 0;

	while(ptr->next())
	{	
		int num = ptr->getInt(1);
		if(!num) continue;
		obj.run(num, fname); 
	}

	return 1;

}


int management:: individual_member(int m_id, const string & fname)
{
	member_week obj; 

	return obj.run(m_id, fname);
}


int management:: ap_report(const string & fname)
{
	etf_week obj;

	return obj.run('A', fname);
}

int management:: etf_report(const string & fname)
{
	etf_week  obj; 

	return obj.run('B', fname); 
}

int management:: provider_directory(const string & fname)
{
	service_directory obj;

	return obj.run(fname);
}

