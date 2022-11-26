#include "reports.h"



int main()
{
	management_report obj;

	obj.eft_report("efttest");
	obj.batch_mark_paid("efttest_detailed_report");
	obj.eft_report("efttest2");
	return 0;
}

