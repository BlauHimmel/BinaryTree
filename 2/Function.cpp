#include "stdafx.h"
#include "Function.h"
#include "BinaryTree.h"

char* strToCh(string s)
{
	char* result = new char[s.length() + 1];
	for (int i = 0; i < s.length(); i++)
	{
		result[i] = s[i];
	}
	result[s.length()] = '\0';
	return result;
}

char* CstrToCh(CString s)
{
	char* result = new char[s.GetLength() + 1];
	for (int i = 0; i < s.GetLength(); i++)
	{
		result[i] = s[i];
	}
	result[s.GetLength()] = '\0';
	return result;
}


