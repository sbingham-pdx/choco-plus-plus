#include "reports.h" 

// Change file to append rather than overwrite
int management_report:: all_providers()
{
	sql::ResultSet *ptr = NULL; 
	string query;
	cadb db;
	provider_report obj;
	int count = 0;

	query = " SELECT DISTINCT provider_number ";
	query += "FROM provider;";

	db.queryDB(query, ptr);
	
	if(!ptr) return 0;

	while(ptr->next())
	{
		int num = ptr->getInt(1);
		if(!num) continue;
		if(count)
			obj.run(num, date(0)+"_all_providers",1); 
		else
			obj.run(num, date(0)+"_all_providers",count++);
	}

	if(ptr) delete ptr;

	return 1;
}

int management_report:: individual_provider(int p_id)
{
	provider_report obj; 
	
	return obj.run(p_id, date(0)+"_"+to_string(p_id)+"_report");
}

// Change file to append rather than overwrite
int management_report:: all_members()
{
	sql::ResultSet *ptr = NULL; 
	string query;
	cadb db;
	member_report obj;
	int count = 0;

	query = " SELECT DISTINCT member_number ";
	query += "FROM member ";
	query += "WHERE member_status = 1;";

	db.queryDB(query, ptr);
	
	if(!ptr) return 0;

	while(ptr->next())
	{	
		int num = ptr->getInt(1);
		if(!num) continue;
		if(count)
			obj.run(num, date(0)+"_all_members",1); 
		else
			obj.run(num, date(0)+"_all_members",count++);
	}

	if(ptr) delete ptr;

	return 1;

}


int management_report:: individual_member(int m_id)
{
	member_report obj; 

	return obj.run(m_id, date(0)+"_"+to_string(m_id)+"_report");
}


int management_report:: ap_report()
{
	accounting_report obj;

	return obj.run('A', date(0)+"_ap_report");
}

int management_report:: eft_report()
{
	accounting_report  obj; 

	return obj.run('C', date(0)+"_eft"); 
}

int management_report:: provider_directory()
{
	service_directory obj;

	return obj.run(date(0)+"_provider_directory");
}

int management_report:: mark_paid(int transaction_id, int type)
{
	cadb obj; 
	if(type)
		obj.setCell("transaction","id", to_string(transaction_id), "payment_status", "1");	
	else
		obj.setCell("transaction","id", to_string(transaction_id), "payment_status", "0");	
	return 1;
}

int management_report:: batch_mark_paid(const string & fname, int type)
{
	ifstream ifile; 
	ofstream ofile;
	int tid =0, pn = 0, mn = 0, day = 0, month = 0, year =0, count = 0;
	float cost = 0;
	forward_list<t_id> to_mark_paid, to_compare;
	t_id temp;
	sql:: ResultSet * res = NULL; 
	string query;
	cadb data_base;
	
	if(fname == "" ) return 0;
	if(!endswith(fname, "_eft_detailed_report")) return 0; 

	ifile.open(fname +".csv");

	if(!ifile) return 0; 
	ofile.open(fname+"_payment_status_updated.csv");
	if(!ofile) return 0;

	ofile << "Provider Number,Transaction ID,Service Date,Member Number,Service Cost" << endl; 

	ifile.ignore(100,',');
	ifile.ignore(100,',');
	ifile.ignore(100,',');
	ifile.ignore(100,',');
	ifile.ignore(100,'\n');
	
	
	ifile >> pn;
	while(!ifile.eof())
	{
		ifile.ignore(100, ',');	
		ifile >> tid; 
		ifile.ignore(100,',');
		ifile >> year;
		ifile.ignore(100,'-');
		ifile >> month;
		ifile.ignore(100,'-');
		ifile >> day;
		ifile.ignore(100,',');
		ifile >> mn;
		ifile.ignore(100,',');
		ifile >> cost;
		temp.read(pn, tid, to_string(year) + "-" + to_string(month) + "-" + to_string(day), mn, cost);
		to_mark_paid.push_front(temp);
		ifile.ignore(100, '\n');
		ifile >> pn;
	}

	ifile.close();

	if(to_mark_paid.empty()) 
	{
		ofile << " Empty input file " << endl; 
		ofile.close();
		return 1; 
	}

	query = "SELECT b.provider_number, a.id, a.trans_date, d.member_number, c.service_cost ";
	query+= "FROM transaction a ";
	query += "JOIN service c ON a.service_id = c.id ";
	query += "JOIN provider b ON b.id = a.provider_id ";
	query += "JOIN member d ON a.member_id = d.id ";
	if(type)
		query += "AND a.payment_status = 0 ";
	else
		query += "AND a.payment_status = 1 ";
	query += "ORDER BY b.provider_number;";

	data_base.queryDB(query, res);

	while(res && res->next())
	{
		temp.read(res->getInt(1), res->getInt(2), res->getString(3), res->getInt(4), res->getDouble(5));
		to_compare.push_front(temp);
	}

	if(res) delete res;

	if(to_compare.empty()) 
	{
		ofile << " No unpaid services " << endl;
		ofile.close();
		return 1;
	}

	to_compare.sort();
	to_mark_paid.sort();

	for(auto it  = to_mark_paid.begin(); it != to_mark_paid.end(); ++it)
	{
		for(auto it2 = to_compare.begin(); it2 != to_compare.end(); ++it2)
		{
			if(*it2 < *it) continue;

			if(!it2->compare_provider(*it)) break;

			if(*it2 == *it)
			{
				if(mark_paid(it->get_id(),type))
				{
					++count;
					it->write(ofile);
					ofile << endl;
					to_compare.remove(*it2);
				}
				break;
			}
		}
	}

	if(!count)
	{
		ofile << "No matching unpaid services" << endl; 
		ofile.close();
		return 1;
	}

	ofile.close();

	return 1;
}
