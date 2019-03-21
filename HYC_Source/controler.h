#define _CRT_SECURE_NO_DEPRECATE

#ifndef __CONTROLER_H__
#define __CONTROLER_H__

#include<stdio.h>
#include<stdlib.h>
#include"search.h"
#include"list.h"
#include"file.h"
#include"view.h"
#include"print.h"
#include"main.h"
#include"function.h"

#define UP			0x4800
#define DOWN		0x5000
#define ENTER       0x1c0d
#define ESC			0x011b

#define SEARCH		1
#define SORT		2
#define COUNT		3
#define INPUT		4
#define MODIFY		5
#define SAVE		6
#define SETTING		7
#define QUIT 		8

int MessageListener(char _text[10][50], char*_title, int _origin_point, int _bar_number);
int SubMenu(int _getchoice);
int Start_Activity();
int Main_Activity();
int Search_Activity();
int Sort_Activity();
int Count_Activity();
int Input_Activity();
int Modify_Activity();
int Save_Activity();
int Setting_Activity();
int Quit_Activity();

#endif 
