#pragma once
#include <vector>
using std::vector;
class MyQuickSort
{
public:
	void operator()(vector<int>& numbers, int left, int right)
	{
		if (right - left <= 1)
			return;

		int i = left;
		int mid = left + (right - left) / 2;
		int j = right;

		if (numbers[left] > numbers[right - 1])
			std::swap(numbers[left], numbers[right - 1]);
		if (numbers[mid] > numbers[right - 1])
			std::swap(numbers[mid], numbers[right - 1]);
		if (numbers[mid] > numbers[left])
			std::swap(numbers[mid], numbers[left]);

		int index = left;
		int provit = numbers[left];
		while (j - 1 > i)
		{
			while (i < (j - 1) && numbers[j - 1] > provit)
			{
				--j;
			}
			while (i < (j - 1) && numbers[i + 1] <= provit)
			{
				++i;
			}
			if (j - i > 1)
			{
				std::swap(numbers[i + 1], numbers[j - 1]);
			}
			std::swap(numbers[index], numbers[i]);
			index = i;
		}

		MyQuickSort()(numbers, left, index);
		MyQuickSort()(numbers, index + 1, right);
	}

	void operator()(vector<int>& numbers)
	{
		MyQuickSort()(numbers, 0, numbers.size());
	}
};

