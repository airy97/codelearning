#include "MyQsort.h"
#include <iostream>

void MyQsort::operator()(IntList& list)
{
	if (list.size() <= 1)
	{
		return;
	}
	else
	{
		(*this)(list, 0, list.size() - 1);
	}
}

void MyQsort::operator()(IntList& list, const int begin, const int end)
{
	if ((end - begin) <= 0)
	{
		return;
	}
	int k = end - begin;
	for (int i = 0; i < k;)
	{
		if (list[(begin + i)] >= list[(begin + k)])
		{
			IntList::iterator iter = list.begin() + begin + k + 1;
			list.insert(iter, list[(begin + i)]);
			iter = list.begin() + ((begin + i));
			list.erase(iter++);
			--k;
		}
		else
		{
			++i;
		}
	}
	(*this)(list, begin, begin + k - 1);
	(*this)(list, begin + k + 1, end);
}

