// LeadIn.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "2.h"
#include "LeadIn.h"
#include "afxdialogex.h"
#include "BinaryTree.h"
#include "Function.h"


// CLeadIn �Ի���


IMPLEMENT_DYNAMIC(CLeadIn, CDialogEx)

CLeadIn::CLeadIn(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLeadIn::IDD, pParent)
	, CS_VLR(_T(""))
	, CS_LVR(_T(""))
{
	
}

CLeadIn::~CLeadIn()
{
}

void CLeadIn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, SelBox);

	DDX_Text(pDX, IDC_EDIT3, CS_VLR);
	DDX_Text(pDX, IDC_EDIT4, CS_LVR);
}


BEGIN_MESSAGE_MAP(CLeadIn, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLeadIn::OnBnClickedButton1)
//	ON_MESSAGE(Leadin_Message, &CLeadIn::OnLeadinMessage)
//	ON_MESSAGE(Main_Message, &CLeadIn::OnMainMessage)
END_MESSAGE_MAP()


// CLeadIn ��Ϣ�������


void CLeadIn::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);

	if (CS_VLR.GetLength() != CS_LVR.GetLength())
	{
		MessageBox(_T("���г��Ȳ�һ��"), _T("����"), MB_OK);
		return;
	}
	if (SelBox.GetCurSel() == CB_ERR)
	{
		MessageBox(_T("δѡ������"), _T("����"), MB_OK);
		return;
	}
	

	int n = CS_VLR.GetLength();
	char* ch_VLR = CstrToCh(CS_VLR);
	char* ch_LVR = CstrToCh(CS_LVR);
	int index = SelBox.GetCurSel();

	//�������������Ƿ�Ϊ��ϴ�
	bool isChar = false, isInt = false, tagChar = true,tagInt=true;
	for (int i = 0; i < CS_VLR.GetLength(); i++)
	{
		if (ch_VLR[i]<65 || (ch_VLR[i]>90) && (ch_VLR[i]<97) || ch_VLR[i]>122)
		{
			tagChar = false;
			break;
		}
		if (ch_LVR[i]<65 || (ch_LVR[i]>90) && (ch_LVR[i]<97) || ch_LVR[i]>122)
		{
			tagChar = false;
			break;
		}
	}
	for (int i = 0; i < CS_VLR.GetLength(); i++)
	{
		if (ch_VLR[i] < 48 || ch_VLR[i] > 57)
		{
			tagInt = false;
			break;
		}
		if (ch_LVR[i] < 48 || ch_LVR[i] > 57)
		{
			tagInt = false;
			break;
		}
	}

	if (tagChar)
		isChar = true;
	if (tagInt)
		isInt = true;

	bool tag;

	if (index == 0)		//char
	{
		if (isChar == false)
		{
			MessageBox(_T("���������,�������������Ͳ�ƥ�䣡"), _T("����", MB_OK));
			return;
		}
		else
		{
			myTree_char.CreatBinTreeByVLRAndLVR(ch_VLR, ch_LVR, n, tag);
			if (!tag)
			{
				MessageBox(_T("���������,�������������Ͳ�ƥ�䣡"), _T("����", MB_OK));
				myTree_char.Clear();
				return;
			}
			else
			{
				myTree_int.Clear();
				CLeadIn::OnCancel();
			}
		}
	}
	else if (index == 1)	//int
	{
		if (isInt == false)
		{
			MessageBox(_T("���������,�������������Ͳ�ƥ�䣡"), _T("����", MB_OK));
			return;
		}
		else
		{
			myTree_int.CreatBinTreeByVLRAndLVR(ch_VLR, ch_LVR, n, tag);
			if (!tag)
			{
				MessageBox(_T("���������,�������������Ͳ�ƥ�䣡"), _T("����", MB_OK));
				myTree_int.Clear();
				return;
			}
			else
			{
				myTree_char.Clear();
				CLeadIn::OnCancel();
			}
		}
	}
	MessageBox(_T("�����ɹ���"), _T("��ʾ"), MB_OK);
	UpdateData(false);
}
