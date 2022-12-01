#include "reports.h"

public void Reports_All_Providers_Success()
{
    ifstream file;
    mangement_report obj; 

    obj.all_providers(); 
    
    file.open(date(0)+"_all_providers.csv");

    assert("expected file exists", file); 

    assert("file contains data", file.peek() != file.eof());

    cout << "Passed" << endl; 
}

public void Reports_Ind_Provider_Sucess()
{

    ifstream file;
    mangement_report obj; 

    obj.individual_provider(158452334); 
    
    file.open(date(0)+"_158452334_report.csv");

    assert("expected file exists", file); 

    assert("file contains data", file.peek() != file.eof());

    cout << "Passed" << endl; 
}

public void Reports_All_Members_Success()
{
    ifstream file;
    mangement_report obj; 

    obj.all_members(); 
    
    file.open(date(0)+"_all_members.csv");

    assert("expected file exists", file); 

    assert("file contains data", file.peek() != file.eof());

    cout << "Passed" << endl; 

}

public void Reports_Ind_Member_Sucess()
{
    ifstream file;
    mangement_report obj; 

    obj.individual_member(631375719); 
    
    file.open(date(0)+"_631375719_report.csv");

    assert("expected file exists", file); 

    assert("file contains data", file.peek() != file.eof());

    cout << "Passed" << endl; 

}

public void Reports_Ind_Member_Bad_ID()
{
    ifstream file;
    mangement_report obj; 

    obj.individual_member(6313757190); 
    
    file.open(date(0)+"_6313757190_report.csv");

    assert("no file created", !file); 

    cout << "Passed" << endl; 
}

public void Reports_Ind_Provider_Bad_ID()
{
    ifstream file;
    mangement_report obj; 

    obj.individual_provider(6313757190); 
    
    file.open(date(0)+"_6313757190_report.csv");

    assert("no file created", !file); 

    cout << "Passed" << endl; 
}


public void AP_Report_Success()
{
    ifstream file;
    mangement_report obj; 

    obj.ap_report();
    
    file.open(date(0)+"_ap_report_csv");

    assert("expected file exists", file); 

    assert("file contains data", file.peek()!=file.eof());

    cout << "Passed" << endl; 
}


[Test]
public void EFT_Report_Success()
{
    ifstream file;
    mangement_report obj; 

    obj.ap_report();
    
    file.open(date(0)+"_ap_report_csv");

    assert("expected file exists", file); 

    assert("file contains data", file.peek()!=file.eof());

    cout << "Passed" << endl; 
}

[Test] 
public void Directory_Sucess()
{

}

[Test]
public void Batch_Paid_Success()
{

}

[Test]
public void Batch_Paid_Bad_File()
{

}*/