#include "SortingAlgorithms.h"

SortingAlgorithms::SortingAlgorithms()
{}

void SortingAlgorithms::SelectionSort(int *nList, int nListLength)
{
	int nEndIndex = nListLength - 1;
	for (int i = 0; i < nListLength; i++)
		Swap(nList[i], nList[MinIndex(nList, i, nEndIndex)]);
}

void SortingAlgorithms::Swap(int& num1, int& num2)
{
	int nTemp = num1;
	num1 = num2;
	num2 = nTemp;
}

int SortingAlgorithms::MinIndex(int* nList, int nStartIndex, int nEndIndex)
{
	int nIndexOfMin = nStartIndex;
	
	for (int i = nStartIndex + 1; i <= nEndIndex; i++)
		if (nList[i] < nList[nIndexOfMin])
			nIndexOfMin = i;

	return nIndexOfMin;
}