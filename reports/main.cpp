#include "reports.h"



int main()
{
	management_report obj;

	obj.all_providers("test");
	obj.all_members("test2");
	obj.ap_report("aptest");
	obj.etf_report("efttest");

	return 0;
}

