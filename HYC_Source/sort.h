#ifndef __SORT_H__
#define __SORT_H__

#define YEAR 10000
#define MONTH 100
#define TERM 500

#include"list.h"
#include"main.h"

Record_List* Sort_ByDate(Record_List* _list);
Record_List* Sort_ByID(Record_List* _list);
Record_List* Sort_ByAmount(Record_List* _list);
Record_List Sort_ByInterval(Record_List* _list, long int _interval);


int SwapNode(Record*_p1, Record*_p2);

#endif 

