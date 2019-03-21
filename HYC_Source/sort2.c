#include"sort.h"

/*sort a list from earlieast date to the latest one*/
Record_List* Sort_ByDate(Record_List* _list)
{
//	int i;

	/*p to find ,pMin point to the min one*/
	Record*p=NULL, *pMin=NULL,*temp=NULL;


	if (_list->head == NULL)
	{
		return NULL;
	}

	/*use chose sort method to sort */
	for ( pMin=_list->head->next;pMin!=NULL&&pMin!=_list->tail; pMin=pMin->next)
	{
		/*the head node is not include*/
		for (temp=p=pMin;p!=NULL && p!=_list->tail->next;p=p->next)
		{
			/*if this record is earlier*/
			if (p->deal_date < pMin->deal_date&&p->deal_date<temp->deal_date)
			{
				/*temporary save the pointer*/
				temp = p;
			}
		}
		/*if find a new earlier record*/
		if (temp != pMin)
		{
			//printf("swap one\n");
			if (temp==_list->tail)
			{
				_list->tail = pMin;
				if (temp->next == NULL)
				{
					all_record.tail = pMin;
				}
			}
			if (pMin == _list->head->next)
			{
				_list->head->next = temp;
			}
			/*swap node*/
			SwapNode(pMin, temp);
	
			/*redirect*/
			pMin = temp;
		}
	}
	return _list;
}

/*sort a list from earlieast date to the latest one*/
Record_List* Sort_ByID(Record_List* _list)
{
	/*p to find ,pMin point to the min one*/
	Record*p = NULL, *pMin = NULL, *temp = NULL;

	if (_list->head == NULL)
	{
		return NULL;
	}

	/*use chose sort method to sort */
	for (pMin = _list->head->next; pMin != NULL && pMin != _list->tail; pMin = pMin->next)
	{
		/*the head node is not include*/
		for (temp = p = pMin; p != NULL && p != _list->tail->next; p = p->next)
		{
			/*if this record is earlier*/
			if (p->id < pMin->id&&p->id<temp->id)
			{
				/*temporary save the pointer*/
				temp = p;
			}
		}
		/*if find a new earlier record*/
		if (temp != pMin)
		{
			//printf("swap one\n");
			if (temp == _list->tail)
			{
				_list->tail = pMin;
				if (temp->next == NULL)
				{
					all_record.tail = pMin;
				}
			}
			if (pMin == _list->head->next)
			{
				//printf("put head\n");
				_list->head->next = temp;
			}
			/*swap node*/
			SwapNode(pMin, temp);

			/*redirect*/
			pMin = temp;
		}
	}
	return _list;
}



/*sort a list from earlieast date to the latest one*/
Record_List* Sort_ByAmount(Record_List* _list)
{
	/*p to find ,pMin point to the min one*/
	Record*p = NULL, *pMin = NULL, *temp = NULL;


	if (_list->head == NULL)
	{
		return NULL;
	}

	/*use chose sort method to sort */
	for (pMin = _list->head->next; pMin != NULL && pMin != _list->tail; pMin = pMin->next)
	{
		/*the head node is not include*/
		for (temp = p = pMin; p != NULL && p != _list->tail->next; p = p->next)
		{
			/*if this record is earlier*/
			if (p->deal_amount < pMin->deal_amount&&p->deal_amount<temp->deal_amount)
			{
				/*temporary save the pointer*/
				temp = p;
			}
		}
			
		/*if find a new earlier record*/
		if (temp != pMin)
		{
		/*	printf("swap one\n");*/
			if (temp == _list->tail)
			{
				_list->tail = pMin;
				if (temp->next == NULL)
				{
					all_record.tail = pMin;
				}
			}
			if (pMin == _list->head->next)
			{
				//printf("put head\n");
				_list->head->next = temp;
			}
			/*swap node*/
			SwapNode(pMin, temp);

			/*redirect*/
			pMin = temp;
		}
	}
	return _list;
}

Record_List Sort_ByInterval(Record_List* _list, long int _interval)
{
	long int current = 20300101;
	long int from_date = 19700101;
	float cnt;
	long int to_date = (from_date + _interval);
	PListNode* temp1 = NULL;
	Record * temp2 = NULL, *temp3 = NULL;

	if (_list->head == NULL || _list->head->next == NULL)
	{
		getch();
		return interval_record;
	}

	for (temp3 = interval_record.head->next = NULL, interval_record.node_number = 1; to_date <= current; from_date += _interval, cnt = 0)
	{
		to_date = (from_date + _interval);
		temp1 = Search_ByDate(*_list, from_date - 1, to_date - 1);
		if (temp1 != NULL)
		{
			cnt = Count_BySearch(temp1);
			temp2 = Create_EmptyRecordNode();
			temp2->deal_amount = cnt;
			if (_interval == TERM)
			{
				temp2->deal_date = from_date / 100;
				temp2->account_date = from_date / 100;
			}
			else
			{
				temp2->deal_date = from_date / _interval;
				temp2->account_date = from_date / _interval;
			}

			interval_record.node_number++;

			if (interval_record.head->next == NULL)
			{
				temp3 = interval_record.head->next = temp2;
			}
			else
			{
				temp3->next = temp2;
				temp3 = temp2;
			}
		}
	}
	if (temp3 != NULL)
	{
		temp3->next = NULL;
		interval_record.tail = temp3;
	}
	return interval_record;
}

int SwapNode(Record*_p1, Record*_p2)
{

	Record*temp1,*temp2,*temp3,*temp4;
	/*protect*/
	if (_p1 == NULL || _p2 == NULL)
	{
		return -1;
	}

	/*if node 1 next to node 2*/
	if (_p1->next == _p2||_p2->next==_p1)
	{
		//printf("case 1");
		temp1 = _p1->pre;
		temp2 = _p2->next;
		
		/*swap the next*/
		temp1->next = _p2;
		_p2->next = _p1;
		_p1->next = temp2;

		/*swap the pre*/
		if (temp2 != NULL)
		{
			temp2->pre = _p1;
		}
		_p1->pre = _p2;
		_p2->pre = temp1;
	}

	/*if node p1 is not next to p2*/
	else
	{
		//printf("case 2");
		temp1 = _p1->pre;
		temp2 = _p1->next;
		temp3 = _p2->pre;
		temp4 = _p2->next;

		/*swap the next*/
		temp1->next = _p2;
		_p2->next =temp2;
		temp3->next = _p1;
		_p1->next = temp4;
		/*swap the pre*/
		if (temp4 != NULL)
		{
			temp4->pre = _p1;
		}
		_p1->pre = temp3;
		temp2->pre = _p2;
		_p2->pre = temp1;
	}
	return 0;
}

