#pragma once
#include "afxwin.h"


// CLeadIn �Ի���

class CLeadIn : public CDialogEx
{
	DECLARE_DYNAMIC(CLeadIn)

public:
	CLeadIn(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLeadIn();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CComboBox SelBox;
	CString CS_VLR;
	CString CS_LVR;
protected:
//	afx_msg LRESULT OnLeadinMessage(WPARAM wParam, LPARAM lParam);
//	afx_msg LRESULT OnMainMessage(WPARAM wParam, LPARAM lParam);
};
