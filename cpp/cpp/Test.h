#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <memory>
#include "LCS.h"
#include "MyQsort.h"
#include <ctime>
#include <math.h>
#include "LC1_TwoSum.h"
#include "LC3_LSWRC.h"
#include "MyBinarySearchTree.h"
#include <chrono>
#define _USE_MATH_DEFINES
namespace Test
{
	template <class T>
	void measure(T&& fun)
	{
		auto starttime = std::chrono::steady_clock::now();
		fun();
		std::chrono::duration<double> diff = std::chrono::steady_clock::now() - starttime;
		std::cout << "Elapsed: " << diff.count() * 1000.0 << " ms. " << std::endl;
	}

	void printvectorint(const std::vector<int>&);

	void TestLCS(const LCS::clist&, const LCS::clist&);
	void AutoTestLCS();

	void MyQsortTest();

	void TestLC3_LSWRC();

	void test_MyBinarySearchTree();

	void test_LC4();
};

