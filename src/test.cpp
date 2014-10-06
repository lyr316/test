/*
 * test.cpp
 *
 *  Created on: May 27, 2014
 *      Author: real
 */

#include <iostream>
#include <vector>
#include "test.h"

int partition(int A[], int start, int end, int pivotIndex)
{
	std::swap(A[pivotIndex], A[end]);

	int newPivotIndex = start;

	for (int i = start; i < end; i++)
	{
		if (A[i] < A[end])
		{
			std::swap(A[i], A[newPivotIndex]);
			newPivotIndex++;
		}
	}

	std::swap(A[end], A[newPivotIndex]);

	return newPivotIndex;
}

void quickSort(int A[], int l, int r)
{
	if (l >= r)
		return;

	int pivotIndex = partition(A, l, r, l);

	quickSort(A, l, pivotIndex - 1);
	quickSort(A, pivotIndex + 1, r);
}

int quickSelect(int A[], int l, int r, int k)
{
	int pivotIndex = partition(A, l, r, l);

	if (pivotIndex <= k - 1)
	{
		return quickSelect(A, pivotIndex + 1, r, k);
	}

	if (pivotIndex >= k + 1)
	{
		return quickSelect(A, l, pivotIndex - 1, l);
	}

	else
		return A[pivotIndex];
}

int binarySearchRecursive(int A[], int start, int end, int target)
{
	if (start == end && A[start] != target)
		return -1;

	int mid = start + (end - start)/2;

	if (A[mid] < target)
		return binarySearchRecursive(A, mid + 1, end, target);

	else if (A[mid] > target)
		return binarySearchRecursive(A, start, mid - 1, target);

	else
		return mid;
}

int binarySearchIterative(int A[], int l, int r, int target)
{
	if (l > r)
		return -1;

	int start = l;
	int end = r;

	while(start <= end)
	{
		int mid = start + (end - start)/2;

		if (A[mid] < target)
		{
			start = mid + 1;
		}

		else if (A[mid] > target)
		{
			end = mid - 1;
		}

		else
			return mid;
	}

	return -1;
}

int binarySearchLast(int A[], int start, int end, int target)
{
	if (start > end)
		return -1;

	int mid = start + (end - start)/2;

	if (A[mid] < target)
		return binarySearchLast(A, mid + 1, end, target);

	else if (A[mid] > target)
		return binarySearchLast(A, start, mid - 1, target);

	else
	{
		int lastTarget = binarySearchLast(A, mid + 1, end, target);
		if (lastTarget == -1)
			return mid;
		else
			return lastTarget;
	}
}

class ListNode {
public:
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
          next = NULL;
      }
  }

ListNode* searchVal(ListNode* head, int target)
{
	ListNode* current = head;
	while(current != NULL)
	{
		if (current->val == target)
			return current;
		current = current->next;
	}
	return NULL;
}

ListNode* appendNode(ListNode* head, ListNode* newNode)
{
	ListNode* current = head;
	while(current->next != NULL)
		{
			current = current->next;
		}
	current->next = newNode;

	return head;
}

void insertNode(ListNode* someNode, ListNode* newNode)
{
	newNode->next = someNode->next;
	someNode->next = newNode;
}

ListNode* deleteNode(ListNode* head, int val)
{
	ListNode* current = head;
	ListNode* previous = NULL;
	ListNode* newHead = head;

	while(current != NULL)
	{
		if (current->val == val)
		{
			if (current == head)
				newHead = newHead->next;

			previous->next = current->next;
			current->next = NULL;
			return newHead;
		}

		else
		{
			previous = current;
			current = current->next;
		}
	}

	return newHead;
}

ListNode* deleteMultipleNode(ListNode* head, int val)
{
	ListNode* current = head;
	ListNode* previous = NULL;
	ListNode* newHead = head;

	while(current != NULL)
	{
		if (current->val == val)
		{
			if (current == newHead)
				newHead = newHead->next;

			previous->next = current->next;
			current->next = NULL;
			current = previous->next;
		}

		else
		{
			previous = current;
			current = current->next;
		}
	}
	return newHead;
}

int main()
{
	ListNode* Head = new ListNode(0);

	ListNode* Second = new ListNode(1);

	ListNode* Third = new ListNode(2);

	Head->next = Second;

	Second->next = Third;

	std::cout << searchVal(Head, 2)->val << std::endl;

	return 0;
}
