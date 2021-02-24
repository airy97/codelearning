#include "MyBinarySearchTree.h"
#include <algorithm>
#include <math.h>

MyBinarySearchTree::MyBinarySearchTree()
{
	treesize = 0;
}

MyBinarySearchTree::MyBinarySearchTree(_Kty k)
{
	treesize = 0;
	insert(k);
}

MyBinarySearchTree::MyBinarySearchTree(NodePtr pNode)
{
	root = pNode;
	treesize = 1;
}


MyBinarySearchTree::MyBinarySearchTree(const std::vector<_Kty>& datalist)
{
	treesize = 0;
	insert(datalist);
}

MyBinarySearchTree::~MyBinarySearchTree()
{

}

bool MyBinarySearchTree::empty()
{
	return (bool)root;
}

int MyBinarySearchTree::size()
{
	return treesize;
}

void MyBinarySearchTree::print()
{
	std::cout << "\nDate in My Binary Search Tree: ";
	Inorder_Tree_Wark(root);
	std::cout << std::endl;
}

void MyBinarySearchTree::printInfo()
{
	std::cout << "tree size: " << size() << ", tree height: " << hight() << std::endl;
}

void MyBinarySearchTree::insert(_Kty k)
{
	treesize += Tree_Insert(root, std::make_shared<MyBinarySearchTree::Node>(k)) ? 1 : 0;
}

void MyBinarySearchTree::insert(const std::vector<_Kty>& datalist)
{
	for (const auto& data : datalist)
	{
		insert(data);
	}
}

void MyBinarySearchTree::random_insert(std::vector<_Kty> datalist)
{
	std::random_shuffle(datalist.begin(), datalist.end());
	insert(datalist);
}

void MyBinarySearchTree::erase(_Kty k)
{
	NodePtr pNode = Tree_Search(root, k);
	if (pNode != nullptr)
	{
		Tree_Delete(root, pNode);
		--treesize;
	}
}

void MyBinarySearchTree::clear()
{
	root = nullptr;
	treesize = 0;
}

int MyBinarySearchTree::hight()
{
	return Tree_Hight(root) - 1;
}

void MyBinarySearchTree::Inorder_Tree_Wark(NodePtr pNode)
{
	if (pNode != nullptr)
	{
		Inorder_Tree_Wark(pNode->left);
		std::cout << pNode->key << ", ";
		Inorder_Tree_Wark(pNode->right);
	}
}

MyBinarySearchTree::NodePtr MyBinarySearchTree::Tree_Search(NodePtr pNode, const _Kty& k)
{
	if (!pNode || pNode->key == k)
	{
		return pNode;
	}
	else if (k < pNode->key)
	{
		return Tree_Search(pNode->left, k);
	}
	else
	{
		return Tree_Search(pNode->right, k);
	}
}

MyBinarySearchTree::NodePtr MyBinarySearchTree::Iterative_Tree_Search(NodePtr pNode, const _Kty& k)
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

MyBinarySearchTree::NodePtr MyBinarySearchTree::Tree_Minimun(NodePtr pNode)
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

MyBinarySearchTree::NodePtr MyBinarySearchTree::Tree_Maximun(NodePtr pNode)
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

MyBinarySearchTree::NodePtr MyBinarySearchTree::Tree_Successor(NodePtr pNode)
{
	if (!pNode)
		return pNode;
	if (pNode->right)
	{
		return Tree_Minimun(pNode->right);
	}
	NodePtr pRightNode = pNode->p;
	while (pRightNode && pNode == pRightNode->right)
	{
		pNode = pRightNode;
		pRightNode = pRightNode->p;
	}
	return pRightNode;
}

bool MyBinarySearchTree::Tree_Insert(NodePtr& head, NodePtr pNode)
{
	if (!pNode)
		return false;
	NodePtr p;
	NodePtr pHead = head;
	while (pHead)
	{
		p = pHead;
		if (pNode->key < pHead->key)
		{
			pHead = pHead->left;
		}
		else if (pNode->key > pHead->key)
		{
			pHead = pHead->right;
		}
		else
		{
			return false;
		}
	}
	pNode->p = p;
	if (!p)
	{
		head = pNode;
	}
	else if (pNode->key < p->key)
	{
		p->left = pNode;
	}
	else
	{
		p->right = pNode;
	}
	return true;
}

bool MyBinarySearchTree::Tree_Delete(NodePtr& head, NodePtr pNode)
{
	if (!pNode->left)
	{
		Transplant(head, pNode, pNode->right);
	}
	else if (!pNode->right)
	{
		Transplant(head, pNode, pNode->left);
	}
	else
	{
		NodePtr y = Tree_Minimun(pNode->right);
		if (y->p != pNode)
		{
			Transplant(head, y, y->right);
			y->right = pNode->right;
			y->right->p = y;
		}
		Transplant(head, pNode, y);
		y->left = pNode->left;
		y->left->p = y;
	}
	return true;
}

void MyBinarySearchTree::Transplant(NodePtr& root, NodePtr u, NodePtr v)
{
	if (!u->p)
	{
		root = v;
	}
	else if (u == u->p->left)
	{
		u->p->left = v;
	}
	else
	{
		u->p->right = v;
	}
	if (v)
	{
		v->p = u->p;
	}
}

int MyBinarySearchTree::Tree_Hight(NodePtr root)
{
	if (!root)
	{
		return 0;
	}
	return std::max(Tree_Hight(root->left) + 1, Tree_Hight(root->right) + 1);
}
