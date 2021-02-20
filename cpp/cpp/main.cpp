//#include <afxwin.h> 
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#include <memory>
#include "Test.h"
#include "LCS.h"
#include "MyQsort.h"
#include <ctime>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

void TestLCS(const clist&, const clist&);
void AutoTestLCS();
void testtry();
void testcatch();
void MyQsortTest();
Test CreatTest(const Test& tt)
{
	Test t = tt;
	t.add();
	return t;
}


int main()
{
	Test t = 1;
	vector<int>::iterator iter;
	system("pause");
	return 0;
}

void TestLCS(const clist& list1, const clist& list2)
{
	static int count = 1;
	cout << "TestLSP " << count << ": " << endl;
	cout << "List1: ";
	for (auto c : list1)
	{
		cout << c << ", ";
	}
	cout << endl;
	cout << "List2: ";
	for (auto c : list2)
	{
		cout << c << ", ";
	}
	cout << endl;
	LCS test(list1, list2);
	cout << "LSP_length: " << test.getlongestlength() << endl;
	cout << "LSP: ";
	clist res = test.getlongestclist();
	for (auto c : res)
	{
		cout << c << ", ";
	}
	cout << endl << endl;
	++count;
}

void AutoTestLCS()
{
	clist list1 = { 'a', 'b', 'd', 'e' };
	clist list2 = { 'a', 'b', 'c', 'd', 'e' };
	clist list3 = { 'f' };
	clist list4 = { 'a', 'b', 'd' };
	vector<clist> vec1 = { list1 };
	vector<clist> vec2 = { list1, list2, list3, list4 };
	for (auto list_1 : vec1)
	{
		for (auto list_2 : vec2)
		{
			TestLCS(list_1, list_2);
		}
	}
}

void MyQsortTest()
{
	srand((int)time(0));
	vector<int> list;
	for (int i = 0; i < 100; i++)
	{
		list.push_back(rand() % 10000);
	}
	MyQsort()(list);
	int count = 0;
	for (auto i : list)
	{
		cout << i << ", ";
		++count;
		if (count == 10)
		{
			cout << endl;
			count = 0;
		}
	}
}

void testtry()
{
	vector<int> temp;
	if (true)
	{
		throw exception();
	}
	std::cout << "trytest Success!" << endl;
}

void testcatch()
{
	try
	{
		testtry();
	}
	catch (const exception& e)
	{
		std::cout << "Success!" << endl;
	}
	std::cout << "Catchtest Success!" << endl;
}



