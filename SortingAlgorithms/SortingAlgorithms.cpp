#include "SortingAlgorithms.h"

/*Private*/
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

//Auxiliary to BubbleSort
void SortingAlgorithms::BubbleUp(int* nList, int nStartIndex, int nEndIndex)
{
	for (int i = nEndIndex; i > nStartIndex; i--)
		if (nList[i] < nList[i - 1])
			Swap(nList[i], nList[i - 1]);
}

//Auxiliary to AdaptiveBubbleSort
void SortingAlgorithms::AdaptiveBubbleUp(int* nList, int nStartIndex, int nEndIndex, bool& bSorted)
{
	bSorted = true;
	for (int i = nEndIndex; i > nStartIndex; i--)
	{
		if (nList[i] < nList[i - 1])
		{
			Swap(nList[i], nList[i - 1]);
			bSorted = false;
		}
			
	}
}

/*Public*/
SortingAlgorithms::SortingAlgorithms()
{}

void SortingAlgorithms::SelectionSort(int* nList, int nListLength)
{
	int nEndIndex = nListLength - 1;
	for (int i = 0; i < nListLength; i++)
		Swap(nList[i], nList[MinIndex(nList, i, nEndIndex)]);
}

void SortingAlgorithms::BubbleSort(int* nList, int nListLength)
{
	for (int i = 0; i < nListLength; i++)
		BubbleUp(nList, i, nListLength - 1);
}

void SortingAlgorithms::AdaptiveBubbleSort(int* nList, int nListLength)
{
	bool bSorted = false;
	for (int i = 0; i < nListLength && bSorted == false; i++)
		AdaptiveBubbleUp(nList, i, nListLength - 1, bSorted);
}