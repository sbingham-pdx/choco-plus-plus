#include "reports.h"



int main()
{
	management_report obj;

	obj.all_providers("test");
	obj.all_members("test2");
	obj.ap_report("aptest");
	obj.eft_report("efttest");
	obj.provider_directory("pdir");

	return 0;
}

