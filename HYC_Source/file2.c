#include"file.h"

/*save current users*/
int Save_Users()
{
	User*plist;
	FILE*fp = fopen(".\\USER.TXT", "w");
	if (fp == NULL)
	{
		return -1;
	}

	/*do not save empty list and the head node*/
	if (all_user.head == NULL || all_user.head->next == NULL)
	{
		return -1;
	}

	/*write from the next of the head node*/
	for (plist = all_user.head->next; plist; plist = plist->next)
	{
		fprintf(fp, "%s %d %s %f %d\n", plist->login_name, plist->account_type, plist->password, plist->my_money, plist->my_record.node_number);
	}

	fclose(fp);
	return 0;
}

/*read saved  users*/
int Read_Users()
{
	User*plist;//point to list
	User*getuser;//read from file
	int cnt;//count how many user are there
	FILE*fp = fopen("USER.TXT", "r");
	if (fp == NULL)
	{
		printf("error:can not open file-----user.txt\n\n");
		getch();
		return -1;
	}

	/*read from the next of the head node*/
	for (plist = all_user.head, cnt = 0;; plist = getuser, cnt++)
	{
		getuser = (User*)malloc(sizeof(User));
		/*create a record list for each user*/
		getuser->my_record = Create_RecordList();
		if (fscanf(fp, "%s %d %s %f %d", getuser->login_name, &getuser->account_type, getuser->password, &getuser->my_money, &getuser->my_record.node_number) == -1)
			break;

		/*link to all_user*/
		plist->next = getuser;
		getuser->pre = plist;
	}
	all_user.node_number = (cnt + 1);
	all_user.tail = plist;
	plist->next = NULL;

	fclose(fp);
	return 0;
}

/*save current records*/
int Save_Records()
{
	Record*plist;
	FILE*fp = fopen(".\\FEE.TXT", "w");
	if (fp == NULL)
	{
		return -1;
	}

	/*do not save empty list and the head node*/
	if (all_record.head == NULL || all_record.head->next == NULL)
	{
		return -1;
	}

	/*write from the next of the head node*/
	for (plist = all_record.head->next; plist; plist = plist->next)
	{
		fprintf(fp, "%d %ld %ld %f %f %d %s\n", plist->id, plist->deal_date, plist->account_date, plist->deal_amount, plist->balance, plist->deal_type, plist->deal_site);
	}

	fclose(fp);
	return 0;
}

/*read saved records*/
int Read_Records()
{
	Record*plist;
	Record*getrecord;
	User*getuser;
	int i = 0;
	int getlist = 0;//getlist==1 ->the user haved get his record list
	FILE*fp = fopen("FEE.TXT", "r");

	if (fp == NULL)
	{
		printf("error:can not open file-----fee.txt\n\n");
		getch();
		return -1;
	}

	/*read from the next of the head node*/
	for (getuser = all_user.head->next, plist = all_record.head, i = 0;; plist = getrecord)
	{

		getrecord = (Record*)malloc(sizeof(Record));
		if (fscanf(fp, "%d %ld %ld %f %f %d %s\n", &getrecord->id, &getrecord->deal_date, &getrecord->account_date, &getrecord->deal_amount, &getrecord->balance, &getrecord->deal_type, getrecord->deal_site) == EOF)
			break;
		/*link to record list*/
		plist->next = getrecord;
		getrecord->pre = plist;

		/*link to user.my_record*/
		if (getlist == 0)
		{
			/*this user get his list*/
			getlist = 1;
			getuser->my_record.head->next = getrecord;
		}
		i++;
		if (i == getuser->my_record.node_number - 1)
		{
			/*he get his all records,come to the next user*/
			getuser->my_record.tail = getrecord;
			getuser = getuser->next;
			getlist = 0;
			i = 0;
		}
	}
	all_record.tail = plist;
	plist->next = NULL;

	fclose(fp);
	return 0;
}

/*save deleted records*/
int Save_BackupRecords()
{
	Record*plist;
	FILE*fp = fopen(".\\UNDE_FEE.TXT", "w");
	if (fp == NULL)
	{
		return -1;
	}

	/*do not save empty list and the head node*/
	if (backup_record.head == NULL || backup_record.head->next == NULL)
	{
		return -1;
	}

	/*write from the next of the head node*/
	for (plist = backup_record.head->next; plist; plist = plist->next)
	{
		fprintf(fp, "%d %ld %ld %f %f %d %s\n", plist->id, plist->deal_date, plist->account_date, plist->deal_amount, plist->balance, plist->deal_type, plist->deal_site);
	}

	fclose(fp);
	return 0;
}

/*read backup records*/
int Read_BackupRecords()
{
	Record*plist;
	Record*getrecord;
	FILE*fp = fopen("UNDE_FEE.TXT", "r");
	if (fp == NULL)
	{
		printf("error:can not open file-----undel_fee.txt\n\n");
		getch();
		return -1;
	}

	for (plist = backup_record.head;;)
	{
		getrecord = (Record*)malloc(sizeof(Record));
		if (fscanf(fp, "%d %ld %ld %f %f %d %s\n", &getrecord->id, &getrecord->deal_date, &getrecord->account_date, &getrecord->deal_amount, &getrecord->balance, &getrecord->deal_type, getrecord->deal_site) == EOF)
			break;
		/*link to record list*/
		plist->next = getrecord;
		getrecord->pre = plist;
		plist = getrecord;
	}

	backup_record.tail = plist;
	plist->next = NULL;

	fclose(fp);
	return 0;
}

/*save conf*/ 
int Save_Config()
{
	Record*plist;
	FILE*fp = fopen(".\\CONF.TXT", "w");
	if (fp == NULL)
	{
		return -1;
	}

	fprintf(fp, "%d", bkcolor);

	fclose(fp);
	return 0;
}

/*read config*/
int Read_Config()
{
	FILE*fp = fopen("CONF.TXT", "r");
	if (fp == NULL)
	{
		return -1;
	}

	fscanf(fp, "%d", &bkcolor);
	fclose(fp);
	return 0;
}


