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
#include "MyQuickSort.h"
#include <ctime>
#include <math.h>
#include "LC01_TwoSum.h"
#include "LC03_LSWRC.h"
#include "MyBinarySearchTree.h"
#include <chrono>
#include "MyQuickSort.h"
#include "MyHeapSort.h"
#define _USE_MATH_DEFINES
namespace Test
{
	//tools
	template <class T>
	void measure(T&& fun)
	{
		auto starttime = std::chrono::steady_clock::now();
		fun();
		std::chrono::duration<double> diff = std::chrono::steady_clock::now() - starttime;
		std::cout << "Elapsed: " << diff.count() * 1000.0 << " ms. " << std::endl;
	}

	void printvectorint(const std::vector<int>&, const std::string& prefix = "", const std::string& suffix = "");
	vector<int> getRandomNumbers(int n);

	//tests
	void TestLCS(const LCS::clist&, const LCS::clist&);
	void AutoTestLCS();

	void MyQsortTest();

	void TestLC3_LSWRC();

	void test_MyBinarySearchTree();

	void test_LC4();

	void test_MyQuickSort();

	void test_MyHeapSort();

	void test_MyBinTree();

	void test_LC54_LCOF_OFFER29();

	void test_LC10_reg_Offer19();

	void test_LC51_NQueens();
};

