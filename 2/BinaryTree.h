
#pragma once

#include "stdafx.h"
#include <queue>
#include <sstream>
#include <string>
using namespace std;


struct IandN
{
	int ii;
	int nn;
};

template <typename T>
class BinTreeNode
{
public:
	T data;
	BinTreeNode<T> *leftChild, *rightChild;
	BinTreeNode<T>() : leftChild(NULL), rightChild(NULL){};
	BinTreeNode(T x, BinTreeNode<T>* left = NULL, BinTreeNode<T>* right = NULL) :data(x), leftChild(left), rightChild(right){};
};

template <typename T>
class BinaryTree
{
public:
	BinaryTree() :root(NULL){};
	BinaryTree(BinaryTree<T> &j);
	~BinaryTree();
	bool isEmpty();
	BinTreeNode<T>* Parent(BinTreeNode<T> *current);
	BinTreeNode<T>* LeftChild(BinTreeNode<T>* current);
	BinTreeNode<T>* RightChild(BinTreeNode<T>* current);
	int Height();
	int Size();
	BinTreeNode<T>* getRoot()const;
	void preOrder(void(*visit)(BinTreeNode<T>* p));
	void inOrder(void(*visit)(BinTreeNode<T>* p));
	void postOrder(void(*visit)(BinTreeNode<T>* p));
	void levelOrder(void(*visit)(BinTreeNode<T>* p));
	void CreatBinTree(char* &expression);
	BinTreeNode<T>* Find(T& item, string &result);
	void SwapTree();
	void CreatBinTreeByVLRAndLVR(char* VLR, char* LVR, int n, bool& tag);
	IandN GetIandN(BinTreeNode<T>* subTree);	//辅助画图函数，返回当前结点在当层的从左往右的个数以及层数，包含空节点 IN为结构体
	void Clear();
protected:
	BinTreeNode<T>* root;
	void destroy(BinTreeNode<T>* &subTree);
	BinTreeNode<T>* CreatBinTreeByVLRAndLVR(char* VLR, char* LVR, int n, BinTreeNode<T>* &subTree, bool& tag);
	void SwapTree(BinTreeNode<T>* subTree);
	void levelOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p));
	BinTreeNode<T>* CreatBinTree(char* &expression, BinTreeNode<T>* &subTree);
	BinTreeNode<T>* Copy(BinTreeNode<T>* orignalCode);
	int Height(BinTreeNode<T>* subTree);
	int Size(BinTreeNode<T>* subTree);
	BinTreeNode<T>* Parent(BinTreeNode<T>* subTree, BinTreeNode<T>* current);
	BinTreeNode<T>* Find(BinTreeNode<T>* subTree, const T &x)const;
	void preOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* P));
	void inOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* P));
	void postOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* P));
	T transferChtoT(char a);
	string transferTtoStr(T a);
};

template <typename T>
void BinaryTree<T>::Clear()
{
	destroy(root);
	root = NULL;
}

template <typename T>
void BinaryTree<T>::CreatBinTree(char* &expression)
{
	CreatBinTree(expression, root);
}

template <typename T>
void BinaryTree<T>::levelOrder(void(*visit)(BinTreeNode<T>* p))
{
	levelOrder(root, visit);
}

template <typename T>
void BinaryTree<T>::postOrder(void(*visit)(BinTreeNode<T>* p))
{
	postOrder(root, visit);
}

template <typename T>
void BinaryTree<T>::inOrder(void(*visit)(BinTreeNode<T>* p))
{
	inOrder(root, visit);
}

