#include "reports.h"


accounting_report:: accounting_report()
{
}

accounting_report:: ~accounting_report()
{
}

int accounting_report::run(char type, const string & fname)
{
	string summary_query, detailed_query;
	sql::ResultSet *summary_results=NULL, *detailed_results=NULL;
	cadb database;
	provider_ap_record temp;
	t_id temp2;

	if(!provider_list.empty())	
		provider_list.clear();
	if(!t_id_list.empty())
		t_id_list.clear();

	start_date = date(6); 
	end_date = date(0); 

	summary_query = "SElECT a.provider_name, a.provider_number, SUM(c.service_cost), COUNT(c.service_cost) ";
	summary_query+= "FROM provider a JOIN transaction b ON a.id = b.provider_id ";
	summary_query+= "JOIN service c ON b.service_id = c.id ";
	summary_query+= "WHERE b.payment_status = 0 ";
	summary_query+= "AND b.trans_date <= '" + end_date + "' ";
	summary_query+= "AND b.trans_date >= '" + start_date + "' ";
	summary_query+= "GROUP BY a.provider_name, a.provider_number;";

	detailed_query = "SELECT b.provider_number, a.id, a.trans_date, d.member_number, c.service_cost ";
	detailed_query+= "FROM transaction a ";
	detailed_query += "JOIN service c ON a.service_id = c.id ";
	detailed_query += "JOIN provider b ON b.id = a.provider_id ";
	detailed_query += "JOIN member d ON a.member_id = d.id ";
	detailed_query += "AND a.trans_date >= '" + start_date + "' ";
	detailed_query += "AND a.trans_date <= '" + end_date +"' ";
	detailed_query += "AND a.payment_status = 0 ";
	detailed_query += "ORDER BY b.provider_number;";

	database.queryDB(summary_query, summary_results); 
	database.queryDB(detailed_query, detailed_results); 

	while(summary_results && summary_results->next())
	{
		temp.read(summary_results->getString(1), summary_results->getInt(2), summary_results->getInt(4), summary_results->getDouble(3));
		provider_list.push_front(temp); 
	}

	while(detailed_results && detailed_results->next())
	{
		temp2.read(detailed_results->getInt(1), detailed_results->getInt(2), detailed_results->getString(3), detailed_results->getInt(4), detailed_results->getDouble(5));
		t_id_list.push_front(temp2);
	}

	if(detailed_results)
		delete detailed_results;
	if(summary_results)
		delete summary_results; 


	if(provider_list.empty()) return 0;

	t_id_list.sort();

	if(type == 'C')
	{
	
		for(auto it = provider_list.begin(); it != provider_list.end(); ++it)
		{
			if(!compare_total(*it))
				return 0;
		}

		if(fname == "") 
		{	
			display('B');
			display(type);
		}
		else 
		{
			write('B', fname); 
			write(type,fname);
		}
	}

	else
	{
		if (fname == "")
			display(type);
		else
			write(type, fname);
	}
		return 1; 
}

int accounting_report:: compare_total(const provider_ap_record & to_comp)
{
	float sum = 0.0;

	for(auto it = t_id_list.begin(); it!=t_id_list.end(); ++it)
	{
		if(!it->compare_provider(to_comp)) continue;

		while(it!=t_id_list.end() && it->compare_provider(to_comp))
		{	
			sum += it->get_cost(); 
			++it;
		}

		break;
	}

	return to_comp.compare(sum);
}

int accounting_report::display(char type)
{
	int pcount = 0, scount = 0; 
	float sfee = 0.0;

	if(type == 'A' || type == 'B')
	{
		if (type == 'A')
			cout << "Provider Number\t\tProvider\t\tService Count\t\tFee Total" << endl;
		else
			cout << "Provider Number\t\tProvider\t\tFee Total" << endl;
		for (auto it = provider_list.begin(); it != provider_list.end(); ++it)
		{
			++pcount;
			sfee += it->display(type, scount);
			cout << endl;
		}

		if (type == 'A')
		{
			cout << "Provider Count: " << pcount << endl;
			cout << "Service Count: " << scount << endl;
			cout << "Service Fee Total: " << sfee << endl;
		}
	}

	else
	{
		cout << "Provider Number\t\tService ID\t\tService Date\t\tMember Number\t\tService Cost" << endl; 
		for (auto it = t_id_list.begin(); it != t_id_list.end(); ++it)
		{
			it->display();
			cout << endl;
		}
	}

	return 1;
}


int accounting_report::write(char type, const string & fname)
{
	ofstream file;
	int pcount = 0, scount = 0; 
	float sfee = 0.0;

	if(type == 'A' || type == 'B')
		file.open(fname + ".csv");
	else 
		file.open(fname +"_detailed_report.csv");

	if(!file) return 0;

	if(type == 'B' || type == 'A')
	{
		if (type == 'A')
			file << "Provider Number,Provider,Service Count,Fee Total" << endl;
		else if (type == 'B')
			file << "Provider Number,Provider,Fee Total" << endl;

		for (auto it = provider_list.begin(); it != provider_list.end(); ++it)
		{
			++pcount;
			sfee += it->write(type, file, scount);
			file << endl;
		}

		if (type == 'A')
		{
			file << "Provider Count: " << pcount << endl;
			file << "Service Count: " << scount << endl;
			file << "Service Fee Total: " << sfee << endl;
		}
	}

	else
	{
		file << "Provider Number,Transaction ID,Service Date,Member Number,Service Cost" << endl; 
		for (auto it = t_id_list.begin(); it != t_id_list.end(); ++it)
		{
			it->write(file);
			file << endl;
		}
	}

	file.close();

	return 1;
}




