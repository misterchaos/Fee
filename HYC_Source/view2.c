#include"view.h"
int bkcolor = DARKGRAY;

//to display on output window
int Output_Window()
{
	setbkcolor(DARKGRAY);
	setviewport(0, 0, 639, 319, 1);
	cleardevice();

	window(1, 1, 80, 19);
	textcolor(0);
	textbackground(0);
	clrscr();
	setcolor(WHITE);
	rectangle(3, 322, 636, 476);

	return 0;
}

//to input on input window
int Input_Window()
{
	textcolor(0);
	window(1, 20, 80, 25);
	clrscr();
	setcolor(WHITE);
	rectangle(3, 322, 636, 476);
	return 0;
}


//to display record in a chart
int PrintRecord_Window()
{
	int i = 0;

	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, 3);

	line(44, 0, 44, 479);
	line(116, 0,116, 479);
	line(188, 0,188, 479);
	line(296, 0, 296, 479);
	line(400, 0, 400, 479);
	line(460, 0, 460, 479);
	line(0, 22, 639, 22);
	setlinestyle(SOLID_LINE, 0, 1);
	for (i = 3; i <30 ; i++)
	{
		line(0, 16 * i, 639, 16 * i);
	}
	return 0;
}

//to display user in a chart
int PrintUser_Window()
{
	int i = 0;

	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, 3);
	line(160, 0, 160, 479);
	line(320, 0, 320, 479);
	line(480, 0, 480, 479);

	line(0, 22, 639, 22);
	setlinestyle(SOLID_LINE, 0, 1);
	for (i = 3; i < 30; i++)
	{
		line(0, 16 * i, 639, 16 * i);
	}

	return 0;
}

//to display welcome window
int Start_Window()
{
	setbkcolor(DARKGRAY);
	setviewport(0, 0, 639, 479, 1);
	cleardevice();

	setcolor(15);
	settextstyle(1, 0, 6);
	outtextxy(180, 15,"WELCOME");
	settextstyle(3, 0, 1);
	setcolor(15);
	outtextxy(20, 80, "Program Name  : Consumption Management System of Pay-card");
	outtextxy(20, 110, "Version         : FEE.GUI.2.0.beta");
	outtextxy(20, 140, "Update          : 1.New :Graphic User Interface Applied ");
	outtextxy(20, 170, "                  2.New :Theme Modify ");
	outtextxy(20, 200, "                  3.Optimization  : Animation Effect");
	outtextxy(20, 230, "                  4.Fix :Fail to Delete Record");
	outtextxy(20, 260, "Environment    : Windows 7-Windows 10");
	outtextxy(20, 290, "Language       : English");
	outtextxy(20, 320, "Developer       : Huang Yuchao");
	outtextxy(20, 350, "Release         : 2019.02.19  China");
	outtextxy(20, 380, "Contact info    : 19927457590");
	outtextxy(20, 410, "Email           : kobe524348@gmail.com");
	outtextxy(20, 450, "Copyright(c) 2019-2022 by Huang Yuchao.All Right Reserved");

	getch();
	return 0;
}

//to draw menu window
int DrawMenu(int _getchoice, char _text[10][50], char*_title, int _origin_point, int _bar_number)
{

	/*style setting*/
	extern int bkcolor;//the background color
	int barcolor = LIGHTGRAY;//the list bar color
	int fill_style1 = SOLID_FILL, fill_style2 = CLOSE_DOS_FILL;

	/*the tile text position*/
	int titlex = 180, titley = 10;
	/*length setting*/
	int multi = 15, gap = 12, width = 35, length = 500, expand = 5;
	/*set bar length*/
	int x1, y1, x2, y2, i;
	y1 = _origin_point, y2 = y1 + width, x1 = (640 - length) / 2, x2 = 640 - x1 * 2;
	/*set bar style*/
	setviewport(0, 0, 639, 479,1);
	setfillstyle(fill_style1, barcolor);
	setbkcolor(bkcolor);
	settextstyle(3, 0, 2);
	cleardevice();

	/*start drawing surface*/
	for (i = 1; i <= _bar_number; i++)
	{
		/*draw a bar*/
		setfillstyle(fill_style2, barcolor);
		bar(x1 + 10, y1 + 10, x2 + 10, y2 + 10);
		/*draw a bar*/
		setfillstyle(fill_style1, barcolor);
		bar(x1, y1, x2, y2);
		/*menu text*/
		setcolor(DARKGRAY);
		outtextxy(x1 + 20, y1 + 5, &_text[i - 1]);
		y1 += (gap + width), y2 += (gap + width);
	}
	
	/*title*/
	setcolor(15); 
	settextstyle(1, 0, 7);
	outtextxy(titlex, titley, _title);
	return 0;
}