template <typename T>
void BinaryTree<T>::preOrder(void(*visit)(BinTreeNode<T>* p))
{
	preOrder(root, visit);
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>::getRoot()const
{
	return root;
}

template <typename T>
int BinaryTree<T>::Size()
{
	return Size(root);
}

template <typename T>
int BinaryTree<T>::Height()
{
	return Height(root);
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>::RightChild(BinTreeNode<T>* current)
{
	return(current == NULL) ? NULL : current->rightChild;
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>::LeftChild(BinTreeNode<T>* current)
{
	return(current == NULL) ? NULL : current->leftChild;
}

template <typename T>
BinTreeNode<T>*  BinaryTree<T>::Parent(BinTreeNode<T> *current)
{
	return(root == NULL || root == current) ? NULL : Parent(root, current);
}

template <typename T>
bool BinaryTree<T>::isEmpty()
{
	return (root == NULL) ? true : false;
}

template <typename T>
void BinaryTree<T>::SwapTree()
{
	SwapTree(root);
}

template <typename T>
void BinaryTree<T>::CreatBinTreeByVLRAndLVR(char* VLR, char* LVR, int n, bool& tag)
{
	tag = true;
	CreatBinTreeByVLRAndLVR(VLR, LVR, n, root, tag);
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	destroy(root);
}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &j)
{
	root = Copy(j.getRoot());
}

template <typename T>
void BinaryTree<T>::destroy(BinTreeNode<T>* &subTree)
{
	if (subTree != NULL)
	{
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		delete subTree;
	}
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T>* subTree, BinTreeNode<T>* current)
{
	if (subTree == NULL)
		return NULL;
	if (subTree->leftChild == current || subTree->rightChild == current)
		return subTree;
	BinTreeNode<T>* temp;
	temp = Parent(subTree->leftChild, current);
	if (temp != NULL)
		return temp;
	else
		return Parent(subTree->rightChild, current);
}

template <typename T>
void BinaryTree<T>::preOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p))
{
	if (subTree != NULL)
	{
		visit(subTree);
		preOrder(subTree->leftChild, visit);
		preOrder(subTree->rightChild, visit);
	}
}

template <typename T>
void BinaryTree<T>::inOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p))
{
	if (subTree != NULL)
	{
		inOrder(subTree->leftChild, visit);
		visit(subTree);
		inOrder(subTree->rightChild, visit);
	}
}

template <typename T>
void BinaryTree<T>::postOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p))
{
	if (subTree != NULL)
	{
		postOrder(subTree->leftChild, visit);
		postOrder(subTree->rightChild, visit);
		visit(subTree);
	}
}

template <typename T>
int BinaryTree<T>::Height(BinTreeNode<T>* subTree)
{
	if (subTree == NULL)
		return 0;
	int heightOfLeftChild = Height(subTree->leftChild);
	int heightOfRightChild = Height(subTree->rightChild);
	if (heightOfLeftChild > heightOfRightChild)
	{
		heightOfLeftChild++;
		return heightOfLeftChild;
	}
	else
	{
		heightOfRightChild++;
		return heightOfRightChild;
	}
}

template <typename T>
int BinaryTree<T>::Size(BinTreeNode<T>* subTree)
{
	if (subTree == NULL)
	{
		return 0;
	}
	if (subTree->leftChild == NULL && subTree->rightChild == NULL)
	{
		return 1;
	}
	return Size(subTree->leftChild) + Size(subTree->rightChild) + 1;
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T>* orignalCode)
{
	if (orignalCode == NULL)
		return NULL;
	BinTreeNode<T>* result = new BinTreeNode<T>(orignalCode->data);
	result->leftChild = Copy(orignalCode->leftChild);
	result->rightChild = Copy(orignalCode->rightChild);
	return result;
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>::Find(BinTreeNode<T>* subTree, const T &x)const
{
	if (subTree == NULL)
		return NULL;
	else if (subTree->data == x)
		return subTree;
	else if (subTree->rightChild == NULL&&subTree->rightChild == NULL)
		return NULL;

	BinTreeNode<T>* ptr = NULL;

	ptr = Find(subTree->leftChild, x);
	if (ptr == NULL)
	{
		ptr = Find(subTree->rightChild, x);
		return ptr;
	}
	else
		return ptr;
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>::CreatBinTree(char* &expression, BinTreeNode<T>* &subTree)
{
	if (expression[0] == '#')
		return NULL;

	if (expression[0] != '\0')
	{
		subTree = new BinTreeNode<T>(transferChtoT(expression[0]));
		subTree->leftChild = CreatBinTree(++expression, subTree->leftChild);
		subTree->rightChild = CreatBinTree(++expression, subTree->rightChild);
		return subTree;
	}
	else
	{
		subTree->leftChild = NULL;
		subTree->rightChild = NULL;
	}
}

template <typename T>
void BinaryTree<T>::levelOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p))
{
	queue<BinTreeNode<T>*> myQueue;
	if (subTree != NULL)
		myQueue.push(subTree);
	while (!myQueue.empty())
	{
		BinTreeNode<T>* p = NULL;
		p = myQueue.front();
		myQueue.pop();
		visit(p);
		if (p->leftChild != NULL)
			myQueue.push(p->leftChild);
		if (p->rightChild != NULL)
			myQueue.push(p->rightChild);
	}
}

