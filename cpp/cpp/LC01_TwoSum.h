#pragma once
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
class LC01_TwoSum
{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i)
		{
			unordered_map<int, int>::iterator finder = hashtable.find(target - nums[i]);
			if (finder != hashtable.end())
			{
				return { finder->second, i };
			}
			else
			{
				hashtable[nums[i]] = i;
			}
		}
		return {};
	}
};

