#include "reports.h"


int main()
{

    management_report obj; 

    obj.all_members("all_members");
    obj.all_providers("all_providers");
    obj.provider_directory("pdirectory");
    obj.ap_report("ap_report");
    obj.eft_report("eft");
    obj.batch_mark_paid("eft_detailed_report");
}