#include"function.h"

Record_List* object = NULL;

int Start_Function()
{
	Read_Users();
	Read_Records();
	Read_BackupRecords();
	Read_Config();

	Start_Window();
	Login_Window();

	if (login_now->account_type == ADMINISTRATOR)
	{
		object = &all_record;
	}
	else
	{
		object = &login_now->my_record;
	}
	return 0;
}


int Search_Function(int _getchoice)
{
	long int from_date, to_date, temp_num;
	int ret = 0;
	float min, max;
	char site[26];
	char str[12];
	PListNode*temp = NULL;
	Record*getrecord = NULL;
	User*getuser = NULL;
	Output_Window();
	Input_Window();

	do
	{
		ret = 0;
		/*go to execute the funtion*/
		switch (_getchoice)
		{
			/*search my banlance*/
		case 1:
			Output_Window();
			printf("\n\n\tyour banlance is now : %f\n", login_now->my_money);
			if (bioskey(0) == ESC)return 0;
			break;
			/*serach by deal date*/
		case 2:
			Output_Window();
			printf("\n\n\tplease input the date you want to search [from] below\n");

			Input_Window();
			from_date = Input_Date();

			Output_Window();
			printf("\n\n\tplease input the date you want to search [to] below\n");

			Input_Window();
			to_date = Input_Date();

			if (from_date >= to_date)
			{
				Output_Window();
				printf("\n\n\tthe date [from] is later than [to] !\n");
				printf("\n\tpress any key to input angain...\n");
				if (bioskey(0) == ESC)return  0;
				ret = -1; break;
			}

			Output_Window();
			temp = Search_ByDate(*object, from_date, to_date);

			if (temp == NULL)
			{
				Output_Window();
				printf("\n\n\tsorry,no such record...\n");
				printf("\n\tpress any key to continue...\n");
				if (bioskey(0) == ESC)return  0;
			}
			else
			{
				Print_RecordBySearch(temp);
				if (bioskey(0) == ESC)return  0;
			}
			break;

			/*search by deal amount*/
		case 3:

			Output_Window();
			printf("\n\n\tplease input the [min] amount you want to search below\n");

			Input_Window();
			min = Input_Money();

			Output_Window();
			printf("\n\n\tplease input the [max] amount you want to search below\n");

			Input_Window();
			max = Input_Money();

			if (min >= max)
			{
				Output_Window();
				printf("\n\n\tthe [min] amount exceed the [max] one !\n");
				printf("\n\n\tyou can press [ESC] key to go back to menu\n");
				printf("\n\n\tpress any other key to input angain...\n");
				if (bioskey(0) == ESC)return  0;
				ret = -1; break;
			}

			Output_Window();
			temp = Search_ByAmount(*object, min, max);
			if (temp == NULL)
			{
				Output_Window();
				printf("\n\n\tsorry,no such record...\n");
				printf("\n\tpress any key to continue...\n");
				if (bioskey(0) == ESC)return  0;
			}
			else
			{
				Print_RecordBySearch(temp);
				if (bioskey(0) == ESC)return  0;
			}
			break;

			/*search by deal type*/
		case 4:

			Output_Window();
			printf("\n\n\tplease input the [deal type] you want to search below\n");

			Input_Window();
			temp_num = Input_DealType();

			Output_Window();
			temp = Search_ByDealType(*object, temp_num);

			if (temp == NULL)
			{
				Output_Window();
				printf("\n\n\tsorry,no such record...\n");
				printf("\n\tpress any key to continue...\n");
				getch();
			}
			else
			{
				Print_RecordBySearch(temp);
				if (bioskey(0) == ESC)return  0;
			}
			break;

			/*search by each month,term,year*/
		case 5:
			Output_Window();
			printf("\n\n\tplease input the [interval] you want to search below\n");

			Input_Window();
			temp_num = Input_Interval();

			Output_Window();
			Sort_ByInterval(object, temp_num);

			if (interval_record.head == NULL || interval_record.head->next == NULL)
			{
				Output_Window();
				printf("\n\n\tsorry,no record or interval invalid...\n");
				printf("\n\tpress any key to continue...\n");
				getch();
			}
			else
			{
				Print_Record(interval_record);
				if (bioskey(0) == ESC)return  0;
			}
			break;

			/*search in deleted records*/
		case 6:

			/*choose a id to search*/
			Output_Window();
			printf("\n\n\tplease input the [record ID] you want to search below\n");

			Input_Window();
			temp_num = Input_ID();

			Output_Window();
			getrecord = Search_RecordByID(backup_record, temp_num);
			if (getrecord == NULL)
			{
				Output_Window();
				printf("\n\n\tsorry,no such record...\n");
				printf("\n\tpress any key to continue...\n");
				if (bioskey(0) == ESC)return  0;
			}
			else
			{
				setviewport(0, 0, 639, 479, 1);
				cleardevice();
				window(1, 1, 80, 1);
				printf("\nID    DL_DATE  AC_DATE      AMOUNT        BALANCE   TYPE    SITE");
				window(1, 3, 80, 25);
				/* id date date amount balance*/
				printf("%-5d %-8ld %-8ld %12.2f %12.2f ", getrecord->id, getrecord->deal_date, getrecord->account_date, -(getrecord->deal_amount), getrecord->balance);
				/*deal type*/
				printf(" %-6s ", getrecord->deal_type == 1 ? "POS" : getrecord->deal_type == 2 ? "cash" : getrecord->deal_type == 3 ? "mobile" : "default");
				/*deal site*/
				strncpy(site, getrecord->deal_site, 20);/*only print 20 char*/
				printf(" %s\n", site);
				if (bioskey(0) == ESC)return  0;
			}
			break;

			/*search a record by ID*/
		case 7:
			do
			{
				ret = 0;
				Output_Window();
				printf("\n\n\tplease input the user's account you want to search in\n");

				Input_Window();
				Input_LoginNumber(str);

				getuser = Search_Account(all_user, str);
				if (str == NULL)
				{
					Output_Window();
					printf("\n\n\tno such user !\n");
					printf("\n\tpress any key to continue...\n");
					ret = -1;
					if (bioskey(0) == ESC)return  0;
				}
			} while (ret == -1);

			Output_Window();
			printf("\n\n\tplease input the [record ID] you want to search below\n");

			Input_Window();
			temp_num = Input_ID();

			getrecord = Search_RecordByID(getuser->my_record, temp_num);
			if (getrecord == NULL)
			{
				Output_Window();
				printf("\n\n\tsorry,no such record...\n");
				printf("\n\tpress any key to continue...\n");
				if (bioskey(0) == ESC)return  0;
			}
			else
			{
				Output_Window();
				printf("%-5d% -8ld% -8ld% -9.2f% -9.2f ", getrecord->id, getrecord->deal_date, getrecord->account_date, getrecord->deal_amount, getrecord->balance);
				/*deal type*/
				printf("%-6s ", getrecord->deal_type == 1 ? "POS" : getrecord->deal_type == 2 ? "cash" : getrecord->deal_type == 3 ? "mobile" : "default");
				/*deal site*/
				strncpy(site, getrecord->deal_site, 25);/*only print 29 char*/
				printf("%-s\n", site);
				if (bioskey(0) == ESC)return  0;
			}

		default:
			break;
		}
	} while (ret == -1);
	return 0;
}

