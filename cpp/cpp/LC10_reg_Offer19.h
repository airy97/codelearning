#pragma once
#include <string>
#include <vector>
using std::vector;
using std::string;
class LC10_reg_Offer19
{
public:
	//正则表达式匹配
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		vector<vector<bool>> res(m + 1, vector<bool>(n + 1, false));
		res[0][0] = true;
		for (int i = 1; i < m + 1; ++i)
		{
			for (int j = 1; j < n + 1; ++j)
			{
				if (res[i][j - 1])
				{
					if (p[j - 1] == '*')
						res[i][j] = true;
				}
				else
				{
					if (s[i - 1] == p[j - 1])
					{
					}
				}
			}
		}
		return res[m][n];

	}
};