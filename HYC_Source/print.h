#define _CRT_SECURE_NO_DEPRECATE

#ifndef __PRINT_H__
#define __PRINT_H__

#include<stdio.h>
#include"list.h"
#include"count.h"
#include"main.h"
#include"search.h"

int Print_Record(Record_List _list);
int Print_User(User_List _list);
int Print_RecordFromTail(Record_List _list);

#endif 