int Sort_Function(int _getchoice)
{
	/*go to execute the funtion*/
	switch (_getchoice)
	{

		/*sort by date and print*/
	case 1:
		if (object->head == NULL || object->head->next == NULL)
		{
			Output_Window();
			printf("\n\n\tsorry,there is no record now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Output_Window();
			Sort_ByDate(object);
			Print_Record(*object);
			Read_Records();
			if (bioskey(0) == ESC)return  0;
		}

		break;

		/*sort by date and print from tail*/
	case 2:
		if (object->head == NULL || object->head->next == NULL)
		{
			Output_Window();
			printf("\n\n\tsorry,there is no record now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Output_Window();
			Sort_ByDate(object);
			Print_RecordFromTail(*object);
			Read_Records();
			if (bioskey(0) == ESC)return  0;
		}

		break;

		/*sort by amount and print*/
	case 3:

		if (object->head == NULL || object->head->next == NULL)
		{
			Output_Window();
			printf("\n\n\tsorry,there is no record now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Output_Window();
			Sort_ByAmount(object);
			Print_Record(*object);
			Read_Records();
			if (bioskey(0) == ESC)return  0;
		}
		break;

		/*sort by amount and print from tail*/
	case 4:

		if (object->head == NULL || object->head->next == NULL)
		{
			Output_Window();
			printf("\n\n\tsorry,there is no record now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Output_Window();
			Sort_ByAmount(object);
			Print_RecordFromTail(*object);
			Read_Records();
			if (bioskey(0) == ESC)return  0;
		}
		break;

		/*sort by ID and print*/
	case 5:

		if (object->head == NULL || object->head->next == NULL)
		{
			Output_Window();
			printf("\n\n\tsorry,there is no record now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Sort_ByID(object);
			Output_Window();
			Print_Record(*object);
			Read_Records();
			if (bioskey(0) == ESC)return  0;
		}
		break;

		/*sort by ID and print from tail*/
	case 6:

		if (object->head == NULL || object->head->next == NULL)
		{
			Output_Window();
			printf("\n\n\tsorry,there is no record now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Sort_ByID(object);
			Output_Window();
			Print_RecordFromTail(*object);
			Read_Records();
			if (bioskey(0) == ESC)return  0;
		}
		break;

	default:

		break;
	}
	return 0;
}

int Count_Function(int _getchoice)
{
	float cnt;
	long int from_date, to_date;
	int ret = 0;
	char number[12] = { 0 };
	PListNode*temp = NULL;
	Record*temp2 = NULL;
	User*_user = NULL;
	Output_Window();;
	Input_Window();

	/*go to execute the funtion*/
	switch (_getchoice)
	{
		/*count amount of login now account*/
	case 1:

		Output_Window();
		if (login_now->my_record.head == NULL || login_now->my_record.head->next == NULL)
		{
			printf("\n\n\tsorry,there is no record now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			cnt = Count_Amount(login_now->my_record);
			printf("\n\n\tthe total amount of your consumption is : %-10.2f\n", -cnt);
			if (bioskey(0) == ESC)return  0;
		}
		break;

		/*choose a date period to count amount*/
	case 2:

		Output_Window();
		printf("\n\n\tplease input the date you want to count [from] below\n");

		Input_Window();
		from_date = Input_Date();

		Output_Window();
		printf("\n\n\tplease input the date you want to count [to] below\n");

		Input_Window();
		to_date = Input_Date();

		Output_Window();
		printf("\n\n\tSearching from [%ld] to [%ld]....\n", from_date, to_date);
		if (from_date >= to_date)
		{
			Output_Window();
			printf("\n\n\tthe date [from] is later than [to] !\n");
			printf("\n\tpress any key to input angain...\n");
			if (bioskey(0) == ESC)return  0;
			ret = -1; break;
		}

		Output_Window();
		temp = Search_ByDate(all_record, from_date, to_date);
		if (temp == NULL)
		{
			Output_Window();
			printf("\n\n\tsorry,no such record...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Output_Window();
			cnt = Count_BySearch(temp);
			printf("\n\n\tthe consumption of this period of time is :%-20.2f\n", -cnt);
			getch();
		}
		break;

		/*choose a specific user to count */
	case 3:

		Output_Window();
		printf("\n\n\tplease input the user's account number you want to count\n");

		Input_Window();
		Input_LoginNumber(number);

		_user = Search_Account(all_user, number);
		if (_user == NULL)
		{
			Output_Window();
			printf("\n\n\tno such user !\n");
			printf("\n\n\tyou can press [ESC] key to go back to menu\n");
			printf("\n\n\tpress any other key to input angain...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Output_Window();
			cnt = Count_Amount(_user->my_record);
			printf("\n\n\tthe consumption of this user is :%-20.2f\n", -cnt);
			if (bioskey(0) == ESC)return 0;
		}

		break;

		/*count all user amount*/
	case 4:

		Output_Window();
		if (object->head == NULL || object->head->next == NULL)
		{
			printf("\n\n\tsorry,there is no record now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			cnt = Count_Amount(*object);
			printf("\n\n\tthe total amount of all user's consumption is : %-10.2f\n", -cnt);
			if (bioskey(0) == ESC)return  0;
		}
		break;
		/*print all user*/
	case 5:

		Output_Window();
		if (all_user.head == NULL || all_user.head->next == NULL)
		{
			printf("\n\n\tsorry,there is no user now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Print_User(all_user);
			if (bioskey(0) == ESC)return  0;
		}
		break;
		/*pritn all record*/
	case 6:

		Output_Window();
		if (all_record.head == NULL || all_record.head->next == NULL)
		{
			printf("\n\n\tsorry,there is no record now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			setbkcolor(DARKGRAY);
			setviewport(0, 0, 639, 479, 1);
			cleardevice();
			Print_Record(all_record);
			PrintRecord_Window();
			if (bioskey(0) == ESC)return  0;
		}
		break;
		/*print all deleted reords*/
	case 7:

		Output_Window();
		if (backup_record.head == NULL || backup_record.head->next == NULL)
		{
			printf("\n\n\tsorry,there is no deleted record now...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Print_Record(backup_record);
			if (bioskey(0) == ESC)return  0;
		}
		break;
	default:
		break;
	}
	return 0;
}


int Input_Function(int _getchoice)
{
	User* getuser = NULL;
	Record* getrecord = NULL;
	char str[12];
	int i = 0, ret = 0, cnt = 0, num = 0;

	Output_Window();
	printf("\n\n\thow many records or users do you want to add?\n");

	/*let him choose how many times to add first*/
	do
	{
		ret = 0;
		Input_Window();
		printf("\n\n\tPlease enter number:");
		cnt = scanf("%d", &num);

		if (cnt == 0)
		{
			Output_Window();
			printf("\n\n\tWhat you imput is not a number!\n");
			if (bioskey(0) == ESC)return  0;
			for (; getchar() != '\n';);
			ret = -1;
		}
		else
			if (num <= 0)
			{
				Output_Window();
				printf("\n\tWhat you imput is out of range !\n");
				if (bioskey(0) == ESC)return  0;
				ret = -1;
			}
	} while (ret == -1);

	for (i = 0; i < num; i++)
	{
		/*go to execute the funtion*/
		switch (_getchoice)
		{

			/*input a user imformation*/
		case 1:
			Output_Window();
			printf("\n\n\tplease input the [NO.%d] user below\n", i + 1);

			Input_Window();
			getuser = Create_UserNode();

			Add_User(&all_user, getuser);
			Save_Function(0);
			break;

		case 2:
			/*if he want to input record ask him to choose account first*/
			do
			{
				ret = 0;
				Output_Window();
				printf("\n\n\tplease input the user's account you want to add record\n");

				Input_Window();
				Input_LoginNumber(str);

				getuser = Search_Account(all_user, str);
				if (getuser == NULL)
				{
					Output_Window();
					printf("\n\n\tno such user !\n");
					printf("\n\tpress any key to continue...\n");
					ret = -1;
					if (bioskey(0) == ESC)return  0;
				}
				if (bioskey(0) == ESC)
					return 0;
			} while (ret == -1);

			Output_Window();
			printf("\n\n\tplease input the [NO.%d] reocord below\n", i + 1);
			
			Input_Window();
			getrecord = Create_RecordNode();
			
			getuser->my_money = getrecord->balance = (getuser->my_money - getrecord->deal_amount);
			getrecord->id = getuser->my_record.node_number;
			Add_Record(&getuser->my_record, getrecord);
			Save_Function(0);
			break;
		default:
			break;
		}
	}
	return 0;
}

int Modify_Function(int _getchoice)
{

	long int temp_num = 0;
	User* getuser = NULL;
	Record* getrecord = NULL;
	char str[12], site[51], n;
	char text[4][30] = { {"Do u want to delete now?(y/n)"},{"Please enter your choice..."} ,{" "} ,{"Warnings"} };
	char text2[4][30] = { {"Recharge succeed !"},{""} ,{"press any key to go back"} ,{"SUCCEED"} };
	int i = 0, ret = 0, cnt = 0, num = 0;
	Output_Window();
	Input_Window();
	/*ask him to choose account first*/
	do
	{
		ret = 0;
		Output_Window();
		printf("\n\n\tplease input the user's account you want to modify\n");

		Input_Window();
		Input_LoginNumber(str);

		getuser = Search_Account(all_user, str);
		if (getuser == NULL)
		{
			Output_Window();
			printf("\n\n\tno such user !\n");
			printf("\n\tpress any key to continue...\n");
			ret = -1;
			if (bioskey(0) == ESC)return  0;
		}
	} while (ret == -1);

	/*ask him to choose record id first*/
	if (_getchoice == 1 || _getchoice == 2)
	{
		Output_Window();
		printf("\n\n\tplease input the [record ID] you want to modify or delete below\n");

		Input_Window();
		temp_num = Input_ID();

		Output_Window();

		getrecord = Search_RecordByID(getuser->my_record, temp_num);
		if (getrecord == NULL)
		{
			Output_Window();
			printf("\n\n\tsorry,no such record...\n");
			printf("\n\tpress any key to continue...\n");
			if (bioskey(0) == ESC)return  0;
		}
		else
		{
			Output_Window();
			printf("\n\n\tthe record you input is as follow\n\t");
			printf("%-5d% -8ld% -8ld% -9.2f% -9.2f ", getrecord->id, getrecord->deal_date, getrecord->account_date, -(getrecord->deal_amount), getrecord->balance);
			/*deal type*/
			printf("%-6s ", getrecord->deal_type == 1 ? "POS" : getrecord->deal_type == 2 ? "cash" : getrecord->deal_type == 3 ? "mobile" : "default");
			/*deal site*/
			strncpy(site, getrecord->deal_site, 25);/*only print 29 char*/
			printf("%-s\n", site);
			if (bioskey(0) == ESC)return  0;
		}
	}

	/*go to execute the funtion*/
	switch (_getchoice)
	{
	case 1:
		if (getrecord != NULL)
		{

			/*modify deal date*/
			Input_Window();
			printf("\n\n\tPlease imput deal date below ");
			getrecord->deal_date = Input_Date();

			/*modufy account date*/
			printf("\n\n\tPlease imput account date below ");
			getrecord->account_date = Input_Date();

			/*modify deal amount*/
			printf("\n\n\tPlease imput deal amount below ");
			getrecord->deal_amount = Input_Money();

			/*modify deal type*/
			printf("\n\n\tPlease imput deal type below ");
			getrecord->deal_type = Input_DealType();

			/*modify deal site*/
			printf("\n\n\tPlease imput deal site below ");
			Input_DealSite(getrecord->deal_site);
		}

		break;
	case 2:

		if (getrecord != NULL)
		{
			do
			{
				Draw_MessageWindow(text);
				n = getch();
				if (n == 'y' || n == 'Y')
				{
					Delete_RecordNode(&getuser->my_record, getrecord);
					Input_Window();
					Output_Window();
					printf("\n\n\tthis record has been deleted !\n");
					printf("\n\tit has been saved to backup file[ undel_fee.txt ]\n");
					if (bioskey(0) == ESC)return  0;
					break;
				}
				else
					if (n == 'n' || n == 'N')
					{
						break;
					}
			} while (1);
		}

		break;
	case 3:
		if (getuser != NULL)
		{
			Output_Window();
			printf("\n\n\thow much do you want to recharge for him ?\n");
			printf("\n\tPlease imput deal amount below \n");

			getuser->my_money += Input_Money();
			Save_Records();
			Save_Users();

			Draw_MessageWindow(text2);
			if (bioskey(0) == ESC)return  0;
			break;
		}
	default:
		break;
	}
	return 0;
}

int Save_Function(int _getchoice)
{
	char n;
	char text[4][30] = { {"Do you want to save now?(y/n)"},{"Please enter your choice..."} ,{" "} ,{"Suggestions"} };
	do
	{
		Draw_MessageWindow(text);
		n = getch();
		if (n == 'y' || n == 'Y')
		{
			Save_BackupRecords();
			Save_Users();
			Save_Records();
			Input_Window();
			Output_Window();
			printf("\n\n\tall the data have been saved !\n");
			printf("\n\tthe users data file is [ user.txt ]\n");
			printf("\n\tthe records data file is [ fee.txt ]\n");
			printf("\n\tthe deleted records data file is [ undel_fee.txt ]\n");
			printf("\n\tyou can find them in the file folder []\n");
			if (bioskey(0) == ESC)return  0;
			break;
		}
		else
			if (n == 'n' || n == 'N')
			{
				break;
			}
	} while (1);
	return 0;
}

int Setting_Function(int _getchoice)
{
	int ret = 0;
	char getpassword[20];
	char text[4][30] = { {"You haved reset your password"},{ 0},{"press any key to go back"},{"SUCCEED"} };
	Output_Window();
	Input_Window();
	switch (_getchoice)
	{
	case 1:
		bkcolor = Input_Color();
		Save_Config();
		break;
	case 2:

		do
		{
			/*imput login password check*/
			ret = 0;

			Output_Window();
			printf("\n\tPlease enter your former password:");
			scanf("%s", getpassword);
			if (bioskey(0) == ESC)return 0;
			if (strcmp(getpassword, login_now->password) != 0)
			{
				ret = -1;
				printf("\n\tPassword incorrect! Please enter again:");
			}
			else
			{
				printf("\n\n\tPlease enter new password:");
				printf("\n\n\tLogin Password[less than 20 char] = ");
				scanf("%s", getpassword);
				/*ensure the string is not longer than 20*/
				if (strlen(getpassword) > 20)
				{
					ret = -1;
					printf("\n\n\t[Warnings]The password is too long !");
				}
				else
				{
					strcpy(login_now->password, getpassword);
					Save_Records();
					Save_Users();
					sprintf(text[1], "your new password is :%s", getpassword);
					Draw_MessageWindow(text);
					getch();
				}
			}
		} while (ret == -1);
		break;
	default:
		break;
	}
	return 0;
}


int Quit_Function(int _getchoice)
{
	char text[4][30] = { {"Are you sure to quit?"},{"press enter to comfirm"} ,{"press any other key to cancel"} ,{"Warnings"} };

	Draw_MessageWindow(text);
	sound(300);
	delay(500);
	nosound();
	if (bioskey(0) == ENTER)
		exit(0);
	return 0;
}

