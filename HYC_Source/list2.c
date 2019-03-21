#include"list.h"


/*to create a user list*/
User_List Create_UserList()
{
	/*create a list*/
	User_List list;


	/*create a head node,add to the list*/
	list.head = (User *)malloc(sizeof(User));

	/*initialize the head node*/
	strcpy(list.head->password, "-1");
	strcpy(list.head->login_name, "-1");
	list.head->account_type = -1;
	list.head->my_record.head = NULL;
	list.head->my_record.tail = NULL;
	list.head->pre = NULL;
	list.head->next = NULL;

	/*initialize the list */
	list.tail = list.head;
	list.node_number = 1;

	return list;
}

/*to create a record list*/
Record_List Create_RecordList()
{

	/*create a list*/
	Record_List list;

	/*create a head node,add to the list*/
	list.head = (Record *)malloc(sizeof(Record));

	/*initialize the head node*/
	list.head->id = 0;
	list.head->deal_date = -1;
	list.head->account_date = -1;
	list.head->deal_amount = -1;
	list.head->balance = -1;
	list.head->deal_type = -1;
	strcpy(list.head->deal_site, "-1");
	list.head->pre = NULL;
	list.head->next = NULL;

	/*initialize the list */
	list.tail = list.head;
	list.node_number = 1;

	return list;
}

/*to create a user node*/
User* Create_UserNode()
{
	/*create a node pointer*/
	User* node;
	/*put imput string here*/
	char str[51] = { 0 };
	int ret = 0;

	/*create a new node*/
	node = (User*)malloc(sizeof(User));

	/*initialize the new node*/

	/*imput login number*/
	do
	{
		ret = 0;
		/*imput login number and check if it is valid*/
		Input_LoginNumber(str);
		/*ensure the account haven't been create*/
		if (Search_Account(all_user, str) == NULL)
		{
			strcpy(node->login_name, str);
			break;
		}
		else
		{
			Output_Window();
			ret = -1;
			printf("\n\n\t[Warnings]This account has already exist !");
		}
	} while (ret == -1);


	/*imput login password*/
	do
	{
		/*imput login password check*/
		ret = 0;
		Input_Window();
		printf("\n\n\t[Tips]You can just imput [0] to set default password[1234]");
		printf("\n\n\tLogin Password[less than 20 char] = ");

		scanf("%s", str);

		/*ensure the string is not longer than 20*/
		if (strlen(str) > 20)
		{
			Output_Window();
			ret = -1;
			printf("\n\n\t[Warnings]The password is too long !");
		}

		if (strcmp(str, "0") == 0)
			strcpy(node->password, "1234");
		else
			strcpy(node->password, str);

	} while (ret == -1);

	/*set acconut type*/

	node->account_type = Input_AccounType();
	Output_Window();

	printf("\n\n\tPlease imput his money below ");
	node->my_money = Input_Money();

	/*create a record list for this user*/
	node->my_record = Create_RecordList();

	/*set pointer*/
	node->pre = NULL;
	node->next = NULL;

	return node;
}

/*to create a record node*/
Record* Create_RecordNode()
{
	/*create a node pointer*/
	Record* node;

	/*create a new node*/
	node = (Record*)malloc(sizeof(Record));

	/*initialize the new node*/
	Output_Window();
	/*imput deal date*/
	printf("\n\n\tPlease imput deal date below ");
	node->deal_date = Input_Date();

	Output_Window();
	/*imput account date*/
	printf("\n\n\tPlease imput account date below ");
	node->account_date = Input_Date();
	Output_Window();

	/*imput deal amount*/
	printf("\n\n\tPlease imput deal amount below ");
	node->deal_amount = Input_Money();
	Output_Window();


	/*imput deal type*/
	printf("\n\n\tPlease imput deal type below ");
	node->deal_type = Input_DealType();
	Output_Window();

	/*imput deal site*/
	printf("\n\n\tPlease imput deal site below ");
	Input_DealSite(node->deal_site);

	/*set pointer*/
	node->balance = -1;
	node->pre = NULL;
	node->next = NULL;

	return node;
}


/*to create a record node*/
Record* Create_EmptyRecordNode()
{
	/*create a node pointer*/
	Record* node;

	/*create a new node*/
	node = (Record*)malloc(sizeof(Record));

	/*initialize the new node*/
	node->id = 0;
	node->deal_date = 0;
	node->account_date = 0;
	node->deal_amount = 0;
	node->balance = 0;
	node->deal_type = 4;
	strcpy(node->deal_site, "defualt");

	/*set pointer*/
	node->pre = NULL;
	node->next = NULL;
	return node;
}

