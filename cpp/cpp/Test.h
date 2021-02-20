#pragma once
class Test
{
	int _t;
public:
	Test(int i = 0);
	Test(double i = 0);
	~Test();
	Test(const Test& t);
	Test(const Test&& t);
	Test& operator=(const Test& t);
	Test& operator=(const Test&& t);
	void print();
	void add(int i = 1);

};

