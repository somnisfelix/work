#include <array>
#include <vector>
#include "Sort.h"

CSort::CSort()
{
}


CSort::~CSort()
{
}

void CSort::BurbbleSort(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		for (int j = 1; j < vec.size() - i; j++)
		{
			if (vec[j - 1] > vec[j])
			{
				swap(vec[j], vec[j - 1]);
			}
		}
	}
}

void CSort::SelectionSort(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int tmp = i;
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[tmp] > vec[j])
			{
				tmp = j;
			}
		}
		swap(vec[i], vec[tmp]);
	}
}

void CSort::InsertionSort(vector<int>& vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		int tmp = i;
		for (int j = i - 1; j >= 0; j--)
		{
			if (vec[j] > vec[tmp])
			{
				swap(vec[j], vec[tmp]);
				tmp = j;
			}
		}
	}
}

void CSort::Merge(vector<int>& vec, int start, int mid, int end)
{
	vector<int> ret;
	int left = start;
	int right = mid + 1;
	while (left <= mid && right <= end)
	{
		if (vec[left] < vec[right])
		{
			ret.push_back(vec[left++]);
		}
		else {
			ret.push_back(vec[right++]);
		}
	}
	for (int i = left; i <= mid; i++)
	{
		ret.push_back(vec[i]);
	}
	for (int i = right; i <= end; i++)
	{
		ret.push_back(vec[i]);
	}

	int j = 0;
	for (int i = start; i <= end; i++)
	{
		vec[i] = ret[j++];
	}
}

void CSort::MergeSort(vector<int>& vec, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(vec, start, mid);
		MergeSort(vec, mid + 1, end);
		Merge(vec, start, mid, end);
	}
}

void CSort::MergeSort(vector<int>& vec)
{
	MergeSort(vec, 0, vec.size() - 1);
}

void CSort::QuickSort(vector<int>& vec, int start, int end)
{	
	int pivot = start + ((end - start) / 2);
	int left = start;
	int right = end;
	while (pivot > left || pivot < right)
	{
		for (; left < pivot; left++)
		{
			if (vec[pivot] < vec[left])
				break;
		}

		for (; right > pivot; right--)
		{
			if (vec[pivot] > vec[right])
				break;
		}
		if (pivot == left) pivot = right;
		else if (pivot == right) pivot = left;
		swap(vec[right], vec[left]);
	}
	if( pivot > start )
		QuickSort(vec, start, pivot - 1);
	if( pivot < end )
		QuickSort(vec, pivot + 1, end);
	
}

void CSort::QuickSort2(vector<int>& vec, int start, int end)
{
	int pivotNum = vec[start];
	int left = start;
	int right = end;
	while (right > left)
	{	
		for (; right > left; right--)
		{
			if (pivotNum > vec[right])
				break;
		}
		for (; left < right; left++)
		{
			if (pivotNum < vec[left])
				break;
		}

		swap(vec[left], vec[right]);
	}

	swap(vec[left], vec[start]);

	if (left > start)
		QuickSort2(vec, start, left - 1);
	if (left < end)
		QuickSort2(vec, left + 1, end);
}

void CSort::QuickSort(vector<int>& vec)
{
	QuickSort2(vec, 0, vec.size() - 1);
}

void CSort::Main()
{
	vector<int> vecInt;
	for (int i = 0; i < 11; i++)
	{
		vecInt.push_back(i);
	}
	random_shuffle(vecInt.begin(), vecInt.end());
	BurbbleSort(vecInt);
	random_shuffle(vecInt.begin(), vecInt.end());
	SelectionSort(vecInt);
	random_shuffle(vecInt.begin(), vecInt.end());
	InsertionSort(vecInt);
	random_shuffle(vecInt.begin(), vecInt.end());
	MergeSort(vecInt);

	vecInt.clear();
	vecInt.push_back(2);
	vecInt.push_back(1);
	vecInt.push_back(6);
	vecInt.push_back(9);
	vecInt.push_back(10);
	vecInt.push_back(7);
	vecInt.push_back(3);
	vecInt.push_back(8);
	vecInt.push_back(4);
	vecInt.push_back(5);
	vecInt.push_back(0);
	QuickSort(vecInt);

	for (int i = 0; i < 10; i++)
	{
		random_shuffle(vecInt.begin(), vecInt.end());
		QuickSort(vecInt);
	}
}