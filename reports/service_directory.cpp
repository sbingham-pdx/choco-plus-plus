#include "reports.h" 


service_directory:: service_directory()
{
}

service_directory:: ~service_directory()
{
}

int service_directory:: run(const string & fname)
{
	cadb db; 
	sql::ResultSet *ptr = NULL;
	string query; 
	service temp; 
	
	query ="Select DISTINCT service_name, service_number, service_cost ";
	query +="FROM service ";
	query +="WHERE service_status = 1; ";

	db.queryDB(query, ptr); 

	if(!ptr) return 0; 

	while(ptr->next())
	{
		temp.read(ptr->getString(1), ptr->getInt(2), ptr->getDouble(3));
		data.push_front(temp); 
	}
	
	if(ptr)
		delete ptr;
	data.sort(); 

	if(fname == "") display(); 
	else write(fname);

	return 1; 
}
		
int service_directory:: display()
{
	cout << left << setw(24) << "Service Name"
	     << left << setw(15) << "Service Number"
	     << left << setw(14) << "Service Cost" << endl;
	for(auto it = data.begin(); it != data.end(); ++it)
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

	for(auto it = data.begin(); it != data.end(); ++it)
	{
		it->write(file);
		file << endl;
	}
	file.close();

	return 1;
}

