/*
 * test.cpp
 *
 *  Created on: May 27, 2014
 *      Author: real
 */

#include <iostream>
#include <vector>
#include <stack>
#include "test.h"

class ListNode {
public:
      int val;
      ListNode* next;
      ListNode(int x) {
          val = x;
          next = NULL;
      }
  };

class TreeNode {
public:
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main()
{
	std::stack<TreeNode*> s;

	return 0;
}
