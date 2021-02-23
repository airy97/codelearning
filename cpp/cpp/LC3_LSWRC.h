#pragma once
#include <string>
#include <vector>
#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_set;
//无重复字符的最长字串
class LC3_LSWRC {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		if (n <= 1)
			return n;
		int left = 0;
		int right = 1;
		int max = 1;
		unordered_set<char> hashtable{ s[0] };
		while (right < n)
		{
			if (!hashtable.count(s[right]))
			{
				hashtable.insert(s[right]);
				++right;
				if ((right - left) > max)
				{
					max = right - left;
				}
			}
			else
			{
				hashtable.erase(s[left]);
				++left;
			}
		}
		return max;
	}

	//考虑到ASCII只有127个，可直接搭建hash表
	int lengthOfLongestSubstringASCII(string s) {
		vector<int> charrope(127, -1);
		int left = -1;
		int maxlength = 0;
		for (int right = 0; right < s.size(); ++right)
		{
			if (charrope[s[right]] > left)
			{
				left = charrope[s[right]];
				charrope[s[right]] = right;
			}
			else
			{
				charrope[s[right]] = right;
				maxlength = (right - left) > maxlength ? (right - left) : maxlength;
			}
		}
		return maxlength;
	}
};