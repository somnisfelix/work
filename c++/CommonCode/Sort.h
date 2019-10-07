#pragma once

using namespace std;

class CSort
{
public:
	CSort();
	~CSort();
	void Main();

private:
	void BurbbleSort(vector<int>& vec);
	void SelectionSort(vector<int>& vec);
	void InsertionSort(vector<int>& vec);
	void MergeSort(vector<int>& vec, int start, int end);
	void MergeSort(vector<int>& vec);
	void Merge(vector<int>& vec, int start, int end, int mid);
	void QuickSort(vector<int>& vec, int start, int end);
	void QuickSort2(vector<int>& vec, int start, int end);
	void QuickSort(vector<int>& vec);
};

