#include "Test.h"
#include "LC04_MedianofTwoAortedArrays.h"
#include <random>
#include "MyBinTree.h"
#include "LC54_Offer29.h"
#include "LC10_reg_Offer19.h"
#include "LC51_NQueens.h"
using std::cout;
using std::endl;

void Test::printvectorint(const std::vector<int>& nums, const std::string& prefix, const std::string& suffix)
{
	cout << prefix;
	for (const auto& num : nums)
	{
		cout << num << ", ";
	}
	cout << suffix;
}

vector<int> Test::getRandomNumbers(int n)
{
	std::default_random_engine e(time(0));
	std::uniform_int_distribution<int> u(0, 100);
	vector<int> numbers(n);
	for (int i = 0; i < n; ++i)
	{
		numbers[i] = u(e);
	}
	return numbers;
}

void Test::TestLCS(const LCS::clist& list1, const LCS::clist& list2)
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
	LCS::clist res = test.getlongestclist();
	for (auto c : res)
	{
		cout << c << ", ";
	}
	cout << endl << endl;
	++count;
}

void Test::AutoTestLCS()
{
	LCS::clist list1 = { 'a', 'b', 'd', 'e' };
	LCS::clist list2 = { 'a', 'b', 'c', 'd', 'e' };
	LCS::clist list3 = { 'f' };
	LCS::clist list4 = { 'a', 'b', 'd' };
	vector<LCS::clist> vec1 = { list1 };
	vector<LCS::clist> vec2 = { list1, list2, list3, list4 };
	for (auto list_1 : vec1)
	{
		for (auto list_2 : vec2)
		{
			TestLCS(list_1, list_2);
		}
	}
}

void Test::MyQsortTest()
{
	srand((int)time(0));
	vector<int> list;
	for (int i = 0; i < 100; i++)
	{
		list.push_back(rand() % 10000);
	}
	MyQuickSort()(list);
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

void Test::TestLC3_LSWRC()
{
	string s = "tmmzuxt";
	int n = LC03_LSWRC().lengthOfLongestSubstringASCII(s);
	cout << n;
}

void Test::test_MyBinarySearchTree()
{
	MyBinarySearchTree tree({ 2,1,3 });
	tree.printInfo();
	cout << "Test end!";
}

void Test::test_LC4()
{
	auto testfun = [](vector<int>& nums1, vector<int>& nums2)
	{
		static int count = 0;
		cout << "Test " << ++count << ": " << endl;
		cout << "Nums1: ";
		printvectorint(nums1);
		cout << endl;
		cout << "Nums2: ";
		printvectorint(nums2);
		cout << endl;
		cout << "Median: " << LC04_MedianofTwoAortedArrays().findMedianSortedArrays(nums1, nums2) << endl << endl;
	};

	vector<int> nums1 = { 1,3 };
	vector<int> nums2 = { 2 };
	testfun(nums1, nums2);

	nums1 = { 1,2 };
	nums2 = { 3,4 };
	testfun(nums1, nums2);

	nums1 = { 0,0 };
	nums2 = { 0,0 };
	testfun(nums1, nums2);

	nums1 = {};
	nums2 = { 1 };
	testfun(nums1, nums2);

	nums1 = { 2 };
	nums2 = {};
	testfun(nums1, nums2);
}

void Test::test_MyQuickSort()
{
	vector<int> numbers;
	int n = 20;
	for (int i = 0; i < 10; ++i)
	{
		numbers = getRandomNumbers(n);
		printvectorint(numbers, "Numbers: ", "\n");
		MyQuickSort()(numbers);
		printvectorint(numbers, "Sorted Numbers: ", "\n");
		bool res = true;
		for (int j = 0; j < n - 1; ++j)
		{
			if (numbers[j + 1] < numbers[j])
			{
				res = false;
			}
		}
		cout << (res ? "Succeed!\n" : "Fail!\n");
		system("pause");
	}
}

void Test::test_MyHeapSort()
{
	vector<int> numbers;
	int n = 100;
	for (int i = 0; i < 10; ++i)
	{
		numbers = getRandomNumbers(n);
		//printvectorint(numbers, "Numbers: ", "\n");
		MyHeapSort()(numbers);
		//printvectorint(numbers, "Sorted Numbers: ", "\n");
		bool res = true;
		for (int j = 0; j < n - 1; ++j)
		{
			if (numbers[j + 1] < numbers[j])
			{
				res = false;
			}
		}
		cout << (res ? "Succeed!\n" : "Fail!\n");
		system("pause");
	}
}

void Test::test_MyBinTree()
{
	typedef MyBinTree::nodeptr ptr;
	ptr head = MyBinTree::getBinTree({ 1,2,3,4,5,6,7 });
	MyBinTree::postorder_recur(head);
	std::cout << std::endl;
	MyBinTree::postorder_iter(head);
}

void Test::test_LC54_LCOF_OFFER29()
{
	vector<vector<int>> m = { {1, 2, 3, 4} ,{5, 6, 7, 8},{9, 10, 11, 12} };
	vector<int> res = LC54_Offer29().spiralOrder(m);
	printvectorint(res);
}

void Test::test_LC10_reg_Offer19()
{
	auto funtest = [](string str1, string reg)
	{
		cout << str1 << endl;
		cout << reg << endl;
		cout << (LC10_reg_Offer19().isMatch(str1, reg) ? "true" : "false") << endl << endl;
	};


	funtest("aa", "a");
	funtest("aa", "a*");
	funtest("ab", ".*");
	funtest("aab", "c*a*b");
	funtest("mississippi", "mis*is*p*");

}

void Test::test_LC51_NQueens()
{
	auto res = LC51_NQueens().solveNQueens(8);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << (i + 1) << " : \n";
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout << res[i][j] << endl;
		}
		cout << endl;
	}
}