template <typename T>
void BinaryTree<T>::SwapTree(BinTreeNode<T>* subTree)
{
	if (subTree == NULL)
		return;
	if (subTree->leftChild == NULL&&subTree->rightChild == NULL)
		return;
	BinTreeNode<T>* temp = NULL;
	temp = subTree->leftChild;
	subTree->leftChild = subTree->rightChild;
	subTree->rightChild = temp;
	SwapTree(subTree->leftChild);
	SwapTree(subTree->rightChild);
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>::CreatBinTreeByVLRAndLVR(char* VLR, char* LVR, int n, BinTreeNode<T>* &subTree, bool& tag)
{
	if (n == 0)
		return NULL;
	int i = 0;
	while (VLR[0] != LVR[i])
	{
		i++;
		if (LVR[i] == '\0')
		{
			tag = false;
			return NULL;
		}
	}

	subTree = new BinTreeNode<T>(transferChtoT(VLR[0]));
	BinTreeNode<T>* temp = subTree;
	temp->leftChild = CreatBinTreeByVLRAndLVR(VLR + 1, LVR, i, temp->leftChild, tag);   			         //i***********
	temp->rightChild = CreatBinTreeByVLRAndLVR(VLR + i + 1, LVR + i + 1, n - i - 1, temp->rightChild, tag);  //*****i******  n-(k+1)
	return temp;
}

template <typename T>
T BinaryTree<T>::transferChtoT(char a)
{
	T result;
	stringstream stream;
	stream << a;
	stream >> result;
	return result;
}

template <typename T>
string BinaryTree<T>::transferTtoStr(T a)
{
	string result;
	stringstream stream;
	stream << a;
	stream >> result;
	return result;
}

template <typename T>
IandN BinaryTree<T>::GetIandN(BinTreeNode<T>* subTree)
{
	int I = 1;
	int N = 1;
	int H = Height();
	BinTreeNode<T>** NODE = NULL;
	NODE = new BinTreeNode<T>*[H];
	for (int l = 0; l < H; l++)
	{
		NODE[l] = NULL;
	}
	NODE[0] = subTree;
	for (int k = 1;; k++)
	{
		
		BinTreeNode<T>* parent = Parent(NODE[k - 1]);
		if (parent == NULL)
			break;
		else
		{
			N++;
			NODE[k] = Parent(NODE[k - 1]);
		}
	}
	for (int j = 0; j < N - 1; j++)	//左0右1 二进制计数法
	{
		if (NODE[j + 1]->leftChild == NODE[j])
			I += pow(2.0, j) * 0;
		if (NODE[j + 1]->rightChild == NODE[j])
			I += pow(2.0, j) * 1;
	}
	delete[] NODE;
	IandN result;
	result.ii = I;
	result.nn = N;
	return result;
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>::Find(T& item, string &result)
{
	BinTreeNode<T>* current = Find(root, item);
	while (current != NULL)
	{
		result += transferTtoStr(current->data);
		current = Parent(current);
	}
	return  Find(root, item);
}



