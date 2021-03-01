#include "Test.h"
#include "LC4_MedianofTwoAortedArrays.h"
using std::cout;
using std::endl;

void Test::printvectorint(const std::vector<int>& nums)
{
	for (const auto& num : nums)
	{
		cout << num << ", ";
	}
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

void Test::TestLC3_LSWRC()
{
	string s = "tmmzuxt";
	int n = LC3_LSWRC().lengthOfLongestSubstringASCII(s);
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
		cout << "Median: " << LC4_MedianofTwoAortedArrays().findMedianSortedArrays(nums1, nums2) << endl << endl;
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

	nums1 = {2};
	nums2 = {};
	testfun(nums1, nums2);
}
