#ifndef SORTING_H
#define SORTING_H

class SortingAlgorithms
{
private:
	void inline Swap(int& num1, int& num2);
	int MinIndex(int *nList, int startIndex, int endIndex);

public:
	SortingAlgorithms();
	void SelectionSort(int *nList, int nListLength);
};

#endif SORTING_H