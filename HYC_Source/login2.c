#include"login.h"


int Login_Window()
{
	int x1, y1, x2, y2;
	int ret = 0;
	int origin_point = 100;
	int width = 240;
	int length = 320;
	char account[30] = { 0 };
	char password[30] = { 0 };
	User* getuser;
	y1 = (480 - width) / 2, y2 = y1 + width, x1 = (640 - length) / 2, x2 = 640 - x1;

	do
	{
		ret = 0;
		/*initialize*/
		setbkcolor(DARKGRAY);
		cleardevice();

		/*background*/
		setfillstyle(11, DARKGRAY);
		bar(x1 + 20, y1 + 20, x2 + 20, y2 + 20);
		setfillstyle(1, LIGHTGRAY);
		bar(x1, y1, x2, y2);
		setlinestyle(SOLID_LINE, 0, 1);
		setcolor(WHITE);
		rectangle(x1 + 3, y1 + 3, x2 - 3, y2 - 3);
		rectangle(x1 + 5, y1 + 5, x2 - 5, y2 - 5);


		/*title bar*/
		setfillstyle(1, BLUE);
		bar(x1 + 10, y2 - 35, x2 - 10, y2 - 10);


		/*input window*/
		rectangle(x1 + 120, y1 + 52, x2 - 10, y1 + 75);
		rectangle(x1 + 120, y1 + 102, x2 - 10, y1 + 125);

		/*title text*/
		settextstyle(1, 0, 1);
		setcolor(WHITE);
		outtextxy(x1 + 120, y2 - 35, "  LOGIN  ");
		//outtextxy(x1 + 40, y1 + 170, "");

		setcolor(DARKGRAY);
		outtextxy(x1 + 20, y1 + 50, "Account");
		outtextxy(x1 + 20, y1 + 100, "Password");

		//setcolor(WHITE);

		/*input window pointer*/
		/*account*/
		setlinestyle(SOLID_LINE, 0, 1);
		setcolor(DARKGRAY);
		rectangle(x1 + 118, y1 + 50, x2 - 8, y1 + 77);
		gotoxy(37, 12);
		scanf("%s", account);
		/*password*/
		rectangle(x1 + 118, y1 + 100, x2 - 8, y1 + 127);
		gotoxy(37, 15);
		scanf("%s", password);

		/*find account*/
		getuser = Search_Account(all_user, account);

		if (getuser == NULL)
		{
			/*title bar*/
			setfillstyle(1, RED);
			bar(x1 + 10, y2 - 35, x2 - 10, y2 - 10);
			/*title text*/
			settextstyle(1, 0, 1);
			setcolor(WHITE);
			outtextxy(x1 + 65, y2 - 35, "ACCOUNT NOT FOUNT");
			sound(100);
			delay(400);
			nosound();
			delay(800);
			ret = -1;

		}
		else
		{
			if (strcmp(password, getuser->password) == 0)
			{
				/*title bar*/
				setfillstyle(1, GREEN);
				bar(x1 + 10, y2 - 35, x2 - 10, y2 - 10);
				/*title text*/
				settextstyle(1, 0, 1);
				setcolor(WHITE);
				outtextxy(x1 + 120, y2 - 35, "SUCCEED ");
				sound(500);
				delay(500);
				nosound();
				login_now = getuser;
				ret = 0;
			}
			else
			{
				/*title bar*/
				setfillstyle(1, RED);
				bar(x1 + 10, y2 - 35, x2 - 10, y2 - 10);
				/*title text*/
				settextstyle(1, 0, 1);
				setcolor(WHITE);
				outtextxy(x1 + 70, y2 - 35, "PASSWORD INCORRECT");
				sound(100);
				delay(400);
				nosound();
				delay(400);
				ret = -1;
			}

		}
	} while (ret == -1);
	return 0;
}

