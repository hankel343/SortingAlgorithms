#include <iostream>
#include <time.h>
#include "SortingAlgorithms.h"

using namespace std;

int main()
{
	SortingAlgorithms Algo;

	srand(time(NULL));
	int nTemp = 0;
	const int nLIST_LENGTH = 10;
	int* nList = new int[nLIST_LENGTH];

	for (int i = 0; i < nLIST_LENGTH; i++)
	{
		nTemp = rand() % RAND_MAX;

		nList[i] = nTemp;
	}

	cout << "Before sorting: \n";
	for (int i = 0; i < nLIST_LENGTH; i++)
	{
		if (i != 0 && i % 10 == 0)
			cout << endl << nList[i] << " ";
		else
			cout << nList[i] << " ";
	}

	Algo.AdaptiveBubbleSort(nList, nLIST_LENGTH);

	cout << "\n\nAfter sorting: \n";
	for (int i = 0; i < nLIST_LENGTH; i++)
	{
		if (i != 0 && i % 10 == 0)
			cout << endl << nList[i] << " ";
		else
			cout << nList[i] << " ";
	}

	delete[] nList;

	return 0;
}