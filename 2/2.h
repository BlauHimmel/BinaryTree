
// 2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif


#include "resource.h"		// ������

// CMy2App: 
// �йش����ʵ�֣������ 2.cpp
//

class CMy2App : public CWinApp
{
public:
	CMy2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	afx_msg void On32771();
	afx_msg void On32773();
	afx_msg void On32774();
};

extern CMy2App theApp;