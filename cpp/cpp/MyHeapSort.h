#pragma once
#pragma once
#include <vector>
using std::vector;
class MyHeapSort
{
public:
	void makeMaxHeap(vector<int>& numbers)
	{
		int n = numbers.size();
		for (int i = n - 1; i >= 0; --i)
		{
			makeMaxHeapOnce(numbers, i, n);
		}
	}

	void makeMaxHeapOnce(vector<int>& numbers, int i, int size)
	{
		int leftclid = left(i);
		if (leftclid >= size)
		{
			return;
		}
		else if (leftclid == size - 1)
		{
			if (numbers[i] < numbers[leftclid])
			{
				std::swap(numbers[i], numbers[leftclid]);
			}
		}
		else
		{
			int maxclid = numbers[leftclid] > numbers[leftclid + 1] ? leftclid : leftclid + 1;
			if (numbers[i] < numbers[maxclid])
			{
				std::swap(numbers[i], numbers[maxclid]);
				makeMaxHeapOnce(numbers, maxclid, size);
			}
		}
	}

	int left(int i)
	{
		return 2 * i + 1;
	}

	int right(int i)
	{
		return left(i) + 1;
	}

	void operator()(vector<int>& numbers, int left, int right)
	{
		makeMaxHeap(numbers);
		for (int i = numbers.size() - 1; i > 0; --i)
		{
			std::swap(numbers[i], numbers[0]);
			makeMaxHeapOnce(numbers, 0, i);
		}
	}

	void operator()(vector<int>& numbers)
	{
		MyHeapSort()(numbers, 0, numbers.size());
	}
};