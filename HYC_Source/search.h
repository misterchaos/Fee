#define _CRT_SECURE_NO_DEPRECATE

#ifndef __SEARCH_H__
#define __SEARCH_H__

#include<stdio.h>
#include"print.h"
#include"list.h"
#include"config.h"
#include"main.h"

/*the node statement of a poniter list */
typedef struct PListNode
{
	Record* pointer;/*point to a record pointer*/
	struct PListNode* next;
}PListNode;

/*to search an account*/
User* Search_Account(const User_List _list, const char* _login_name);

/*to search records*/
Record*Search_RecordByID(Record_List _list, int _id);
PListNode* Search_ByDate(Record_List _list, long int _begin,long int _end);
PListNode* Search_ByAmount(Record_List _list, float _min, float _max);
PListNode* Search_ByDealType(Record_List _list, int _deal_type);

/*output result*/
int Print_RecordBySearch(PListNode* _list);
float Count_BySearch(PListNode* _list);


#endif 
