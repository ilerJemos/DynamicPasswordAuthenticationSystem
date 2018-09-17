
// clientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "client.h"
#include "clientDlg.h"
#include "afxdialogex.h"





#ifdef _DEBUG
#define new DEBUG_NEW
#define REFRESHTIME 60   //���¶�̬����ʱ��
//#define MAXRANGE 100    //���������Χ
//#define STEP 1           //����������
#endif

//int m_bSwitchBkgnd = 0;

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


// CclientDlg �Ի���



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


// CclientDlg ��Ϣ�������

BOOL CclientDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//m_bSwitchBkgnd = 1;
	//��ʼ����̬�������壬�ı�
	m_Font.CreatePointFont(300, "Arial", NULL);  
    m_static.SetFont(&m_Font,true);  
    m_static.SetWindowText("100");  

	//��ʼ��ʱ����
	//nPos = 60;

	//CProgressCtrl *pProgCtrl=(CProgressCtrl*)GetDlgItem(IDC_PROGRESS2);
    //pProgCtrl->SetRange(0,60);//���ý�������Χ
	//pProgCtrl->SetPos(60); // ���ý�������ʼλ��
	//pProgCtrl-> SetBarColor(RGB(0, 233, 233));
	//pProgCtrl->SetStep(-1); //���ý���������

	//m_progress.SetRange(0 , MAXRANGE); //���ý�������Χ
	//m_progress.SetPos(MAXRANGE);       //���ý�������ʼλ��
	

	SetTimer(0,1000, NULL);//���ý���������ʱ��
	time = 0;
	i=0;

	//��ʼ����ˢ
	 CString strBmpPath = _T(".\\res\\bkground1.jpg");  
    CImage img;  
    img.Load(strBmpPath); 
    MoveWindow(0, 0, img.GetWidth(), img.GetHeight());
    CBitmap bmpTmp;  
    bmpTmp.Attach(img.Detach());  
    m_brush.CreatePatternBrush(&bmpTmp);  

	//���ܶԻ�����״
	//CRgn rgnTmp;  
    RECT rc;  
    //GetClientRect(&rc);  
    //rgnTmp.CreateRoundRectRgn(rc.left + 30, rc.top + 30, rc.right - rc.left - 30, rc.bottom-rc.top -30, 20, 20);  
    //SetWindowRgn(rgnTmp, TRUE);  

	

//if (m_picture.Load(MAKEINTRESOURCE(IDR_GIF1),_T("gif")))//IDR_GIF1����ӵ�GIF������ID�š�gif���������ʱ��������ļ�����
//        m_picture.Draw();

	 //��ʼ���رհ�ť

	//m_btnClose.SetImagePath(_T("./res/btnClose.png"),_T("./res/20170513234002_5ZQYf.png"));  
    //m_btnClose.InitMyButton(400,10,64,64,true); 

	//flash
	
//RECT rc; 
this->GetClientRect(&rc);//��ÿͻ��������� 
//����flash��λ�� 
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
strFileName += "PROGRESS.swf";//clock.swf��flash�ļ������֣���flash�ļ����ڹ���Ŀ¼�¡� 
flashshow.LoadMovie(0, strFileName); 
flashshow.Play(); 

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CclientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

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
HCURSOR CclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CclientDlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	
		*pResult = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CclientDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CProgressCtrl *pProgCtrl=(CProgressCtrl*)GetDlgItem(IDC_PROGRESS2);
	CStatic *textCtrl = (CStatic*)GetDlgItem(IDC_STATIC1);

	time++;
	i++;

	if(time == REFRESHTIME){
		time = 0;
		
		int testNum = 010101;
		
		CString str;
		str.Format("%d", i);

		//ˢ�¶�̬����
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

	// TODO:  �ڴ˸��� DC ���κ�����
	if(nCtlColor == CTLCOLOR_STATIC)
	{
		pDC -> SetTextColor(RGB(0,0,255)); //����ǰ��ɫ
		pDC->SetBkMode(TRANSPARENT); //����͸��
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH); //��ȡ������ɫ��Ϻ�Ļ��ʣ����͸��

	}

	 if (pWnd == this )  
    {  
        return m_brush;  
    }  


	return hbr;

}


//BOOL CclientDlg::OnEraseBkgnd(CDC* pDC)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
    // �ػ� �ı��ؼ�  
    CRect rect;  
    cTxt->GetWindowRect(&rect); // ֻ�ֲ�ˢ��  
    CWnd *pParent = cTxt->GetParent();  
    if (pParent)  
    {  
        pParent->ScreenToClient(&rect); // ����Ļ����ת��Ϊ��������  
        pParent->InvalidateRect(&rect); // ���¾��������ػ棩  
    }  
}


LRESULT CclientDlg::OnNcHitTest(CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	 LRESULT ret = CDialogEx::OnNcHitTest(point);  
    return (ret == HTCLIENT) ? HTCAPTION : ret;  
}


void CclientDlg::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


//�ı���汳��
//void CclientDlg::ChangeBK(void)
//{
	
//}


BOOL CclientDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CDialogEx::PreCreateWindow(cs);
}
