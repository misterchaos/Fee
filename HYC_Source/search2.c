#include"search.h"

/*to search an account by account number*/
User* Search_Account(const User_List _list, const char* _login_name)
{
	User*p;

	/*do not search empty list and the head node*/
	if (_list.head == NULL || _list.tail == NULL)
	{
		return NULL;
	}

	for (p = _list.head->next; p != _list.tail->next; p = p->next)
	{
		/*if this account match the nnumber*/
		if (strcmp(p->login_name, _login_name) == 0)
			return p;
	}
	return NULL;
}


/*to search a record by its ID*/
Record*Search_RecordByID(Record_List _list, int _id)
{
	Record* p;

	/*do not search empty list and the head node*/
	if (_list.head == NULL || _list.head->next == NULL)
	{
		return NULL;
	}

	for (p = _list.head->next; p != NULL && p != _list.tail->next; p = p->next)
	{
		/*if this record match the nnumber*/
		if (p->id == _id)
			return p;
	}
	return NULL;
}


/*search all the records which match condition*/
PListNode* Search_ByDate(Record_List _list, long int _begin, long int _end)
{
	Record* getrecord = NULL;//to search record list
	PListNode* phead = NULL;//the head of the plist
	PListNode* get_plistnode = NULL;//to create plistnode
	PListNode* plist = phead;//point to plistnode

	/*do not search empty list and the head node*/
	if (_list.head == NULL || _list.head->next == NULL)
	{
		printf("no record to search\n");
		return NULL;
	}

	for (getrecord = _list.head->next, plist = phead; getrecord != NULL && getrecord != _list.tail->next; getrecord = getrecord->next)
	{
		if (getrecord->deal_date >= _begin && getrecord->deal_date <= _end)
		{
			/*create a record pointer's pointer*/
			get_plistnode = (PListNode*)malloc(sizeof(PListNode));
			/*let it point to this record*/
			get_plistnode->pointer = getrecord;
			/*add it to the pointer list*/
			if (phead == NULL)
			{
				phead = plist = get_plistnode;
			}
			else
			{
				plist->next = get_plistnode;
				plist = get_plistnode;
			}
		}
	}
	if (plist != NULL)
		plist->next = NULL;
	return phead;
}


/*search all the records which match condition*/
PListNode* Search_ByAmount(Record_List _list, float _min, float _max)
{
	Record* getrecord = NULL;//to search record list
	PListNode* phead = NULL;//the head of the plist
	PListNode* get_plistnode = NULL;//to create plistnode
	PListNode* plist = phead;//point to plistnode


	/*do not search empty list and the head node*/
	if (_list.head == NULL || _list.head->next == NULL)
	{
		return NULL;
	}

	for (getrecord = _list.head->next, plist = phead; getrecord != NULL && getrecord != _list.tail->next; getrecord = getrecord->next)
	{
		if (getrecord->deal_amount >= _min && getrecord->deal_amount <= _max)
		{
			/*create a record pointer's pointer*/
			get_plistnode = (PListNode*)malloc(sizeof(PListNode));
			/*let it point to this record*/
			get_plistnode->pointer = getrecord;
			/*add it to the pointer list*/
			if (phead == NULL)
			{
				phead = plist = get_plistnode;
			}
			else
			{
				plist->next = get_plistnode;
				plist = get_plistnode;
			}
		}
	}
	if (plist != NULL)
		plist->next = NULL;
	return phead;
}


/*search all the records which match condition*/
PListNode* Search_ByDealType(Record_List _list, int _deal_type)
{
	Record* getrecord = NULL;//to search record list
	PListNode* phead = NULL;//the head of the plist
	PListNode* get_plistnode = NULL;//to create plistnode
	PListNode* plist = phead;//point to plistnode



	/*do not search empty list and the head node*/
	if (_list.head == NULL || _list.head->next == NULL)
	{
		return NULL;
	}

	for (getrecord = _list.head->next, plist = phead; getrecord != NULL && getrecord != _list.tail->next; getrecord = getrecord->next)
	{
		if (getrecord->deal_type == _deal_type)
		{
			/*create a record pointer's pointer*/
			get_plistnode = (PListNode*)malloc(sizeof(PListNode));
			/*let it point to this record*/
			get_plistnode->pointer = getrecord;
			/*add it to the pointer list*/
			if (phead == NULL)
			{
				phead = plist = get_plistnode;
			}
			else
			{
				plist->next = get_plistnode;
				plist = get_plistnode;
			}
		}
	}
	if (plist != NULL)
		plist->next = NULL;
	return phead;
}


int Print_RecordBySearch(PListNode* _list)
{
	PListNode*p;
	char site[21];

	/*do not print empty list*/
	if (_list == NULL)
	{
		return -1;
	}
	setviewport(0, 0, 639, 479, 1);
	cleardevice();
	window(1, 1, 80, 1);
	printf("ID    DL_DATE  AC_DATE      AMOUNT      BALANCE    TYPE    SITE");
	window(1, 3, 80, 25);

	for (p = _list; p; p = p->next)
	{
		/* id date date amount balance*/
		printf("%-5d %-8ld %-8ld %12.2f %12.2f ", p->pointer->id, p->pointer->deal_date, p->pointer->account_date, -(p->pointer->deal_amount), p->pointer->balance);
		/*deal type*/
		printf(" %-6s ", p->pointer->deal_type == 1 ? "POS" : p->pointer->deal_type == 2 ? "cash" : "mobile");
		/*deal site*/
		strncpy(site, p->pointer->deal_site, 20);/*only print 25 char*/
		printf(" %s\n", site);
	}

	PrintRecord_Window();
	return 0;
}


float Count_BySearch(PListNode* _list)
{
	PListNode*p;
	float cnt = 0;/*add to this*/

	/*do not print empty list*/

	if (_list->pointer == NULL || _list->pointer == NULL)
	{
		return 0;
	}

	for (p = _list; p; p = p->next)
	{
		cnt += p->pointer->deal_amount;
	}

	return cnt;
}
