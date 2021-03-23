#ifndef SORTING_H
#define SORTING_H

class SortingAlgorithms
{
private:
	void inline Swap(int& num1, int& num2);
	int MinIndex(int* pList, int startIndex, int endIndex, int& nComparisons);
	void BubbleUp(int* pList, int nStartIndex, int nEndIndex, int& nComparisons);
	void AdaptiveBubbleUp(int* pList, int nStartIndex, int nEndIndex, bool& sorted, int& nComparisons);
	void InsertItem(int* pList, int nStartIndex, int nEndIndex, int& nComparisons);
	void Merge(int* pList, int nLeftFirst, int nLeftLast, int nRightFirst, int nRightLast, int* pTempArray, int& nComparisons);

public:
	SortingAlgorithms();
	void SelectionSort(int* pList, int pListLength, int& nComparisons);
	void BubbleSort(int* pList, int pListLength, int& nComparisons);
	void AdaptiveBubbleSort(int* pList, int pListLength, int& nComparisons);
	void InsertionSort(int* pList, int pListLength, int& nComparisons);
	void MergeSort(int* pList, int nFirst, int nLast, int* pTempArray, int& nComparisons);
};

#endif SORTING_H