#include "reports.h"
//to do: 
//	align outputs (all files)
//	custom dates(all files)
//	check write to file
//	test more cases


member_report:: member_report()
{
	number = 0; 
}


member_report:: ~member_report()
{
}


int member_report:: run(int m_id, const string & fname)
{ 
	string member_query, service_query; 
	sql:: ResultSet *mem = NULL, *ser = NULL;
	cadb db;
	member_service temp;

	start_date = date(6);
	end_date = date(0);
	
	if(number) reset();

	number = m_id;
	m_id = db.getID("member",to_string(m_id));

	member_query = "SELECT member_name, member_street, member_city, member_state, member_zip ";
	member_query += "FROM member ";
	member_query += ("WHERE id= " + to_string(m_id) +";");

	service_query = "SELECT a.trans_date, b.service_name, c.provider_name ";
	service_query += "FROM transaction a JOIN service b ";
	service_query += "ON a.service_id  = b.id ";
	service_query += "JOIN provider c ON c.id = a.provider_id ";
	service_query += ("WHERE a.member_id = " + to_string(m_id));
	service_query += " AND a.trans_date >= '" + start_date + "' ";
	service_query += "AND a.trans_date <= '" + end_date + "' ;";

	db.queryDB(member_query,mem);	
	db.queryDB(service_query,ser);


	if(mem && mem->next())
	{
		name = mem->getString(1);
		street = mem->getString(2);
		city  = mem->getString(3);
		state = mem->getString(4);
		zip = mem->getString(5);

		delete mem;
	}
	else
	{
		//what is returned if member doesnt exist? 
		cout << "Member: " << number << " does not exist\n";
		return 0;
	}
	// should the report still be written if no services for that week? 
	while(ser && ser->next())
	{
		temp.read(ser->getString(1),ser->getString(2),ser->getString(3));
		member_service_list.push_front(temp);
	}

	if(ser)
		delete ser;
	

	member_service_list.sort();

	if(fname == "") display(); 
	else write(fname);
	return 1; 
}

void member_report:: reset()
{
	name = street = city = state = zip = "";
       	number = 0;
	
	member_service_list.clear();
}	

int member_report:: display()
{
	int count = 0;

	if(!number) return 0; 
	cout << "Member: " << name << endl; 
	cout << "Address: " << street <<  endl << city << ", " << state << ", " << zip << endl; 
	cout << "Service Report from " << start_date << " to " << end_date << endl;
	cout << " Service Date   Service Name            Provider\n";
	for(auto it = member_service_list.begin(); it != member_service_list.end(); ++it)
	{
		cout << ++count << ": ";
		it->display();
		cout << endl;
	}

	return 1;
}

int member_report:: write(const string & fname)
{
	ofstream file;
	int count = 0;

	if(!number) return 0; 

	file.open(fname + ".csv");

	if(!file) return 0;

	file << "Member: " << name << endl;
	file  << "Address: " << street << ", " << city << ", " << state << ", " << zip << endl; 
	file << "Service Report from " << start_date << " to " << end_date << endl;
	file << "Count, Service Date,Service,Provider" << endl;
	for(auto it = member_service_list.begin(); it != member_service_list.end(); ++it)
	{
		file << ++count << ",";
		it->write(file); 
		file << endl;
	}

	file.close();

	return 1;
}




	
	






