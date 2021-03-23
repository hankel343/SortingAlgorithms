#ifndef SORTING_H
#define SORTING_H

class SortingAlgorithms
{
private:
	void inline Swap(int& num1, int& num2);
	int MinIndex(int* nList, int startIndex, int endIndex, int& nComparisons);
	void BubbleUp(int* nList, int nStartIndex, int nEndIndex, int& nComparisons);
	void AdaptiveBubbleUp(int* nList, int nStartIndex, int nEndIndex, bool& sorted, int& nComparisons);
	void InsertItem(int* nList, int nStartIndex, int nEndIndex, int& nComparisons);

public:
	SortingAlgorithms();
	void SelectionSort(int* nList, int nListLength, int& nComparisons);
	void BubbleSort(int* nList, int nListLength, int& nComparisons);
	void AdaptiveBubbleSort(int* nList, int nListLength, int& nComparisons);
	void InsertionSort(int* nList, int nListLength, int& nComparisons);
};

#endif SORTING_H