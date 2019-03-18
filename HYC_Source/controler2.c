#include"controler.h"

int MessageListener(char _text[10][50], char*_title, int _origin_point, int _bar_number)
{
	int _getchoice = 1;
	/*initialize menu interface*/
	DrawMenu(1, _text, _title, _origin_point, _bar_number);
	Refresh_DrawMenu(1, _text, _title, _origin_point, _bar_number);

	do
	{
		switch (bioskey(0))
		{
			/*menu go up*/
		case UP:

			if (_getchoice > 1)
			{
				sound(200);
				delay(50);
				nosound();
				_getchoice--;
			}

			Refresh_DrawMenu(_getchoice, _text, _title, _origin_point, _bar_number);

			break;

			/*menu go down*/
		case DOWN:

			if (_getchoice < _bar_number)
			{
				sound(200);
				delay(20);
				nosound();
				_getchoice++;
			}

			Refresh_DrawMenu(_getchoice, _text, _title, _origin_point, _bar_number);

			break;

			/*choose a function*/
		case ENTER:

			sound(400);
			delay(20);
			nosound();
			return _getchoice;
			break;

			/*exit*/
		case ESC:
			return _getchoice = -1;
		default:
			break;
		}
	} while (1);
}

int SubMenu(int _getchoice)
{
	/*go to second class menu*/

	switch (_getchoice)
	{
	case SEARCH:
		Search_Activity();
		break;
	case SORT:
		Sort_Activity();
		break;
	case COUNT:
		Count_Activity();
		break;
	case INPUT:
		Input_Activity();
		break;
	case MODIFY:
		Modify_Activity();
		break;
	case SAVE:
		Save_Activity();
		break;
	case SETTING:
		Setting_Activity();
		break;
	case QUIT:
		Quit_Activity();
	default:
		break;
	}
	return 0;
}

int Start_Activity()
{
	/*shart up*/
	Start_Function();
	return 0;
}

int Main_Activity()
{

	int choose = 0;/*choose =1 -> goto function*/
	int bar_number = 8;
	int origin_point = 90;
	char text[10][50] = { {"Option 1 : Search "},{"Option 2 : Sort "},
							{"Option 3 : Statistics"},{"Option 4 : Input"},
							{"Option 5 : Modify"} ,{"Option 6 : Save"} ,
							{"Option 7 : Setting"} ,{"Option 8 : Quit"} };
	char *title = "HOME";
	/*block users*/
	if (login_now->account_type == USER)
		bar_number = 3;

	do
	{
		choose = MessageListener(text, title, origin_point, bar_number);
		if (choose == -1)
		{
			Quit_Function(1);
		}
		else
		{
			SubMenu(choose);
			choose = 0;
		}
	} while (1);
	return 0;
}



int Search_Activity()
{
	int choose = 0;/*choose =1 -> goto function*/
	int bar_number = 7;
	int origin_point = 90;
	char text[10][50] = { {"1 : Check my balance"},{"2 : Search by date"},
							{"3 : Search by amount"},{"4 : Search by payment type"},
							{"5 : Search by month/term/year"},{"6 : Search in deleted records"},
							{"7 : Search by ID"} };
	char title[10] = { "SEARCH" };

	/*block users*/
	if (login_now->account_type == USER)
		bar_number = 5;

	do
	{
		choose = MessageListener(text, title, origin_point, bar_number);
		if (choose == -1)
		{
			return 0;
		}
		else
		{
			Search_Function(choose);
			choose = 0;
		}
	} while (1);
	return 0;
}

int Sort_Activity()
{
	int choose = 0;/*choose =1 -> goto function*/
	int bar_number = 6;
	int origin_point = 90;
	char text[10][50] = { {"1 : Sort from earliest to latest"},{"2 : Sort from latest to earliest "},
							{"3 : Sort from min to max amount"},{"4 : Sort from max to min amount"},
							{"5 : Sort from min to max id"},{"6 : Sort from max to min id"} };
	char title[10] = { "SORT" };

	do
	{
		choose = MessageListener(text, title, origin_point, bar_number);
		if (choose == -1)
		{
			return 0;
		}
		else
		{
			Sort_Function(choose);
			choose = 0;
		}
	} while (1);
	return 0;
}

int Count_Activity()
{
	int choose = 0;/*choose =1 -> goto function*/
	int bar_number = 7;
	int origin_point = 90;
	char text[10][50] = { {"1 : Count my amount"},{"2 : Count in a specific period of time"},
							{"3 : Count amount of a specific user"},{"4 : Count all user's amount"},
							{"5 : Check all users"},{"6 : Check all records"},{"7 : Check all deleted records"} };
	char title[10] = { "STATISTIC" };

	/*block users*/
	if (login_now->account_type == USER)
		bar_number = 2;

	do
	{
		choose = MessageListener(text, title, origin_point, bar_number);
		if (choose == -1)
		{
			return 0;
		}
		else
		{
			Count_Function(choose);
			choose = 0;
		}
	} while (1);
	return 0;
}

int Input_Activity()
{
	int choose = 0;/*choose =1 -> goto function*/
	int bar_number = 2;
	int origin_point = 90;
	char text[10][50] = { {"1 : Add new users "},{"2 : Add new records"} };
	char title[10] = { "INPUT" };

	do
	{
		choose = MessageListener(text, title, origin_point, bar_number);
		if (choose == -1)
		{
			return 0;
		}
		else
		{
			Input_Function(choose);
			choose = 0;
		}
	} while (1);
	return 0;
}

int Modify_Activity()
{
	int choose = 0;/*choose =1 -> goto function*/
	int bar_number = 3;
	int origin_point = 90;
	char text[10][50] = { {"1 : Modify a record"},{"2 : Delete a record"},{"3 : Recharge for user's account"} };
	char title[10] = { "MODIFY" };

	do
	{
		choose = MessageListener(text, title, origin_point, bar_number);
		if (choose == -1)
		{
			return 0;
		}
		else
		{

			Modify_Function(choose);
			choose = 0;
		}
	} while (1);
	return 0;
}


int Save_Activity()
{
	Save_Function(0);
	return 0;
}


int Setting_Activity()
{
	int choose = 0;/*choose =1 -> goto function*/
	int bar_number = 2;
	int origin_point = 90;
	char text[10][50] = { {"1 : Theme setting"},{"2 : Password reset"} };
	char title[10] = { "SETTING" };

	do
	{
		choose = MessageListener(text, title, origin_point, bar_number);
		if (choose == -1)
		{
			return 0;
		}
		else
		{

			Setting_Function(choose);
			choose = 0;
		}
	} while (1);
	return 0;
}


int Quit_Activity()
{
	Quit_Function(0);
	return 0;
}



