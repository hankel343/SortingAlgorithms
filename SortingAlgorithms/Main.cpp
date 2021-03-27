#include <iostream>
#include <time.h>
#include <chrono>
#include <iomanip>
#include "SortingAlgorithms.h"

using namespace std;

int main()
{
	srand(time(NULL));
	chrono::time_point<chrono::system_clock> start;
	chrono::time_point<chrono::system_clock> end;
	chrono::duration<float> elapsed;

	SortingAlgorithms Algo;


	int nTemp = 0;
	long long nComparisons = 0;
	const int nLIST_LENGTH = 100000;
	int* pSelectionSort = new int[nLIST_LENGTH];
	int* pBubbleSort = new int[nLIST_LENGTH];
	int* pAdaptiveBubbleSort = new int[nLIST_LENGTH];
	int* pInsertionSort = new int[nLIST_LENGTH];
	int* pMergeSort = new int[nLIST_LENGTH];
	int* pHeapSort = new int[nLIST_LENGTH];

	for (int i = 0; i < nLIST_LENGTH; i++)
	{
		nTemp = rand() % RAND_MAX;

		pSelectionSort[i] = nTemp;
		pBubbleSort[i] = nTemp;
		pAdaptiveBubbleSort[i] = nTemp;
		pInsertionSort[i] = nTemp;
		pMergeSort[i] = nTemp;
		pHeapSort[i] = nTemp;
	}


	start = chrono::system_clock::now();
	Algo.SelectionSort(pSelectionSort, nLIST_LENGTH, nComparisons);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Selection Sort:\n";
	cout << "Sorting time: " << fixed << elapsed.count() << " seconds" << endl;
	cout << "Total comparisons: " << nComparisons << endl;

	nComparisons = 0;
	start = chrono::system_clock::now();
	Algo.BubbleSort(pBubbleSort, nLIST_LENGTH, nComparisons);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "\nBubble Sort:\n";
	cout << "Sorting time: " << fixed << elapsed.count() << " seconds" << endl;
	cout << "Total comparisons: " << nComparisons << endl;

	nComparisons = 0;
	start = chrono::system_clock::now();
	Algo.AdaptiveBubbleSort(pAdaptiveBubbleSort, nLIST_LENGTH, nComparisons);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "\nAdaptive Bubble Sort: \n";
	cout << "Sorting time: " << fixed << elapsed.count() << " seconds" << endl;
	cout << "Total comparisons: " << nComparisons << endl;

	nComparisons = 0;
	start = chrono::system_clock::now();
	Algo.InsertionSort(pInsertionSort, nLIST_LENGTH, nComparisons);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "\nInsertion Sort:\n";
	cout << "Sorting time: " << fixed << elapsed.count() << " seconds" << endl;
	cout << "Total comparisons: " << nComparisons << endl;
	
	int* pTempArray = new int[nLIST_LENGTH];
	nComparisons = 0;
	start = chrono::system_clock::now();
	Algo.MergeSort(pMergeSort, 0, nLIST_LENGTH-1, pTempArray, nComparisons);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "\nMerge Sort:\n";
	cout << "Sorting time: " << fixed << elapsed.count() << " seconds" << endl;
	cout << "Total comparisons: " << nComparisons << endl;

	nComparisons = 0;
	start = chrono::system_clock::now();
	Algo.HeapSort(pHeapSort, nLIST_LENGTH, nComparisons);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "\nHeapSort:\n";
	cout << "Sorting time: " << fixed << elapsed.count() << " seconds" << endl;
	cout << "Total comparisons: " << nComparisons << endl;

	delete[] pSelectionSort;
	delete[] pBubbleSort;
	delete[] pAdaptiveBubbleSort;
	delete[] pInsertionSort;
	delete[] pMergeSort;
	delete[] pTempArray;
	delete[] pHeapSort;

	return 0;
}