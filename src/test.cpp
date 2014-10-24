/*
 * test.cpp
 *
 *  Created on: May 27, 2014
 *      Author: real
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

void printTree(TreeNode* root)
{
	if (root == NULL)
		return;

	std::queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		q.push(q.front()->left);
		q.push(q.front()->right);
		std::cout << q.front()->val << ' ';
		q.pop();
	}

	return;
}

int main()
{
	std::stack<TreeNode*> s;

	return 0;
}
