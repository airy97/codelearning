#include "MyBinarySearchTree.h"
#include <iostream>

MyBinarySearchTree::MyBinarySearchTree()
{
	root = nullptr;
	degree = 0;
}

MyBinarySearchTree::MyBinarySearchTree(Node* pNode)
{
	root = pNode;
	degree = 1;
}

MyBinarySearchTree::~MyBinarySearchTree()
{

}

bool MyBinarySearchTree::empty()
{
	return (bool)root;
}

void MyBinarySearchTree::Inorder_Tree_Wark(Node* pNode)
{
	if (pNode != nullptr)
	{
		Inorder_Tree_Wark(pNode->left);
		std::cout << pNode->key << "; ";
		Inorder_Tree_Wark(pNode->right);
	}
}

MyBinarySearchTree::Node* MyBinarySearchTree::Tree_Search(Node* pNode, const _Kty& k)
{
	if (!pNode || pNode->key == k)
	{
		return pNode;
	}
	else if (pNode->key < k)
	{
		return Tree_Search(pNode->left, k);
	}
	else
	{
		return Tree_Search(pNode->right, k);
	}
}

MyBinarySearchTree::Node* MyBinarySearchTree::Iterative_Tree_Search(Node* pNode, const _Kty& k)
{
	while (!pNode || pNode->key == k)
	{
		if (k < pNode->key)
		{
			pNode = pNode->left;
		}
		else
		{
			pNode = pNode->right;
		}
	}
	return pNode;
}

MyBinarySearchTree::Node* MyBinarySearchTree::Tree_Minimun(Node* pNode)
{
	if (pNode)
	{
		while (pNode->left)
		{
			pNode = pNode->left;
		}
	}
	return pNode;
}

MyBinarySearchTree::Node* MyBinarySearchTree::Tree_Maximun(Node* pNode)
{
	if (pNode)
	{
		while (pNode->right)
		{
			pNode = pNode->right;
		}
	}
	return pNode;
}

MyBinarySearchTree::Node* MyBinarySearchTree::Tree_Successor(Node* pNode)
{
	if (!pNode)
		return pNode;
	if (pNode->right)
	{
		return Tree_Minimun(pNode->right);
	}
	Node* pRightNode = pNode->p;
	while (pRightNode && pNode == pRightNode->right)
	{
		pNode = pRightNode;
		pRightNode = pRightNode->p;
	}
	return pRightNode;
}

void MyBinarySearchTree::Tree_Insert(Node* pHead, Node* pNode)
{
	if (!pHead)
	{
		pHead = pNode;
		return;
	}
	else if (pHead->key == pNode->key)
	{
		pHead->val = pNode->val;
		return;
	}

}

void MyBinarySearchTree::Tree_Delete(Node* pHead, Node* pNode)
{
}
