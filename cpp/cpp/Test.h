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
#define _USE_MATH_DEFINES
namespace Test
{
	void TestLCS(const LCS::clist&, const LCS::clist&);
	void AutoTestLCS();

	void MyQsortTest();

	void TestLC3_LSWRC();

	void test_MyBinarySearchTree();
};

