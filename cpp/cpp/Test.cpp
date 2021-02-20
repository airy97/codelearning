#include "Test.h"
#include <iostream>
using std::cout;
using std::endl;

Test::Test(int i) 
{
	_t = i;
	cout << "Create Test " << _t << " !" << endl;
}

Test::Test(const Test& t)
{
	_t = t._t;
	cout << "Copy Create Test " << _t << " !" << endl;
}

Test::Test(const Test&& t)
{
	_t = t._t;
	cout << "Move Copy Create Test " << _t << " !" << endl;
}

Test::Test(double d /*= 0*/)
{
	int i = round(d);
	_t = i;
	cout << "Create Test " << _t << " !" << endl;
}

Test::~Test()
{
	cout << "Destory Test" << _t << " !" << endl;
}

Test& Test::operator=(const Test& t)
{
	_t = t._t;
	cout << "= Test " << _t << " !" << endl;
	return *this;
}

Test& Test::operator=(const Test&& t)
{
	_t = t._t;
	cout << "Move= Test " << _t << " !" << endl;
	return *this;
}

void Test::print()
{
	cout << "Test: " << _t << endl;
}

void Test::add(int i /*= 1*/)
{
	_t += i;
}
