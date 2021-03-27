#ifndef SORTING_H
#define SORTING_H
#include <thread>

class SortingAlgorithms
{
private:
	void inline Swap(int& num1, int& num2);
	int MinIndex(int* pList, int startIndex, int endIndex, long long& nComparisons);
	void BubbleUp(int* pList, int nStartIndex, int nEndIndex, long long& nComparisons);
	void AdaptiveBubbleUp(int* pList, int nStartIndex, int nEndIndex, bool& sorted, long long& nComparisons);
	void InsertItem(int* pList, int nStartIndex, int nEndIndex, long long& nComparisons);
	void Merge(int* pList, int nLeftFirst, int nLeftLast, int nRightFirst, int nRightLast, int* pTempArray, long long& nComparisons);
	void ReheapDown(int* pList, int nRoot, int nLastIndex, long long& nComparisons);

public:
	SortingAlgorithms();
	void SelectionSort(int* pList, int nListLength, long long& nComparisons);
	void BubbleSort(int* pList, int nListLength, long long& nComparisons);
	void AdaptiveBubbleSort(int* pList, int nListLength, long long& nComparisons);
	void InsertionSort(int* pList, int nListLength, long long& nComparisons);
	void MergeSort(int* pList, int nFirst, int nLast, int* pTempArray, long long& nComparisons);
	void HeapSort(int* pList, int nListLength, long long& nComparisons);
};

#endif SORTING_H