/*to add a node to a linked-list */
int Add_User(User_List* _list, User* _node)
{
	if (_node == NULL)
	{
		return -1;
	}

	if (_list->head == NULL)
	{
		/*add to tail*/
		_list->head = _node;
		_list->tail = _node;
		_node->next = NULL;
		_node->pre = NULL;
		/*let the number of node++ */
		_list->node_number = 1;
	}
	else
	{
		/*add to tail*/
		_list->tail->next = _node;
		_node->pre = _list->tail;
		_list->tail = _node;
		_node->next = NULL;
		/*let the number of node++ */
		_list->node_number++;
	}
	return 0;
}


int Add_Record(Record_List* _list, Record* _node)

{
	Record*rtemp = NULL;
	if (_node == NULL)
	{
		return -1;
	}

	if (_list->head == NULL || _list->tail == NULL)
	{
		/*add to tail*/
		_list->head = _node;
		_list->tail = _node;
		_node->next = NULL;
		_node->pre = NULL;
		/*let the number of node++ */
		_list->node_number = 1;
	}
	else
	{

		if (_list->node_number <= 1 || _list->head == _list->tail)
		{
			/*Link to all_record*/
			_list->head->next = _node;
			all_record.tail->next = _node;
			_node->pre = all_record.tail;
			all_record.tail = _list->tail = _node;
			_node->next = NULL;

		}
		else
		{
			if (_list->tail == all_record.tail || _list->tail->next == NULL)
			{
				/*add to tail*/
				_list->tail->next = _node;
				_node->pre = _list->tail;
				/*redirect*/
				all_record.tail = _node;
				_list->tail = _node;
				_node->next = NULL;
			}
			else
			{
				rtemp = _list->tail->next;
				/*add to tail*/
				_node->pre = _list->tail;
				_list->tail->next = _node;
				/*limked to the next list*/
				_node->next = rtemp;

				rtemp->pre = _node;
				/*redirect*/
				_list->tail = _node;
			}
		}
		/*let the number of node++ */
		_list->node_number++;
		all_record.node_number++;
	}
	return 0;
}


int Add_ToBackupList(Record* _node)

{
	Record*rtemp = NULL;
	if (_node == NULL)
	{
		return -1;
	}

	if (backup_record.head == NULL || backup_record.tail == NULL)
	{
		/*add to tail*/
		backup_record.head = _node;
		backup_record.tail = _node;
		_node->next = NULL;
		_node->pre = NULL;
		/*let the number of node++ */
		backup_record.node_number = 1;
	}
	else
	{
		/*Link to backup_record*/
		backup_record.tail->next = _node;
		_node->pre = backup_record.tail;
		backup_record.tail = _node;
		_node->next = NULL;

		/*let the number of node++ */
		backup_record.node_number++;
	}
	return 0;
}


/*to delete a node from linked-list */
void Delete_UserNode(User_List _list, User* _node)
{


	/*delete from a user list*/
	_node->pre->next = _node->next;

	/*ensure this node is not the last one*/
	if (_node->next != NULL)
	{
		_node->next->pre = _node->pre;
	}
	free(_node);
}

int  Delete_RecordNode(Record_List*_list, Record* _node)
{
	if (_node->pre == NULL)
	{
		return -1;
	}
	/*delete from a record list*/

	/*if this node is the last of all_record*/
	if (_node->next == NULL)
	{
		/*if this node is the first one of this user's records*/
		if (_list->head->next == _node)
		{
			_list->head->next = NULL;
			_list->tail = _list->head;
			all_record.tail = _node->pre;
			all_record.tail->next = NULL;
		}
		else
		{
			_list->tail = all_record.tail = _node->pre;
			_list->tail->next = all_record.tail = NULL;
		}
	}
	else
	{
		/*if it is the first one of this user's records*/
		if (_list->head->next == _node)
		{
			/*if it also is the last one of this user's records*/
			if (_list->tail == _node)
			{
				_list->tail = _list->head;
				_list->head->next = NULL;
				_node->pre->next = _node->next;
				_node->next->pre = _node->pre;
			}
			else
			{
				_list->head->next = _node->next;
				_node->pre->next = _node->next;
				_node->next->pre = _node->pre;

			}
		}
		else
		{
			/*if it is also the last one of this user's records*/
			if (_list->tail == _node)
			{
				_list->tail = _node->pre;
			}
			_node->pre->next = _node->next;
			_node->next->pre = _node->pre;
		}
	}

	/*refresh information*/
	all_record.node_number--;
	_list->node_number--;
	/*add to backup list*/
	Add_ToBackupList(_node);
	//Print_Record(backup_record);
	Save_BackupRecords();
	Save_Records();
	Save_Users();
	//		free(_node);
	return 0;
}


