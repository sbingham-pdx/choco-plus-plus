#include "reports.h"


provider_report:: provider_report()
{
	number = 0; 
}


provider_report:: ~provider_report()
{
}


int provider_report:: run(int p_id, const string & fname, int filetype)
{ 
	string provider_query, service_query; 
	provider_service temp;
	cadb database;
	sql::ResultSet *provider_data = NULL, *service_records = NULL;
	
	start_date = date(6);
	end_date = date(0); 
	
	if(number) reset();

	number = p_id; 
	p_id = database.getID("provider", to_string(p_id));

	if(!p_id) return 0;

	provider_query = "SELECT provider_name, provider_street, provider_city, ";
	provider_query += "provider_state, provider_zip ";
	provider_query += "FROM provider ";
	provider_query += ("WHERE id  = " + to_string(p_id) +";");

	service_query = "SELECT a.trans_date, a.trans_date_time, b.member_name, ";
	service_query += "b.member_number, c.service_number, c.service_cost FROM transaction a ";
	service_query += "JOIN member b  ON a.member_id= b.id   ";
	service_query += "JOIN service c ON a.service_id = c.id ";
	service_query += "WHERE a.provider_id= " + to_string(p_id) + " ";
	service_query += "AND a.trans_date >= '" + start_date + "' ";
	service_query += "AND a.trans_date <= '" + end_date +"' ;";

	database.queryDB(provider_query,provider_data);	
	database.queryDB(service_query,service_records);

	if(provider_data && provider_data->next())
	{
		name = provider_data->getString(1);
		street = provider_data->getString(2);
		city  = provider_data->getString(3);
		state = provider_data->getString(4);
		zip = provider_data->getString(5);

		delete provider_data;
	}
	else
	{
		if(provider_data)
			delete provider_data;
		if(service_records)
			delete service_records;
		return 0;
	}

	while(service_records && service_records->next())
	{
		temp.read(service_records->getString(1),service_records->getString(2), service_records->getString(3),service_records->getInt(4),
				service_records->getInt(5),service_records->getDouble(6));
		provider_service_list.push_front(temp);
	}

	if(service_records)
		delete service_records;
	
	provider_service_list.sort();

	if(fname == "") display(); 
	else write(fname, filetype);

	return 1; 
}


void provider_report:: reset()
{
	zip = name = street = city = state = "";
    number = 0;
	
	provider_service_list.clear();
}	

int provider_report:: display()
{
	int count = 0;
	float week_fee = 0.0;

	if(!number) return 0; 
	cout << "Provider: " << name << endl; 
	cout << "Address: " << street <<  endl << city << ", " << state << ", " << zip << endl; 
	cout << "Service Report from " << start_date << " to " << end_date << endl;
	cout <<"   " << left << setw(13) << "Service Date" 
	     << left << setw(20) << "Record Date"
	     << left << setw(25) << "Member Name"
	     << left << setw(14) << "Member Number"
	     << left << setw(13) << "Service Code"
	     << left << setw(11) << "Fee" << endl;
	for(auto it = provider_service_list.begin(); it != provider_service_list.end(); ++it)
	{
		cout << ++count << ": ";
		week_fee+= it->display();
		cout << endl;
	}
	
	cout << endl << "Count of Services Provided: " << count << " Fees Owed: " << week_fee << endl;
	return 1;
}

int provider_report:: write(const string & fname, int filetype)
{
	ofstream file;
	float week_fee = 0;
	int count = 0;

	if(!number) return 0; 

	if(!filetype)
		file.open(fname + ".csv");
	else 
		file.open(fname + ".csv", ios::app);

	if(!file) return 0;

	file << "Provider: " << name << endl;
	file  << "Address: " << street << ", " << city << ", " << state << ", " << zip << endl; 
	file << "Service Report from " << start_date << " to " << end_date << endl;
	file << "Count,Date of Service,Date of Record,Member Name,Member Number,Service Code,Fee\n";
	for(auto it = provider_service_list.begin(); it != provider_service_list.end(); ++it)
	{
		file << ++count << ",";
		week_fee += it->write(file); 
		file << endl;
	}
	file << "Count of Services Provided: " << count << " Fees Owed: " << week_fee << endl << endl;

	file.close();

	return 1;
}

int provider_report:: provider_directory(const string & fname)
{
	service_directory obj; 

	return obj.run(fname);
}









	
	






