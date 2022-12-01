#include "reports.h"

void Reports_All_Providers_Success()
{
    ifstream file;
    management_report obj;

    obj.all_providers(); 
    
    file.open(date(0)+"_all_providers.csv");

    assert(("expected file exists", file));

    file.peek();
    assert(("file contains data", !file.eof()));

    cout << "Passed" << endl; 
}

void Reports_Ind_Provider_Success()
{

    ifstream file;
    management_report obj;

    obj.individual_provider(158452334); 
    
    file.open(date(0)+"_158452334_report.csv");

    assert(("expected file exists", file)); 
    
    file.peek();

    assert(("file contains data",!file.eof()));

    cout << "Passed" << endl; 
}

void Reports_All_Members_Success()
{
    ifstream file;
    management_report obj;

    obj.all_members(); 
    
    file.open(date(0)+"_all_members.csv");

    assert(("expected file exists", file));

    file.peek();

    assert(("file contains data", !file.eof()));

    cout << "Passed" << endl; 

}

void Reports_Ind_Member_Success()
{
    ifstream file;
    management_report obj;

    obj.individual_member(631375719); 
    
    file.open(date(0)+"_631375719_report.csv");

    assert(("expected file exists", file));

    file.peek();

    assert(("file contains data", !file.eof()));

    cout << "Passed" << endl; 

}

void Reports_Ind_Member_Bad_ID()
{
    ifstream file;
    management_report obj;

    obj.individual_member(631375); 
    
    file.open(date(0)+"_6313757190_report.csv");

    assert(("no file created", !file)); 

    cout << "Passed" << endl; 
}

void Reports_Ind_Provider_Bad_ID()
{
    ifstream file;
    management_report obj;

    obj.individual_provider(631); 
    
    file.open(date(0)+"_6313757190_report.csv");

    assert(("no file created", !file));

    cout << "Passed" << endl; 
}


void AP_Report_Success()
{
    ifstream file;
    management_report obj;

    obj.ap_report();
    
    file.open(date(0)+"_ap_report.csv");

    assert(("expected file exists", file)); 

    file.peek();

    assert(("file contains data", !file.eof()));

    cout << "Passed" << endl; 
}


void EFT_Report_Success()
{
    ifstream file;
    ifstream file2;
    management_report obj;

    obj.eft_report();
    
    file.open(date(0)+"_eft_report.csv");
    file.open(date(0)+"_eft_detailed_report.csv");

    assert(("expected files exists", file && file2)); 

    file.peek(); 
    file2.peek();

    assert(("files contain data", !file.eof() && !file.eof()));

    cout << "Passed" << endl; 
}

void Directory_Sucess()
{
    ifstream file;
    management_report obj;

    obj.provider_directory();
    
    file.open(date(0)+"_provider_directory.csv");

    assert(("expected file exists", file));

    file.peek();

    assert(("file contains data", !file.eof()));

    cout << "Passed" << endl; 

}

void Batch_Paid_Success()
{
    ifstream f1, f2;
    management_report obj;

    obj.eft_report();

    assert(("valid inpuit file", obj.batch_mark_paid(date(0)+"_eft_detailed_report")));

    f1.open(date(0) + "_eft_detailed_report_payment_status_updated.csv");
    f2.open(date(0) + "_eft_detailed_report.csv");

    assert(("file output valid", f1 && f2));

    assert(("files are identical", comparefiles(f1, f2)));

    cout << "Passed" << endl;
}

void Batch_Paid_Bad_File()
{
    management_report obj;

    assert(("bad input file" , !obj.batch_mark_paid(date(0)+"eft_detailed_report")));
    assert(("bad input file" , !obj.batch_mark_paid("1900-12-21_eft_detailed_report")));
    assert(("bad input file" , !obj.batch_mark_paid("2022-14-21_eft_detailed_report")));
    assert(("bad input file" , !obj.batch_mark_paid("2022-14-51_eft_detailed_report")));

    cout << "Passed" << endl;
}


int main()
{
   /*Reports_All_Providers_Success();
   Reports_Ind_Provider_Success();
   Reports_All_Members_Success();
   Reports_Ind_Member_Success();
   Reports_Ind_Member_Bad_ID();
   Reports_Ind_Provider_Bad_ID();
   AP_Report_Success();
   EFT_Report_Success();
   Directory_Sucess();*/
   Batch_Paid_Success();
   //Batch_Paid_Bad_File();
   return 0;
}