int FreeUserList(User_List _list)
{
	User*p = NULL;
	User*q = NULL;

	for (p = _list.head; p; p = q)
	{
		q = p->next;
		free(p);
	}
	_list.head->next = NULL;
	_list.tail = _list.head;
	_list.node_number = 1;
	return 0;
}

int FreeRecordList(Record_List _list)
{
	Record*p = NULL;
	Record*q = NULL;

	for (p = _list.head; p; p = q)
	{
		q = p->next;
		free(p);
	}
	_list.head->next = NULL;
	_list.tail = _list.head;
	_list.node_number = 1;
	return 0;
}

/*imput login number*/
char* Input_LoginNumber(char*_arr)
{
	/*put imput string here*/
	int i = 0;
	int ret = 0;
	Input_Window();
	do
	{
		/*imput login number and check*/

		ret = 0;
		Input_Window();
		printf("\n\n\tLogin Name[phone number] = ");
		scanf("%s", _arr);
		/*ensure the string are all number*/
		for (i = 0; _arr[i] != '\0'; i++)
		{
			if (_arr[i] < '0' || _arr[i] > '9')
			{
				Output_Window();
				ret = -1;
				printf("\n\n\t[Warnings]This is not a right phone number!");
				break;
			}

		}
		/*ensure the string is not longer than 11*/
		if (strlen(_arr) != 11)
		{
			Output_Window();
			ret = -1;
			printf("\n\n\t[Warnings]This is number is too short or too long!");
		}

	} while (ret == -1);
	return _arr;
}

/*to imput date*/
long int Input_Date()
{
	int i = 0;
	int ret = 0;
	long int _date = 0;
	long int cnt = 0;
	char str[51] = { 0 };
	do
	{
		Input_Window();
		ret = 0;
		Input_Window();
		printf("\n\n\t[Tips]Example : 20190101");
		printf("\n\n\t[year-month-day]Date = ");
		//		gets(str);
		scanf("%s", str);
		/*ensure the string are all number*/
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				Output_Window();
				ret = -1;
				printf("\n\n\t[Warnings]You should only imput numbers !");
				break;
			}

		}
		/*ensure the string is not too long or too short*/
		if (strlen(str) != 8)
		{
			Output_Window();
			ret = -1;
			printf("\n\n\t[Warnings]It seems that what you imput is too short or too long !");
		}
		else
		{
			/*change char to long int and check*/
			for (i = 0, _date = 0, cnt = 10000000; str[i] != '\0'; i++)
			{
				_date += (str[i] - 48)*cnt;
				cnt /= 10;
			}
			if (((_date % 10000) / 100) < 1 || ((_date % 10000) / 100) > 12 || (_date % 100) < 1 || (_date % 100) > 31)
			{
				ret = -1;
				Output_Window();
				printf("\n\t[Warnings]month=[%ld],day=[%ld]!", ((_date % 10000) / 100), (_date % 100));
				printf("\n\t[Warnings]What you input is not a valid date!");
				printf("\n\t[Warnings]Month should be between[1-12]!");
				printf("\n\t[Warnings]Day should be between [1-31]!");
			}
		}

	} while (ret == -1);
	return _date;
}

/*to imput amount of money*/
float Input_Money()
{
	float money = 0;
	int ret = 0;
	int cnt;
	do
	{
		ret = 0;
		Input_Window();
		printf("\n\n\tAmount[RMB] = ");
		cnt = scanf("%f", &money);
		if (cnt == 0)
		{
			Output_Window();
			ret = -1;
			printf("\n\n\t[Warnings]What you imput is not a number!");
			for (; getchar() != '\n';);
		}
		else
			/*check number*/
			if (money < 0)
			{
				Output_Window();
				ret = -1;
				printf("\n\n\t[Warnings]What you imput is invalid !");
			}
	} while (ret == -1);
	return money;
}

