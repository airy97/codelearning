#pragma once
#include <vector>
using std::vector;
class LC54_Offer29 {
public:
	//顺时针打印数组
	struct pos
	{
		int x;
		int y;
		pos(int xx = 0, int yy = 0) :x(xx), y(yy) {}
	};

	void mprint(vector<vector<int>>& matrix, int m, int n, vector<int>& nums, int layer)
	{
		pos org(layer, layer);
		for (; org.y < n - layer; ++org.y)
		{
			nums.emplace_back(matrix[org.x][org.y]);
		}
		++org.x;
		--org.y;
		if (m <= 2 * layer + 1)
		{
			return;
		}
		for (; org.x < m - layer; ++org.x)
		{
			nums.emplace_back(matrix[org.x][org.y]);
		}
		--org.x;
		--org.y;
		if (n <= 2 * layer + 1)
		{
			return;
		}
		for (; org.y >= layer; --org.y)
		{
			nums.emplace_back(matrix[org.x][org.y]);
		}
		--org.x;
		++org.y;
		for (; org.x > layer; --org.x)
		{
			nums.emplace_back(matrix[org.x][org.y]);
		}
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
		{
			return {};
		}
		vector<int> res;
		int m = matrix.size();
		int n = matrix[0].size();
		int nlayer = (min(m, n) + 1) / 2;
		for (int i = 0; i < nlayer; ++i)
			mprint(matrix, m, n, res, i);
		return res;
	}
};