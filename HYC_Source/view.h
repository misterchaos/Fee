#define _CRT_SECURE_NO_DEPRECATE

#ifndef __VIEW_H__
#define __VIEW_H__

#define CLOSE_DOS_FILL 11

#include<stdio.h>
#include"search.h"
#include"list.h"
#include"main.h"
#include<graphics.h>
#include<bios.h>
#include<conio.h>

int Output_Window();
int Input_Window();
int DrawMenu(int _getchoice, char _text[10][50], char*_title, int _origin_point, int _bar_number);
int Draw_MessageWindow(char _warning[4][30]);
int PrintRecord_Window();
int Refresh_DrawMenu(int _getchoice, char _text[10][50], char*_title, int _origin_point, int _bar_number);
int Return_Window();
int PrintUser_Window();
int Start_Window();

/*background color*/
extern int bkcolor;

#endif 