/*to imput type of deal*/
int Input_DealType()
{
	char type;
	int ret = 0;
	do
	{
		ret = 0;
		Input_Window();
		printf("\n\n\t[Tips] [p]for POS,[c]for cash,[m]for mobile pay");
		printf("\n\n\tDeal Type = [ ]\b\b");
		type = getch();
		if (type == 'p' || type == 'P')
			return POS;
		else
			if (type == 'c' || type == 'C')
				return cash;
			else
				if (type == 'm' || type == 'M')
					return mobile;
				else
				{
					Output_Window();
					ret = -1;
					printf("\n\n\t[Warnings]Invalid Type !");
				}
	} while (ret == -1);
	return defualt;
}


/*to imput color of theme*/
int Input_Color()
{
	char color;
	int ret = 0;
	do
	{
		ret = 0;
		Output_Window();
		printf("\n\n\tThe colors you can choose is as follow :\n\n");
		printf("\tBLUE----------------------[b]\n");
		printf("\tGREEN---------------------[g]\n");
		printf("\tCYAN----------------------[c]\n");
		printf("\tRED-----------------------[r]\n");
		printf("\tDARKGRAY------------------[d]\n");

		Input_Window();
		printf("\n\n\tPlease enter your choice :");
		printf("\n\n\tColor = [ ]\b\b");
		color = getch();
		if (color == 'b' || color == 'B')
			return BLUE;
		else
			if (color == 'g' || color == 'G')
				return GREEN;
			else
				if (color == 'c' || color == 'C')
					return CYAN;
				else
					if (color == 'd' || color == 'D')
						return DARKGRAY;
					else
						if (color == 'r' || color == 'R')
							return RED;
						else
						{
							Output_Window();
							ret = -1;
							printf("\n\n\t[Warnings]Invalid Type !");
						}
	} while (ret == -1);
	return	color;
}


int Input_AccounType()
{
	int ret = 0;
	int type = -1;
	do
	{
		ret = 0;
		Input_Window();
		printf("\n\n\tAccount Type[u for user,a for administrator] = ");
		printf("\n\n\tAccount Type = [ ]\b\b");
		type = getch();
		if (type == 'u' || type == 'U')
			type = USER;
		else
			if (type == 'a' || type == 'A')
				type = ADMINISTRATOR;
			else
			{
				Output_Window();
				ret = -1;
				printf("\n\n\t[Warnings]Invalid Type !");
				for (; getchar() != '\n';);
			}
	} while (ret == -1);
	return type;
}

/*input interval*/
int Input_Interval()
{
	char interval;
	int ret = 0;
	do
	{
		ret = 0;
		Input_Window();
		printf("\n\n\t[Tips]: [ m ] for month,[ t ] for term,[ y ] for year");
		printf("\n\n\tSearch By [ ]\b\b");
		interval = getch();
		printf("\n");

		if (interval == 'm' || interval == 'M')
			return MONTH;
		else
			if (interval == 't' || interval == 'T')
				return TERM;
			else
				if (interval == 'y' || interval == 'Y')
					return YEAR;
				else
				{
					Output_Window();
					ret = -1;
					printf("\n\n\t[Warnings]No suach Type !");
					if (bioskey(0) == ESC)return -1;
				}
	} while (ret == -1);
	return 0;
}

/*input ID*/
int Input_ID()
{
	int ret = 0;
	int id = 0;
	int cnt;

	do
	{
		ret = 0;
		Input_Window();
		printf("\n\n\tPlease enter number:");
		cnt = scanf("%d", &id);
		if (cnt == 0)
		{
			Output_Window();
			printf("\n\n\tWhat you imput is not a number!\n");
			for (; getchar() != '\n';);
			ret = -1;
		}
		else
			if (id < 0)
			{
				Output_Window();
				printf("\n\tWhat you imput is out of range!\n");
				ret = -1;
			}
	} while (ret == -1);
	return id;
}

/*to imput site of deal*/
char*Input_DealSite(char *_str)
{
	/*put imput string here*/
	int  ret = 0;
	do
	{
		ret = 0;
		Input_Window();
		printf("\n\n\t[Tips]Example : Beijing,China");
		printf("\n\n\tDeal site[Up to 50 char] = ");
		scanf("%s", _str);
		if (strlen(_str) > 50)
		{
			ret = -1;
			Output_Window();
			printf("\n\n\t[Warnings]This site name is too long!");
		}

	} while (ret == -1);
	return _str;
}

