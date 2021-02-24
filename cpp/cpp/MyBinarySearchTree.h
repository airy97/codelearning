#pragma once
#include <memory>
#include <vector>
#include <iostream>
//该二叉搜索树仅维护key，不保存卫星数据
typedef int _Kty;
class MyBinarySearchTree
{
public:
	class Node
	{
	public:
		_Kty key = _Kty();
		std::shared_ptr<Node> p;
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;
		Node(_Kty k)
		{
			key = k;
		}
		~Node() {
			std::cout << "\nNode deleted!\n";
		}
	};
	using NodePtr = std::shared_ptr<MyBinarySearchTree::Node>;

	MyBinarySearchTree();
	MyBinarySearchTree(_Kty k);
	MyBinarySearchTree(const std::vector<_Kty>& datalist);
	MyBinarySearchTree(NodePtr pNode);
	~MyBinarySearchTree();

private:
	NodePtr root;
	int treesize;

public:
	bool empty();
	int size();
	void print();
	void printInfo();
	void insert(_Kty k);
	void insert(const std::vector<_Kty>& datalist);
	void random_insert(std::vector<_Kty> datalist);
	void erase(_Kty k);
	void clear();
	int hight();

public:
	static void Inorder_Tree_Wark(NodePtr pNode);

	static NodePtr Tree_Search(NodePtr pNode, const _Kty& k);

	static NodePtr Iterative_Tree_Search(NodePtr pNode, const _Kty& k);

	static NodePtr Tree_Minimun(NodePtr pNode);

	static NodePtr Tree_Maximun(NodePtr pNode);

	static NodePtr Tree_Successor(NodePtr pNode);

	static bool Tree_Insert(NodePtr& head, NodePtr pNode);

	static bool Tree_Delete(NodePtr& head, NodePtr pNode);

	static void Transplant(NodePtr& root, NodePtr u, NodePtr v);

	static int Tree_Hight(NodePtr root);

};

