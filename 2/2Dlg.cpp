
// 2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "2.h"
#include "2Dlg.h"
#include "afxdialogex.h"
#include "BinaryTree.h"
#include "Function.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy2Dlg �Ի���



CMy2Dlg::CMy2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32772, &CMy2Dlg::On32772)
	ON_COMMAND(ID_32773, &CMy2Dlg::On32773)
	ON_COMMAND(ID_32774, &CMy2Dlg::On32774)
END_MESSAGE_MAP()


// CMy2Dlg ��Ϣ�������

BOOL CMy2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	MessageBox(_T("������ϽǵĹ��ܲ˵����ɲ���������\n�ڵ���֮ǰ�뱣֤�����ǰ�����к����������ǺϷ��ģ�\n����ʾһ��������֮ǰ����������"), _T("��ʾ"), MB_OK);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CClientDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy2Dlg::On32772()	//����
{
	// TODO:  �ڴ���������������

	CClientDC dc(this);
	CRect Rect;
	GetClientRect(Rect);

	if (myTree_char.getRoot() != NULL)
	{
		PaintBinaryTree(myTree_char, dc, Rect);
	}
	else if (myTree_int.getRoot() != NULL)
	{
		PaintBinaryTree(myTree_int, dc, Rect);
	}
	else
	{
		MessageBox(_T("�㻹û��������"), _T("��ʾ"), MB_OK);
	}

}


void CMy2Dlg::On32773()	//����
{
	// TODO:  �ڴ���������������
	InvalidateRect(NULL, true);
	MessageBox(_T("�����ɹ�"), _T("��ʾ"), MB_OK);
}


void CMy2Dlg::On32774()
{
	// TODO:  �ڴ���������������
	if (myTree_char.getRoot() == NULL&&myTree_int.getRoot() == NULL)
	{
		MessageBox(_T("�㻹û��������"), _T("��ʾ"), MB_OK);
		return;
	}

	myTree_int.SwapTree();
	myTree_char.SwapTree();
	MessageBox(_T("�����ɹ�"), _T("��ʾ"), MB_OK);
}
