#pragma once
#include <vector>
using std::pair;
using std::vector;
//最长公共子序列
class LCS
{
public:
	typedef vector<char> clist;
	LCS(const clist& list1 = clist(), const clist& list2 = clist());
	~LCS();
	int getlongestlength();
	clist getlongestclist();

private:
	pair<int, int> General(clist list1, clist list2, size_t size1, size_t size2);
	clist m_list1;
	clist m_list2;
	vector<vector<int>> m_longestlist;
	vector<vector<int>> m_list1endlist;
};

