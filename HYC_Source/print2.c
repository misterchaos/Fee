#include"print.h"

int Print_Record(Record_List _list)
{
	Record*p;
	char site[21];

	/*do not print empty list and the head node*/
	if (_list.head == NULL || _list.head->next == NULL)
	{
		return -1;
	}
	setviewport(0, 0, 639, 479, 1);
	cleardevice();
	window(1, 1, 80, 1);
	printf("ID    DL_DATE  AC_DATE      AMOUNT      BALANCE    TYPE    SITE");

	window(1, 3, 80, 25);
	for (p = _list.head->next; p != NULL && p != _list.tail->next; p = p->next)
	{
		/* id date date amount balance*/
		printf("%-5d %-8ld %-8ld %12.2f %12.2f ", p->id, p->deal_date, p->account_date, -(p->deal_amount), p->balance);
		/*deal type*/
		printf(" %-6s ", p->deal_type == 1 ? "POS" : p->deal_type == 2 ? "cash" : p->deal_type == 3 ? "mobile" : "default");
		/*deal site*/
		strncpy(site, p->deal_site, 20);/*only print 20 char*/
		printf(" %s\n", site);
	}
	PrintRecord_Window();

	return 0;
}

int Print_User(User_List _list)
{
	User* p;
	float count;

	/*do not print empty list and the head node*/
	if (_list.head == NULL || _list.head->next == NULL)
	{
		return -1;
	}
	setviewport(0, 0, 639, 479, 1);
	cleardevice();

	window(1, 1, 80, 1);
	printf("     ACCOUNT            CONSUMPTION           BALANCE             RECORDS");

	window(1, 3, 80, 25);

	for (p = _list.head->next; p; p = p->next)
	{

		count = Count_Amount(p->my_record);
		printf(" %-19s %18.2f  %18.2f %15d\n", p->login_name, -(count), p->my_money, p->my_record.node_number - 1);
	}
	PrintUser_Window();
	return 0;
}


int Print_RecordFromTail(Record_List _list)
{
	Record*p;
	char site[21];

	/*do not print empty list and the head node*/
	if (_list.tail == NULL || _list.tail == _list.head)
	{
		return -1;
	}
	setviewport(0, 0, 639, 479, 1);
	cleardevice();
	window(1, 1, 80, 1);
	printf("ID    DL_DATE  AC_DATE      AMOUNT      BALANCE    TYPE    SITE");

	window(1, 3, 80, 25);

	for (p = _list.tail; p != NULL && p != _list.head; p = p->pre)
	{
		/* id date date amount balance*/
		printf("%-5d %-8ld %-8ld %12.2f %12.2f ", p->id, p->deal_date, p->account_date, -(p->deal_amount), p->balance);
		/*deal type*/
		printf(" %-6s ", p->deal_type == 1 ? "POS" : p->deal_type == 2 ? "cash" : p->deal_type == 3 ? "mobile" : "default");
		/*deal site*/
		strncpy(site, p->deal_site, 20);/*only print 20 char*/
		printf(" %s\n", site);
	}
	PrintRecord_Window();

	return 0;
}

