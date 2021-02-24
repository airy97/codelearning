#include "LCS.h"

using namespace std;

LCS::LCS(const clist& list1, const clist& list2) :m_list1(list1), m_list2(list2)
{
	m_longestlist = vector<vector<int>>(list1.size() + 1, vector<int>(list2.size() + 1, -1));
	m_list1endlist = vector<vector<int>>(list1.size() + 1, vector<int>(list2.size() + 1, -1));
	for (auto& vec : m_longestlist)
	{
		vec[0] = 0;
	}
	for (auto& x : m_longestlist[0])
	{
		x = 0;
	}
	for (auto& vec : m_list1endlist)
	{
		vec[0] = 0;
	}
	for (auto& x : m_list1endlist[0])
	{
		x = 0;
	}
	General(m_list1, m_list2, m_list1.size(), m_list2.size());
	if (!m_list2.empty())
	{
		for (auto& vec : m_list1endlist)
		{
			for (int i = vec.size() - 1; i > 0; --i)
			{
				if (vec[i] < 0)
				{
					for (int j = i - 1; j >= 0; --j)
					{
						if (vec[j] >= 0)
						{
							vec[i] = vec[j];
							break;
						}
					}
				}
			}
		}
	}
}

LCS::~LCS() {}

pair<int, int> LCS::General(clist list1, clist list2, size_t size1, size_t size2)
{
	if (m_list1endlist[size1][size2] >= 0)
		return make_pair(m_longestlist[size1][size2], m_list1endlist[size1][size2]);
	if (list1.at(size1 - 1) == list2.at(size2 - 1))
	{
		pair<int, int> res = General(list1, list2, size1 - 1, size2 - 1);
		res.first += 1;
		res.second = size1;
		m_longestlist[size1][size2] = res.first;
		m_list1endlist[size1][size2] = res.second;
		return res;
	}
	else
	{
		pair<int, int> res1 = General(list1, list2, size1, size2 - 1);
		pair<int, int> res2 = General(list1, list2, size1 - 1, size2);
		pair<int, int> res = (res1.first >= res2.first) ? res1 : res2;
		m_longestlist[size1][size2] = res.first;
		m_list1endlist[size1][size2] = res.second;
		return res;
	}
}

int LCS::getlongestlength()
{
	return m_longestlist[m_list1.size()][m_list2.size()];
}

LCS::clist LCS::getlongestclist()
{
	vector<int> indexs;
	int index = m_list1endlist[m_list1.size()][m_list2.size()];
	while (index > 0)
	{
		indexs.push_back(index);
		index = m_list1endlist[size_t(index) - 1][m_list2.size()];
	}
	reverse(indexs.begin(), indexs.end());
	clist longestlist;
	for (auto i : indexs)
	{
		longestlist.push_back(m_list1[i - 1]);
	}
	return longestlist;
}
