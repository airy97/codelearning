#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <stack>
class MyBinTree
{
public:
	class TreeNode
	{
	public:
		int val;
		std::shared_ptr<TreeNode> left;
		std::shared_ptr<TreeNode> right;
		TreeNode(int v = 0) :val(v) {}
		~TreeNode() {}
	};

	typedef std::shared_ptr<TreeNode> nodeptr;
	static  nodeptr getBinTree(const std::vector<int> nums)
	{
		int n = nums.size();
		if (n == 0)
			return nullptr;
		std::vector<nodeptr> ptrs(n);
		for (int i = 0; i < n; ++i)
		{
			ptrs[i].reset(new TreeNode(nums[i]));
		}
		for (int i = 0; i < (n - 1) / 2; ++i)
		{
			ptrs[i]->left = ptrs[2 * i + 1];
			ptrs[i]->right = ptrs[2 * i + 2];
		}
		if (n % 2 == 0)
		{
			ptrs[n / 2 - 1]->left = ptrs[n - 1];
		}
		return ptrs[0];
	}

	static void preorder_recur(nodeptr head)
	{
		if (head == nullptr)
		{
			return;
		}
		std::cout << head->val << ", ";
		preorder_recur(head->left);
		preorder_recur(head->right);
	}

	typedef std::stack<nodeptr> pstack;
	static void preorder_iter(nodeptr head)
	{
		pstack pk;
		pk.push(head);
		nodeptr p;
		while (!pk.empty())
		{
			p = pk.top();
			pk.pop();
			if (p != nullptr)
			{
				std::cout << p->val << ", ";
				pk.push(p->right);
				pk.push(p->left);
			}
		}
	}

	static void inorder_recur(nodeptr head)
	{
		if (head == nullptr)
		{
			return;
		}
		inorder_recur(head->left);
		std::cout << head->val << ", ";
		inorder_recur(head->right);
	}

	static void inorder_iter(nodeptr head)
	{
		pstack pk;
		nodeptr p = head;
		while (!pk.empty() || p != nullptr)
		{
			while (p != nullptr)
			{
				pk.push(p);
				p = p->left;
			}
			p = pk.top();
			pk.pop();
			std::cout << p->val << ", ";
			p = p->right;
		}
	}

	static void postorder_recur(nodeptr head)
	{
		if (head == nullptr)
		{
			return;
		}
		postorder_recur(head->left);
		postorder_recur(head->right);
		std::cout << head->val << ", ";
	}

	static void postorder_iter(nodeptr head)
	{
		pstack pk;
		pk.push(head);
		pstack postk;
		nodeptr p = head;
		while (!pk.empty() || p != nullptr)
		{
			p = pk.top();
			pk.pop();
			if (p != nullptr)
			{
				postk.push(p);
				pk.push(p->left);
				pk.push(p->right);
			}			
		}
		while (!postk.empty())
		{
			std::cout << postk.top()->val << ", ";
			postk.pop();
		}
	}
};

