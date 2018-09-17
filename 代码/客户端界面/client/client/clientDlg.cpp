
// clientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "client.h"
#include "clientDlg.h"
#include "afxdialogex.h"





#ifdef _DEBUG
#define new DEBUG_NEW
#define REFRESHTIME 60   //更新动态口令时间
//#define MAXRANGE 100    //进度条最大范围
//#define STEP 1           //进度条步长
#endif

//int m_bSwitchBkgnd = 0;

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


// CclientDlg 对话框



CclientDlg::CclientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CclientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CclientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_static);
	//DDX_Control(pDX, IDC_GIF, m_picture);
	//DDX_Control(pDX, IDC_GIF, m_picture);
	//DDX_Control(pDX, IDC_BUTTON_CLOSE, m_btnClose);
	//DDX_Control(pDX, IDC_BUTTON_MIN, m_btnMin);
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_btnClose);
	//DDX_Control(pDX, IDC_PROGRESS1, m_ProCtrl);
	DDX_Control(pDX, IDC_PROGRESS2, m_progress);
	DDX_Control(pDX, IDC_SHOCKWAVEFLASH, flashshow);
}

BEGIN_MESSAGE_MAP(CclientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CclientDlg::OnNMCustomdrawProgress1)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
//	ON_WM_ERASEBKGND()
ON_WM_NCHITTEST()
ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CclientDlg::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// CclientDlg 消息处理程序

BOOL CclientDlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//m_bSwitchBkgnd = 1;
	//初始化动态口令字体，文本
	m_Font.CreatePointFont(300, "Arial", NULL);  
    m_static.SetFont(&m_Font,true);  
    m_static.SetWindowText("100");  

	//初始化时间条
	//nPos = 60;

	//CProgressCtrl *pProgCtrl=(CProgressCtrl*)GetDlgItem(IDC_PROGRESS2);
    //pProgCtrl->SetRange(0,60);//设置进度条范围
	//pProgCtrl->SetPos(60); // 设置进度条初始位置
	//pProgCtrl-> SetBarColor(RGB(0, 233, 233));
	//pProgCtrl->SetStep(-1); //设置进度条步长

	//m_progress.SetRange(0 , MAXRANGE); //设置进度条范围
	//m_progress.SetPos(MAXRANGE);       //设置进度条初始位置
	

	SetTimer(0,1000, NULL);//设置进度条更新时钟
	time = 0;
	i=0;

	//初始化笔刷
	 CString strBmpPath = _T(".\\res\\bkground1.jpg");  
    CImage img;  
    img.Load(strBmpPath); 
    MoveWindow(0, 0, img.GetWidth(), img.GetHeight());
    CBitmap bmpTmp;  
    bmpTmp.Attach(img.Detach());  
    m_brush.CreatePatternBrush(&bmpTmp);  

	//重塑对话框形状
	//CRgn rgnTmp;  
    RECT rc;  
    //GetClientRect(&rc);  
    //rgnTmp.CreateRoundRectRgn(rc.left + 30, rc.top + 30, rc.right - rc.left - 30, rc.bottom-rc.top -30, 20, 20);  
    //SetWindowRgn(rgnTmp, TRUE);  

	

//if (m_picture.Load(MAKEINTRESOURCE(IDR_GIF1),_T("gif")))//IDR_GIF1是添加的GIF动画的ID号。gif即是在添加时所键入的文件类型
//        m_picture.Draw();

	 //初始化关闭按钮

	//m_btnClose.SetImagePath(_T("./res/btnClose.png"),_T("./res/20170513234002_5ZQYf.png"));  
    //m_btnClose.InitMyButton(400,10,64,64,true); 

	//flash
	
//RECT rc; 
this->GetClientRect(&rc);//获得客户区的坐标 
//调整flash的位置 
rc.left=rc.right/2-158; 
rc.right=rc.right/2+158; 
rc.top+=404; 
rc.bottom=rc.bottom - 147; 
flashshow.MoveWindow( &rc, true ); 
TCHAR strCurDrt[500]; 
int nLen = ::GetCurrentDirectory(500,strCurDrt); 
if( strCurDrt[nLen]!='\\' ) 
{ 
strCurDrt[nLen++] = '\\'; 
strCurDrt[nLen] = '\0'; 
} 
CString strFileName = strCurDrt; 
strFileName += "PROGRESS.swf";//clock.swf是flash文件的名字，该flash文件放在工程目录下。 
flashshow.LoadMovie(0, strFileName); 
flashshow.Play(); 

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CclientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CclientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

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
HCURSOR CclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CclientDlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	
		*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CclientDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CProgressCtrl *pProgCtrl=(CProgressCtrl*)GetDlgItem(IDC_PROGRESS2);
	CStatic *textCtrl = (CStatic*)GetDlgItem(IDC_STATIC1);

	time++;
	i++;

	if(time == REFRESHTIME){
		time = 0;
		
		int testNum = 010101;
		
		CString str;
		str.Format("%d", i);

		//刷新动态口令
		//textCtrl->SetWindowTextA(str);
		//textCtrl->ShowWindow(SW_HIDE);
		//textCtrl->ShowWindow(SW_SHOW);
		ChgStaticText(textCtrl, str);

	}

	CDialogEx::OnTimer(nIDEvent);
}


HBRUSH CclientDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if(nCtlColor == CTLCOLOR_STATIC)
	{
		pDC -> SetTextColor(RGB(0,0,255)); //文字前景色
		pDC->SetBkMode(TRANSPARENT); //设置透明
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH); //获取画笔颜色混合后的画笔，完成透明

	}

	 if (pWnd == this )  
    {  
        return m_brush;  
    }  


	return hbr;

}


//BOOL CclientDlg::OnEraseBkgnd(CDC* pDC)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	/*CDialog::OnEraseBkgnd(pDC);
// HBITMAP   m_hBitmap;
// HDC           m_hBkDC;
//
// if(m_bSwitchBkgnd % 2 == 0)
//	   m_hBitmap   =   ::LoadBitmap(::GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_BITMAP3));
// else
//	  m_hBitmap   =   ::LoadBitmap(::GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_BITMAP2));
//
//	  m_hBkDC     =   ::CreateCompatibleDC(pDC-> m_hDC);
//
//	  if(m_hBitmap   &&   m_hBkDC)
// {
//  ::SelectObject(m_hBkDC,m_hBitmap);
//  ::StretchBlt(pDC-> m_hDC,0,0,1000,1050,m_hBkDC,0,0,1000,1050,SRCCOPY);
//  ::DeleteObject(m_hBitmap);
//  ::DeleteDC(m_hBkDC);
// }
//*/
//
//
// return TRUE;
//}


void CclientDlg::ChgStaticText(CStatic *cTxt, const CString sContect)
{
	cTxt->SetWindowText(sContect);  
    // 重绘 文本控件  
    CRect rect;  
    cTxt->GetWindowRect(&rect); // 只局部刷新  
    CWnd *pParent = cTxt->GetParent();  
    if (pParent)  
    {  
        pParent->ScreenToClient(&rect); // 把屏幕坐标转换为窗口坐标  
        pParent->InvalidateRect(&rect); // 更新矩形区域（重绘）  
    }  
}


LRESULT CclientDlg::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	 LRESULT ret = CDialogEx::OnNcHitTest(point);  
    return (ret == HTCLIENT) ? HTCAPTION : ret;  
}


void CclientDlg::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


//改变界面背景
//void CclientDlg::ChangeBK(void)
//{
	
//}


BOOL CclientDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialogEx::PreCreateWindow(cs);
}
