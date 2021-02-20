#pragma once
#include <vector>
using std::vector;
class MyQsort
{
public:
	typedef vector<int> IntList;
	void operator()(IntList&);
	void operator()(IntList&, const int, const int);
};

