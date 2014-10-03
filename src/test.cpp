/*
 * test.cpp
 *
 *  Created on: May 27, 2014
 *      Author: real
 */

#include <iostream>
#include "test.h"

int partition(int A[], int beginIndex, int endIndex)
{
	int l = beginIndex;
	int r = endIndex;
	int pivot = A[l];

	while (l < r)
	{
		while (A[r] > pivot && l < r)
		{
			r--;
		}

		if (l < r)
		{
			A[l] = A[r];
			l++;
		}

		while (A[l] < pivot && l < r)
		{
			l++;
		}

		if (l < r)
		{
			A[r] = A[l];
			r--;
		}
	}

	A[l] = pivot;
	return l;
}

void quickSort(int A[], int l, int r)
{
	if (l >= r)
		return;

	int pivotIndex = partition(A, l, r);

	quickSort(A, l, pivotIndex - 1);
	quickSort(A, pivotIndex + 1, r);
}

int main()
{
	int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	quickSort(A, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		std::cout << A[i] << std::endl;
	}

	return 0;
}

