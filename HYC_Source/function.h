#define _CRT_SECURE_NO_DEPRECATE

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include<stdio.h>                 
#include<stdlib.h>              
#include<string.h>              
#include"list.h"
#include"config.h"
#include"login.h"
#include"menu.h"
#include"controler.h"
#include"print.h"
#include"search.h"
#include"sort.h"
#include"view.h"
#include"file.h"

int Start_Function();
int Search_Function(int _getchoice);
int Sort_Function(int _getchoice);
int Count_Function(int _getchoice);
int Input_Function(int _getchoice);
int Modify_Function(int _getchoice);
int Save_Function(int _getchoice);
int Setting_Function(int _getchoice);
int Quit_Function(int _getchoice);



#endif