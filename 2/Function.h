#pragma once

#define RADIUS 13.0
#define Y_CORRECT 7

#include "stdafx.h"
#include "BinaryTree.h"

char* strToCh(string s);

char* CstrToCh(CString s);

template <typename T>
CString TtoCstr(T x);

template <typename T>
void PaintBinaryTree(BinaryTree<T> &Tree, CPaintDC &dc, CRect &Rect);

template <typename T>
CString TtoCstr(T x)
{
	stringstream stream;
	CString result;
	string temp;
	stream << x;
	stream >> temp;
	
	CA2T szr(temp.c_str());
	result = (LPCTSTR)szr;

	return result;
}

/*
template <typename T>
void PaintBinaryTree(BinaryTree<T> &Tree, CClientDC &dc, CRect &Rect)
{
	int H = Tree.Height();

	int Height = Rect.Height();
	int Width = Rect.Width();

	BinTreeNode<T>* subTree = Tree.getRoot();
	queue<BinTreeNode<T>*> myQueue;

	if (subTree == NULL)	//空树
	{
		CString temp = _T("#");
		dc.Ellipse(Width / 2.0 - RADIUS, Height / 2.0 - RADIUS, Width / 2.0 + RADIUS, Height / 2.0 + RADIUS);
		dc.TextOutW(Width / 2.0, Height / 2.0 - Y_CORRECT, temp);
		return;
	}
	else
		myQueue.push(subTree);

	while (!myQueue.empty())
	{
		BinTreeNode<T>* p = myQueue.front();
		myQueue.pop();

		//画出当前结点
		//非空节点
		if (p != NULL)
		{
			//获得当前结点在树种的相对位置层数n，从左到右的个数i
			int i = Tree.GetIandN(p).ii;
			int n = Tree.GetIandN(p).nn;

			//计算节点在屏幕中画出的坐标
			double x = (Width / (pow(2, n - 1) + 1))*i;
			double y = (Height / (H + 2))*n;

			dc.Ellipse(x - RADIUS, y - RADIUS, x + RADIUS, y + RADIUS);
			dc.SetTextAlign(TA_CENTER);
			dc.TextOutW(x, y - Y_CORRECT, TtoCstr(p->data));
			
			if (!(p->leftChild == NULL&&p->rightChild == NULL))
			{
				//画出连接左节点的线
				dc.MoveTo(x - sqrt(2.0)*0.5*RADIUS, y + sqrt(2.0)*0.5*RADIUS);
				int xNextL = (Width / (pow(2, n) + 1))*(2 * i - 1);
				int yNextL = (Height / (H + 2))*(n + 1);
				dc.LineTo(xNextL + sqrt(2.0)*0.5*RADIUS, yNextL - sqrt(2.0)*0.5*RADIUS);

				//画出连接右节点的线
				dc.MoveTo(x + sqrt(2.0)*0.5*RADIUS, y + sqrt(2.0)*0.5*RADIUS);
				int xNextR = (Width / (pow(2, n) + 1))*(2 * i);
				int yNextR = (Height / (H + 2))*(n + 1);
				dc.LineTo(xNextR - sqrt(2.0)*0.5*RADIUS, yNextR - sqrt(2.0)*0.5*RADIUS);
			}

		}
	
		//画当前结点子女节点中的空节点
		if (p != NULL)
		{
			if (p->leftChild == NULL)
			{
				int i = Tree.GetIandN(p).ii;
				int n = Tree.GetIandN(p).nn;
				double temp_x = (Width / (pow(2, n) + 1))*(2 * i - 1);	//空节点的坐标
				double temp_y = (Height / (H + 2))*(n + 1);
				double x = (Width / (pow(2, n - 1) + 1))*i;		//空节点父节点的坐标
				double y = (Height / (H + 2))*n;

				//画出连接左节点的线
				dc.MoveTo(x - sqrt(2.0)*0.5*RADIUS, y + sqrt(2.0)*0.5*RADIUS);
				int xNextL = (Width / (pow(2, n) + 1))*(2 * i - 1);
				int yNextL = (Height / (H + 2))*(n + 1);
				dc.LineTo(xNextL + sqrt(2.0)*0.5*RADIUS, yNextL - sqrt(2.0)*0.5*RADIUS);

				CString temp = _T("#");
				dc.Ellipse(temp_x - RADIUS, temp_y - RADIUS, temp_x + RADIUS, temp_y + RADIUS);
				dc.SetTextAlign(TA_CENTER);
				dc.TextOutW(temp_x, temp_y - Y_CORRECT, temp);
			}
			else
			{
				myQueue.push(p->leftChild);
			}

			if (p->rightChild == NULL)
			{
				int i = Tree.GetIandN(p).ii;
				int n = Tree.GetIandN(p).nn;
				double temp_x = (Width / (pow(2, n) + 1))*(2 * i);//空节点的坐标
				double temp_y = (Height / (H + 2))*(n + 1);
				double x = (Width / (pow(2, n - 1) + 1))*i;		//空节点父节点的坐标
				double y = (Height / (H + 2))*n;

				//画出连接右节点的线
				dc.MoveTo(x + sqrt(2.0)*0.5*RADIUS, y + sqrt(2.0)*0.5*RADIUS);
				int xNextR = (Width / (pow(2, n) + 1))*(2 * i);
				int yNextR = (Height / (H + 2))*(n + 1);
				dc.LineTo(xNextR - sqrt(2.0)*0.5*RADIUS, yNextR - sqrt(2.0)*0.5*RADIUS);

				CString temp = _T("#");
				dc.Ellipse(temp_x - RADIUS, temp_y - RADIUS, temp_x + RADIUS, temp_y + RADIUS);
				dc.SetTextAlign(TA_CENTER);
				dc.TextOutW(temp_x, temp_y - Y_CORRECT, temp);
			}
			else
			{
				myQueue.push(p->rightChild);
			}
		}
	}
}
*/