//to refresh menu window
int Refresh_DrawMenu(int _getchoice, char _text[10][50], char*_title, int _origin_point, int _bar_number)
{
	/* default style setting*/
	extern int bkcolor;//the background color
	int barcolor = LIGHTGRAY;//the list bar color
	int fill_style1 = SOLID_FILL, fill_style2 = CLOSE_DOS_FILL;

	/*the tile text position*/
	int titlex = 180, titley = 10;
	/*length setting*/
	int multi = 15, gap = 12, width = 35, length = 500, expand = 5;
	/*set bar length*/
	int x1, y1, x2, y2, i;
	y1 = _origin_point, y2 = y1 + width, x1 = (640 - length) / 2, x2 = 640 - x1 * 2;
	/*set bar style*/
	setviewport(0, 0, 639, 479, 1);
	setfillstyle(fill_style1, barcolor);
	setbkcolor(bkcolor);
	settextstyle(3, 0, 2);

	/*start drawing surface*/
	for (i = 1; i <= _bar_number; i++)
	{
		if (i == _getchoice - 1 || i == _getchoice + 1)
		{
			/*overwrite*/
			setfillstyle(fill_style1, bkcolor);
			bar(x1 + expand * multi, y1 - (expand + 2), x2 + expand * multi, y2 + expand);

			/*draw below bar*/
			setfillstyle(fill_style2, barcolor);
			bar(x1 + 10, y1 + 10, x2 + 10, y2 + 10);
			/*draw over bar*/
			setfillstyle(fill_style1, barcolor);
			bar(x1, y1, x2, y2);
			/*menu text*/
			setcolor(DARKGRAY);
			outtextxy(x1 + 20, y1 + 5, &_text[i - 1]);
		}
		else
		{
			if (i == _getchoice)
			{
				/*overwrite*/
				setfillstyle(fill_style1, bkcolor);
				bar(x1, y1, x2 + 10, y2 + 10);

				x1 += expand * multi, y1 -= (expand + 2), x2 += expand * multi, y2 += expand;
				/*draw a bar*/
				setfillstyle(fill_style1, bkcolor);//DRAKGRAY
				bar(x1 + 10, y1 + 10, x2 + 10, y2 + 10);
				/*draw a bar*/
				setfillstyle(fill_style2, barcolor);
				bar(x1, y1, x2, y2);
				/*draw a rectangle*/
				setlinestyle(SOLID_LINE, 0, 1);
				setcolor(WHITE);
				rectangle(x1 + 3, y1 + 3, x2 - 3, y2 - 3);
				rectangle(x1 + 5, y1 + 5, x2 - 5, y2 - 5);
				/*out text*/
				outtextxy(x1 + 20, y1 + 5, &_text[i - 1]);
				x1 -= expand * multi, y1 += expand, x2 -= expand * multi, y2 -= expand;
			}
		}
		y1 += (gap + width), y2 += (gap + width);
	}
	return 0;
}

// to display a pot_up message window
int Draw_MessageWindow(char _warning[4][30])
{

	int x1, y1, x2, y2;
	int origin_point = 100;
	int width = 240;
	int length = 320;

	setviewport(0, 0, 639, 479, 1);

	y1 = (480 - width) / 2, y2 = y1 + width, x1 = (640 - length) / 2, x2 = 640 - x1;

	/*back ground*/
	setfillstyle(11, DARKGRAY);
	bar(x1 + 20, y1 + 20, x2 + 20, y2 + 20);

	setfillstyle(1, LIGHTGRAY);
	bar(x1, y1, x2, y2);

	setfillstyle(1, BLUE);
	bar(x1 + 10, y2 - 35, x2 - 10, y2 - 10);

	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(WHITE);
	rectangle(x1 + 3, y1 + 3, x2 - 3, y2 - 3);
	rectangle(x1 + 5, y1 + 5, x2 - 5, y2 - 5);

	/*text */
	settextstyle(1, 0, 1);
	setcolor(WHITE);
	outtextxy(x1 + 120, y2 - 35,_warning[3]);
	outtextxy(x1 + 40, y1 + 170,_warning[2]);
	setcolor(DARKGRAY);
	outtextxy(x1 + 20, y1 + 50, _warning[0]);
	outtextxy(x1 + 20, y1 + 100, _warning[1]);
	setcolor(WHITE);

	sound(500);
	delay(50);
	nosound();
	return 0;
}

//to display a window to ask if he want to go back
int Return_Window()
{
	char text[4][30] = { {"Do you want to go back?"},{"press [enter]or[ESC]to comfirm"} ,{"press any other key to cancel"} ,{"Warnings"} };
	Draw_MessageWindow(text);
	sound(400);
	delay(50);
	nosound();
	if (bioskey(0) == ENTER || bioskey(0) == ESC)
		return -1;
	else
		return 0;
}

