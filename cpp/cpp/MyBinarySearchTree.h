#pragma once
#include <memory>
typedef int _Kty;
typedef int _Ty;
class MyBinarySearchTree
{
public:
	class Node
	{
	public:
		_Kty key = _Kty();
		_Ty val = _Ty();
		Node* p = nullptr;
		Node* left = nullptr;
		Node* right = nullptr;
	};
	MyBinarySearchTree();
	MyBinarySearchTree(Node* pNode);
	~MyBinarySearchTree();
	bool empty();

	static void Inorder_Tree_Wark(Node* pNode);

	static Node* Tree_Search(Node* pNode, const _Kty& k);

	static Node* Iterative_Tree_Search(Node* pNode, const _Kty& k);

	static Node* Tree_Minimun(Node* pNode);

	static Node* Tree_Maximun(Node* pNode);

	static Node* Tree_Successor(Node* pNode);

	static void Tree_Insert(Node* pHead, Node* pNode);

	static void Tree_Delete(Node* pHead, Node* pNode);

private:
	Node* root;
	int degree;
};

