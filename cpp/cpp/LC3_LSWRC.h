#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_set;
//无重复字符的最长字串
class LC3_LSWRC {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() <= 1)
		{
			return s.size();
		}
		vector<int> lengthtable(s.size(), 1);
		for (int i = 1; i < s.size(); ++i)
		{
			unordered_set<char> hashtable;
			hashtable.insert(s[i]);
			for (int j = i - 1; j >= 0; --j)
			{
				if (hashtable.count(s[j]) == 0)
				{
					hashtable.insert(s[j]);
				}
				else
					break;
			}
			lengthtable[i] = max(lengthtable[i - 1], (int)hashtable.size());
		}
		return lengthtable[s.size() - 1];
	}
};