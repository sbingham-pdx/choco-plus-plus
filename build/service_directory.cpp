#include "reports.h" 


service_directory:: service_directory()
{
}

service_directory:: ~service_directory()
{
}

int service_directory:: run(const string & fname)
{
	cadb database; 
	sql::ResultSet *results = NULL;
	string query; 
	service_record temp; 
	
	query ="Select DISTINCT service_name, service_number, service_cost ";
	query +="FROM service ";
	query +="WHERE service_status = 1; ";
	
	if(!service_list.empty())
		service_list.clear();

	database.queryDB(query, results); 

	if(!results) return 0; 

	while(results->next())
	{
		temp.read(results->getString(1), results->getInt(2), results->getDouble(3));
		service_list.push_front(temp); 
	}
	
	if(results)
		delete results;

	service_list.sort(); 

	if(fname == "") display(); 
	else write(fname);

	return 1; 
}
		
int service_directory:: display()
{
	cout << left << setw(24) << "Service Name"
	     << left << setw(15) << "Service Number"
	     << left << setw(14) << "Service Cost" << endl;
	for(auto it = service_list.begin(); it != service_list.end(); ++it)
	{
		it->display();
		cout << endl;
	}

	return 1;
}

int service_directory:: write(const string & fname)
{
	ofstream file;

	file.open(fname+".csv"); 
	
	if(!file) return 0;

	file << "Service Name" << ","
	    << "Service Number" << ","
	    << "Service Cost" << endl;

	for(auto it = service_list.begin(); it != service_list.end(); ++it)
	{
		it->write(file);
		file << endl;
	}
	file.close();

	return 1;
}


