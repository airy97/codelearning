#pragma once
#include <memory>
#include <vector>
#include <iostream>
class MyRBTree
{
public:
	typedef int K;
	typedef int V;
	static const bool black = true;
	static const bool red = false;
	class RBNode
	{
	public:
		K key = K();
		V val = V();
		std::weak_ptr<RBNode> p;
		std::shared_ptr<RBNode> left;
		std::shared_ptr<RBNode> right;
		bool color = black;//true-black,false-red
	};
	class RBNodeNIL : RBNode
	{
	};
	typedef std::shared_ptr<RBNode> NodePtr;

private:
	NodePtr root;
	std::unique_ptr<RBNodeNIL> pNil = std::make_unique<RBNodeNIL>(RBNodeNIL());
};

