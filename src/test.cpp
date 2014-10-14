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
      ListNode* next;
      ListNode(int x) {
          val = x;
          next = NULL;
      }
  };

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

ListNode* insertNode(ListNode* head, ListNode* newNode)
{
	if (head == NULL)
		return newNode;

	if (head->val >= newNode->val)
	{
		newNode->next = head;
		return newNode;
	}

	else
	{
		ListNode* pre = head;
		ListNode* cur = head->next;

		while(cur != NULL)
		{
			if (cur->val >= newNode->val)
			{
				newNode->next = cur;
				pre->next = newNode;
				return head;
			}

			pre = cur;
			cur = cur->next;
		}

		pre->next = newNode;

		return head;
	}
}

ListNode* insertNodewithTwoLevelPointer(ListNode* head, ListNode* newNode)
{
	if (head == NULL)
		return newNode;

	ListNode** p = &head;

	while(*p != NULL)
	{
		if ((*p)->val >= newNode->val)
		{
			newNode->next = (*p)->next;
			*p = newNode;
		}

		*p = (*p)->next;
	}

	if ((*p)->next == head)
		return *p;
	else
		return head;
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

ListNode* rotateOnce(ListNode* head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        ListNode* pre;
        ListNode* cur = head;
        ListNode* next = cur->next;

        while(next != NULL)
        {
            pre = cur;
            cur = next;
            next = next->next;
        }

        pre->next = NULL;
        cur->next = head;

        return cur;
    }

ListNode *rotateRight(ListNode *head, int k) {

        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        int length = 0;
        ListNode* cur = head;

        while (cur != NULL)
        {
            cur = cur->next;
            length++;
        }

        int rotateTimes = k&length;

        ListNode* newHead = head;

        for (int i = 0; i < rotateTimes; i++)
        {
            newHead = rotateOnce(newHead);
        }

        return newHead;

    }

ListNode *partition(ListNode *head, int x) {

        if (head == NULL)
            return NULL;

        if (head->next == NULL)
            return head;

        ListNode dummy = ListNode(0);
        dummy.next = head;

        ListNode* pre = &dummy;
        ListNode* cur = head;
        ListNode* next;
        ListNode* curSmall = &dummy;

        while (cur != NULL)
        {
            next = cur->next;

            if (cur->val < x)
            {
                pre->next = cur->next;
                cur->next = curSmall->next;
                curSmall->next = cur;
                curSmall = cur;
                if (pre == &dummy)
                    pre = cur;
            }

            else
            {
                pre = cur;
            }

            cur = next;
        }

        return dummy.next;
    }

//struct RandomListNode {
//      int label;
//      RandomListNode *next, *random;
//      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
//  };
//
//RandomListNode *copyRandomList(RandomListNode *head) {
//
//        RandomListNode* cur_node=head;
//        RandomListNode* new_head=NULL;
//        RandomListNode* new_tail=NULL;
//
//        while (cur_node!=NULL)
//        {
//            RandomListNode* next_node=cur_node->next;
//
//            RandomListNode* new_node= new RandomListNode(cur_node->label);
//
//            cur_node->next=new_node;
//            new_node->random=cur_node;
//
//            if (new_head==NULL)
//            {
//                new_head=new_node;
//                new_tail=new_node;
//            }
//            else
//            {
//                new_tail->next=new_node;
//                new_tail=new_node;
//            }
//
//            cur_node=next_node;
//        }
//
//        cur_node=new_head;
//
//        vector<RandomListNode*> originals;
//
//        while (cur_node!=NULL)
//        {
//            RandomListNode* original_node=cur_node->random;
//
//			if (original_node->random==NULL)
//				cur_node->random=NULL;
//			else
//                cur_node->random=original_node->random->next;
//
//			originals.push_back(original_node);
//
//			cur_node=cur_node->next;
//        }
//
//        for (int i=0;i<originals.size();i++)
//        {
//            if (i!=originals.size()-1)
//                originals[i]->next=originals[i+1];
//            else
//                originals[i]->next=NULL;
//        }
//        return new_head;
//
//    }

int main()
{
//	ListNode* head = new ListNode(1);
//
//	ListNode* second = new ListNode(2);
//
//	ListNode* third = new ListNode(3);
//
//	head->next = second;
//	second->next = third;
//
//	head = partition(head, 4);
//
//	std::cout << head->val << std::endl
//			<< (head->next)->val <<std::endl
//			<< ((head->next)->next)->val<<std::endl;

	RentalCarSystem r(100);

	Date start = Date (2014, 10, 10);

	Date end = Date (2014, 10, 11);

	std::cout << r.inquiryAvailability(0, start, end) << std::endl;

	std::cout << r.placeOrder(0, start, end) << std::endl;

	std::cout << r.inquiryAvailability(0, start, end) << std::endl;

	std::cout << r.cancelOrder(0) << std::endl;

	std::cout << r.inquiryAvailability(0, start, end) << std::endl;

	return 0;
}
