#include "SortingAlgorithms.h"

/*Private*/
void SortingAlgorithms::Swap(int& num1, int& num2)
{
	int nTemp = num1;
	num1 = num2;
	num2 = nTemp;
}

int SortingAlgorithms::MinIndex(int* nList, int nStartIndex, int nEndIndex, int& nComparisons)
{
	int nIndexOfMin = nStartIndex;

	for (int i = nStartIndex + 1; i <= nEndIndex; i++)
	{
		nComparisons++;
		if (nList[i] < nList[nIndexOfMin])
			nIndexOfMin = i;
	}

	return nIndexOfMin;
}

//Auxiliary to BubbleSort
void SortingAlgorithms::BubbleUp(int* nList, int nStartIndex, int nEndIndex, int& nComparisons)
{
	for (int i = nEndIndex; i > nStartIndex; i--)
	{
		nComparisons++;
		if (nList[i] < nList[i - 1])
			Swap(nList[i], nList[i - 1]);
	}
		
}

//Auxiliary to AdaptiveBubbleSort
void SortingAlgorithms::AdaptiveBubbleUp(int* nList, int nStartIndex, int nEndIndex, bool& bSorted, int& nComparisons)
{
	bSorted = true;
	for (int i = nEndIndex; i > nStartIndex; i--)
	{
		nComparisons++;
		if (nList[i] < nList[i - 1])
		{
			Swap(nList[i], nList[i - 1]);
			bSorted = false;
		}
			
	}
}

//Auxiliary to InsertionSort
void SortingAlgorithms::InsertItem(int* nList, int nStartIndex, int nEndIndex, int& nComparisons)
{
	bool bFinished = false;
	int nCurrent = nEndIndex;
	bool bMoreToSearch = (nCurrent != nStartIndex);

	while (bMoreToSearch && bFinished == false)
	{
		nComparisons++;
		if (nList[nCurrent] < nList[nCurrent - 1])
		{
			Swap(nList[nCurrent], nList[nCurrent - 1]);
			nCurrent--;
			bMoreToSearch = (nCurrent != nStartIndex);
		}
		else
			bFinished = true;
	}
}

/*Public*/
SortingAlgorithms::SortingAlgorithms()
{}

void SortingAlgorithms::SelectionSort(int* nList, int nListLength, int& nComparisons)
{
	int nEndIndex = nListLength - 1;
	for (int i = 0; i < nListLength; i++)
		Swap(nList[i], nList[MinIndex(nList, i, nEndIndex, nComparisons)]);
}

void SortingAlgorithms::BubbleSort(int* nList, int nListLength, int& nComparisons)
{
	for (int i = 0; i < nListLength; i++)
		BubbleUp(nList, i, nListLength - 1, nComparisons);
}

void SortingAlgorithms::AdaptiveBubbleSort(int* nList, int nListLength, int& nComparisons)
{
	bool bSorted = false;
	for (int i = 0; i < nListLength && bSorted == false; i++)
		AdaptiveBubbleUp(nList, i, nListLength - 1, bSorted, nComparisons);
}

void SortingAlgorithms::InsertionSort(int* nList, int nListLength, int& nComparisons)
{
	for (int i = 0; i < nListLength; i++)
		InsertItem(nList, 0, i, nComparisons);
}