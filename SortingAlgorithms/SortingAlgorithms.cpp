#include "SortingAlgorithms.h"

/*Private*/
void SortingAlgorithms::Swap(int& num1, int& num2)
{
	int nTemp = num1;
	num1 = num2;
	num2 = nTemp;
}

//Auxiliary to SelectionSort
int SortingAlgorithms::MinIndex(int* pList, int nStartIndex, int nEndIndex, long long& nComparisons)
{
	int nIndexOfMin = nStartIndex;

	for (int i = nStartIndex + 1; i <= nEndIndex; i++)
	{
		nComparisons++;
		if (pList[i] < pList[nIndexOfMin])
			nIndexOfMin = i;
	}

	return nIndexOfMin;
}

//Auxiliary to BubbleSort
void SortingAlgorithms::BubbleUp(int* pList, int nStartIndex, int nEndIndex, long long& nComparisons)
{
	for (int i = nEndIndex; i > nStartIndex; i--)
	{
		nComparisons++;
		if (pList[i] < pList[i - 1])
			Swap(pList[i], pList[i - 1]);
	}
		
}

//Auxiliary to AdaptiveBubbleSort
void SortingAlgorithms::AdaptiveBubbleUp(int* pList, int nStartIndex, int nEndIndex, bool& bSorted, long long& nComparisons)
{
	bSorted = true;
	for (int i = nEndIndex; i > nStartIndex; i--)
	{
		nComparisons++;
		if (pList[i] < pList[i - 1])
		{
			Swap(pList[i], pList[i - 1]);
			bSorted = false;
		}
			
	}
}

//Auxiliary to InsertionSort
void SortingAlgorithms::InsertItem(int* pList, int nStartIndex, int nEndIndex, long long& nComparisons)
{
	bool bFinished = false;
	int nCurrent = nEndIndex;
	bool bMoreToSearch = (nCurrent != nStartIndex);

	while (bMoreToSearch && bFinished == false)
	{
		nComparisons++;
		if (pList[nCurrent] < pList[nCurrent - 1])
		{
			Swap(pList[nCurrent], pList[nCurrent - 1]);
			nCurrent--;
			bMoreToSearch = (nCurrent != nStartIndex);
		}
		else
			bFinished = true;
	}
}

//Auxiliary to MergeSort()
void SortingAlgorithms::Merge(int* pList, int nLeftFirst, int nLeftLast, int nRightFirst, int nRightLast, int* pTempArray, long long& nComparisons)
{
	int nIndex = nLeftFirst;
	int nSaveFirst = nLeftFirst;

	//Merging elements from left and right arrays in sorted order.
	while ((nLeftFirst <= nLeftLast) && (nRightFirst <= nRightLast))
	{
		nComparisons++;
		if (pList[nLeftFirst] < pList[nRightFirst])
		{
			pTempArray[nIndex] = pList[nLeftFirst];
			nLeftFirst++;
		} else {
			pTempArray[nIndex] = pList[nRightFirst];
			nRightFirst++;
		}
		nIndex++;
	}

	//Copy remaining elements from left array
	while (nLeftFirst <= nLeftLast)
	{
		pTempArray[nIndex] = pList[nLeftFirst];
		nLeftFirst++;
		nIndex++;
	}

	//Copy remaining elements from right array
	while (nRightFirst <= nRightLast)
	{
		pTempArray[nIndex] = pList[nRightFirst];
		nRightFirst++;
		nIndex++;
	}

	//Copy sorted elements back to original array
	for (nIndex = nSaveFirst; nIndex <= nRightLast; nIndex++)
	{
		pList[nIndex] = pTempArray[nIndex];
	}
}

//Auxiliary to HeapSort()
void SortingAlgorithms::ReheapDown(int* pList, int nRoot, int nLastIndex, long long& nComparisons)
{
	int nMaxChild; //Left and right child are compared, index of greater is stored in nMaxChild.
	int nLeftChild;
	int nRightChild;
	
	//Array indexing for storing binary tree in an array
	nLeftChild = nRoot * 2 + 1;
	nRightChild = nRoot * 2 + 2;

	if (nLeftChild <= nLastIndex)
	{
		if (nLeftChild == nLastIndex) //If equal, there is only a left child
		{
			nComparisons++;
			nMaxChild = nLeftChild;
		} else {
			nComparisons++;
			if (pList[nLeftChild] <= pList[nRightChild])
				nMaxChild = nRightChild;
			else
				nMaxChild = nLeftChild;
		}

		//If parent node is greater than descendent
		if (pList[nRoot] < pList[nMaxChild])
		{
			nComparisons++;
			Swap(pList[nRoot], pList[nMaxChild]);
			ReheapDown(pList, nMaxChild, nLastIndex, nComparisons);
		}
	}
}

/*Public*/
SortingAlgorithms::SortingAlgorithms()
{}

void SortingAlgorithms::SelectionSort(int* pList, int pListLength, long long& nComparisons)
{
	int nEndIndex = pListLength - 1;
	for (int i = 0; i < pListLength; i++)
		Swap(pList[i], pList[MinIndex(pList, i, nEndIndex, nComparisons)]);
}

void SortingAlgorithms::BubbleSort(int* pList, int pListLength, long long& nComparisons)
{
	for (int i = 0; i < pListLength; i++)
		BubbleUp(pList, i, pListLength - 1, nComparisons);
}

void SortingAlgorithms::AdaptiveBubbleSort(int* pList, int pListLength, long long& nComparisons)
{
	bool bSorted = false;
	for (int i = 0; i < pListLength && bSorted == false; i++)
		AdaptiveBubbleUp(pList, i, pListLength - 1, bSorted, nComparisons);
}

void SortingAlgorithms::InsertionSort(int* pList, int pListLength, long long& nComparisons)
{
	for (int i = 0; i < pListLength; i++)
		InsertItem(pList, 0, i, nComparisons);
}

void SortingAlgorithms::MergeSort(int* pList, int nFirst, int nLast, int* pTempArray, long long& nComparisons)
{
	if (nFirst < nLast)
	{
		int nMiddle = (nFirst + nLast) / 2;
		MergeSort(pList, nFirst, nMiddle, pTempArray, nComparisons);
		MergeSort(pList, nMiddle + 1, nLast, pTempArray, nComparisons);
		Merge(pList, nFirst, nMiddle, nMiddle + 1, nLast, pTempArray, nComparisons);
	}
}

void SortingAlgorithms::HeapSort(int* pHeap, int nNumValues, long long& nComparisons)
{
	for (int i = nNumValues / 2 - 1; i >= 0; i--)
		ReheapDown(pHeap, i, nNumValues - 1, nComparisons);

	for (int i = nNumValues - 1; i >= 1; i--)
	{
		Swap(pHeap[0], pHeap[i]);
		ReheapDown(pHeap, 0, i - 1, nComparisons);
	}
}