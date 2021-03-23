#ifndef SORTING_H
#define SORTING_H

class SortingAlgorithms
{
private:
	void inline Swap(int& num1, int& num2);
	int MinIndex(int* nList, int startIndex, int endIndex);
	void BubbleUp(int* nList, int nStartIndex, int nEndIndex);
	void AdaptiveBubbleUp(int* nList, int nStartIndex, int nEndIndex, bool& sorted);

public:
	SortingAlgorithms();
	void SelectionSort(int* nList, int nListLength);
	void BubbleSort(int* nList, int nListLength);
	void AdaptiveBubbleSort(int* nList, int nListLength);
};

#endif SORTING_H