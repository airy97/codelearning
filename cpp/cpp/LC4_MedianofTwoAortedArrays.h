#pragma once
#include <vector>
#include <math.h>
#include<algorithm>
#include <stdlib.h>
#include <iostream>
#define min(a,b) (((a) < (b)) ? (a) : (b))
using std::vector;
class LC4_MedianofTwoAortedArrays {
	//O(log(m+n))
public:
	static int findKthNum(const vector<int>& nums1, const vector<int>& nums2, int k)
	{
		if (nums1.empty())
		{
			return nums2[k - 1];
		}
		if (nums2.empty())
		{
			return nums1[k - 1];
		}

		int m = nums1.size();
		int n = nums2.size();
		int index1 = 0;
		int index2 = 0;
		while (true)
		{
			if (k == 1)
			{
				return min(nums1[index1], nums2[index2]);
			}
			int newindex1 = min(m - 1, index1 + k / 2 - 1);
			int newindex2 = min(n - 1, index2 + k / 2 - 1);
			if (nums1[newindex1] < nums2[newindex2])
			{
				k -= newindex1 - index1 + 1;
				index1 = newindex1 + 1;
				if (index1 == m)
				{
					return nums2[index2 + k - 1];
				}
			}
			else
			{
				k -= newindex2 - index2 + 1;
				index2 = newindex2 + 1;
				if (index2 == n)
				{
					return nums1[index1 + k - 1];
				}
			}
		}
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int totallength = nums1.size() + nums2.size();
		if ((totallength % 2) == 1)
		{
			return findKthNum(nums1, nums2, (totallength + 1) / 2);
		}
		else
		{
			return (findKthNum(nums1, nums2, totallength / 2) + findKthNum(nums1, nums2, totallength / 2 + 1)) * 0.5;
		}
	}
};