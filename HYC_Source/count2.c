#include"count.h"

float Count_Amount(Record_List _list)
{
	Record*p;
	float cnt = 0;/*add to this*/

	if (_list.head == NULL || _list.tail == NULL || _list.head->next == NULL)
	{
		return 0;
	}

	for (p = _list.head->next; p != _list.tail->next&&p != NULL; p = p->next)
	{
		cnt += p->deal_amount;
	}
	return cnt;
}

