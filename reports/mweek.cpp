#include "reports.h"
//to do: 
//	align outputs (all files)
//	custom dates(all files)
//	check write to file
//	test more cases
//	managent reports

member_week:: member_week()
{
	number = 0; 
}


member_week:: ~member_week()
{
}


int member_week:: run(int m_id, const string & fname)
{ 
	string member_query, service_query; 
	sql:: ResultSet *mem = NULL, *ser = NULL;
	cadb db;
	service temp;

	begin = date(6);
	end = date(0);
	
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
	service_query += " AND a.trans_date >= '" + begin + "' ";
	service_query += "AND a.trans_date <= '" + end + "' ;";

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

	while(ser && ser->next())
	{
		temp.read(ser->getString(1),ser->getString(2),ser->getString(3));
		data.push_front(temp);
	}

	if(ser)
		delete ser;
	

	data.sort();

	if(fname == "") display(); 
	else write(fname);
	return 1; 
}

void member_week:: reset()
{
	name = street = city = state = zip = "";
       	number = 0;
	
	data.clear();
}	

int member_week:: display()
{
	int count = 0;

	if(!number) return 0; 
	cout << "Member: " << name << endl; 
	cout << "Address: " << street <<  endl << city << ", " << state << ", " << zip << endl; 
	cout << "Service Report from " << begin << " to " << end << endl;
	cout << " Service Date   Service Name            Provider\n";
	for(auto it = data.begin(); it != data.end(); ++it)
	{
		cout << ++count << ": ";
		it->display();
		cout << endl;
	}

	return 1;
}

int member_week:: write(const string & fname)
{
	ofstream file;
	int count = 0;

	if(!number) return 0; 

	file.open(fname + ".csv");

	file << "Member: " << name << endl;
	file  << "Address: " << street << ", " << city << ", " << state << ", " << zip << endl; 
	file << "Service Report from " << begin << " to " << end << endl;
	file << "Service Date,Service,Provider" << endl;
	for(auto it = data.begin(); it != data.end(); ++it)
	{
		file << ++count << ": ";
		it->write(file); 
		file << endl;
	}

	file.close();

	return 1;
}




	
	