template <typename T>
void PaintBinaryTree(BinaryTree<T> &Tree, CClientDC &dc, CRect &Rect)
{
	int H = Tree.Height();

	int Height = Rect.Height();
	int Width = Rect.Width();

	BinTreeNode<T>* subTree = Tree.getRoot();
	queue<BinTreeNode<T>*> myQueue;

	if (subTree == NULL)	//空树
	{
		CString temp = _T("#");
		dc.Ellipse(Width / 2.0 - RADIUS, Height / 2.0 - RADIUS, Width / 2.0 + RADIUS, Height / 2.0 + RADIUS);
		dc.TextOutW(Width / 2.0, Height / 2.0 - Y_CORRECT, temp);
		return;
	}
	else
		myQueue.push(subTree);

	while (!myQueue.empty())
	{
		BinTreeNode<T>* p = myQueue.front();
		myQueue.pop();

		//画出当前结点
		//非空节点
		if (p != NULL)
		{
			//获得当前结点在树种的相对位置层数n，从左到右的个数i
			int i = Tree.GetIandN(p).ii;
			int n = Tree.GetIandN(p).nn;

			//计算节点在屏幕中画出的坐标
			double x = (Width / (2 * pow(2, n - 1)))*(2 * i - 1);	/////////////////////
			double y = (Height / (H + 2))*n;

			dc.Ellipse(x - RADIUS, y - RADIUS, x + RADIUS, y + RADIUS);
			dc.SetTextAlign(TA_CENTER);
			dc.TextOutW(x, y - Y_CORRECT, TtoCstr(p->data));

			if (!(p->leftChild == NULL&&p->rightChild == NULL))
			{
				//画出连接左节点的线
				dc.MoveTo(x - sqrt(2.0)*0.5*RADIUS, y + sqrt(2.0)*0.5*RADIUS);
				int xNextL = (Width / (2 * pow(2, n)))*(4 * i - 3);
				int yNextL = (Height / (H + 2))*(n + 1);
				dc.LineTo(xNextL + sqrt(2.0)*0.5*RADIUS, yNextL - sqrt(2.0)*0.5*RADIUS);

				//画出连接右节点的线
				dc.MoveTo(x + sqrt(2.0)*0.5*RADIUS, y + sqrt(2.0)*0.5*RADIUS);
				int xNextR = (Width / (2 * pow(2, n)))*(4 * i - 1);
				int yNextR = (Height / (H + 2))*(n + 1);
				dc.LineTo(xNextR - sqrt(2.0)*0.5*RADIUS, yNextR - sqrt(2.0)*0.5*RADIUS);
			}

		}

		//画当前结点子女节点中的空节点
		if (p != NULL)
		{
			if (p->leftChild == NULL)
			{
				int i = Tree.GetIandN(p).ii;
				int n = Tree.GetIandN(p).nn;
				double temp_x = (Width / (2 * pow(2, n)))*(4 * i - 3);	//空节点的坐标
				double temp_y = (Height / (H + 2))*(n + 1);
				double x = (Width / (2 * pow(2, n - 1)))*(2 * i - 1);	//空节点父节点的坐标
				double y = (Height / (H + 2))*n;

				//画出连接左节点的线
				dc.MoveTo(x - sqrt(2.0)*0.5*RADIUS, y + sqrt(2.0)*0.5*RADIUS);
				int xNextL = (Width / (2 * pow(2, n)))*(4 * i - 3);
				int yNextL = (Height / (H + 2))*(n + 1);
				dc.LineTo(xNextL + sqrt(2.0)*0.5*RADIUS, yNextL - sqrt(2.0)*0.5*RADIUS);

				CString temp = _T("#");
				dc.Ellipse(temp_x - RADIUS, temp_y - RADIUS, temp_x + RADIUS, temp_y + RADIUS);
				dc.SetTextAlign(TA_CENTER);
				dc.TextOutW(temp_x, temp_y - Y_CORRECT, temp);
			}
			else
			{
				myQueue.push(p->leftChild);
			}

			if (p->rightChild == NULL)
			{
				int i = Tree.GetIandN(p).ii;
				int n = Tree.GetIandN(p).nn;
				double temp_x = (Width / (2 * pow(2, n)))*(4 * i - 1);//空节点的坐标
				double temp_y = (Height / (H + 2))*(n + 1);
				double x = (Width / (2 * pow(2, n - 1)))*(2 * i - 1);	//空节点父节点的坐标
				double y = (Height / (H + 2))*n;

				//画出连接右节点的线
				dc.MoveTo(x + sqrt(2.0)*0.5*RADIUS, y + sqrt(2.0)*0.5*RADIUS);
				int xNextR = (Width / (2 * pow(2, n)))*(4 * i - 1);
				int yNextR = (Height / (H + 2))*(n + 1);
				dc.LineTo(xNextR - sqrt(2.0)*0.5*RADIUS, yNextR - sqrt(2.0)*0.5*RADIUS);

				CString temp = _T("#");
				dc.Ellipse(temp_x - RADIUS, temp_y - RADIUS, temp_x + RADIUS, temp_y + RADIUS);
				dc.SetTextAlign(TA_CENTER);
				dc.TextOutW(temp_x, temp_y - Y_CORRECT, temp);
			}
			else
			{
				myQueue.push(p->rightChild);
			}
		}
	}
}
