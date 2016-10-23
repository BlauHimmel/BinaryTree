
// 2Dlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMy2Dlg 对话框



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


// CMy2Dlg 消息处理程序

BOOL CMy2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	MessageBox(_T("点击左上角的功能菜单即可操作本程序！\n在导入之前请保证输入和前序序列和中序序列是合法的！\n在显示一个二叉树之前请先清屏！"), _T("提示"), MB_OK);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CClientDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy2Dlg::On32772()	//绘制
{
	// TODO:  在此添加命令处理程序代码

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
		MessageBox(_T("你还没导入树！"), _T("提示"), MB_OK);
	}

}


void CMy2Dlg::On32773()	//清屏
{
	// TODO:  在此添加命令处理程序代码
	InvalidateRect(NULL, true);
	MessageBox(_T("清屏成功"), _T("提示"), MB_OK);
}


void CMy2Dlg::On32774()
{
	// TODO:  在此添加命令处理程序代码
	if (myTree_char.getRoot() == NULL&&myTree_int.getRoot() == NULL)
	{
		MessageBox(_T("你还没导入树！"), _T("提示"), MB_OK);
		return;
	}

	myTree_int.SwapTree();
	myTree_char.SwapTree();
	MessageBox(_T("交换成功"), _T("提示"), MB_OK);
}
