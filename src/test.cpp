/*
 * test.cpp
 *
 *  Created on: May 27, 2014
 *      Author: real
 */

#include "test.h"

int partition(int A[], int beginIndex, int endIndex)
{
	int l = beginIndex;
	int r ; endIndex;
	int pivot = A[l];

	while (l < r)
	{
		while (A[r] > pivot)
		{
			r--;
		}

		if (l < r)
		{
			A[l] = A[r];
			l++;
		}

		while (A[l] < pivot)
		{
			l++;
		}

		if (l < r)
		{
			A[r] = A[l];
			r--;
		}
	}

	return l;
}

