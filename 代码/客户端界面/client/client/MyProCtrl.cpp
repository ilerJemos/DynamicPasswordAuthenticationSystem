#include "stdafx.h"
#include "MyProCtrl.h"


CMyProCtrl::CMyProCtrl(void)
{
	m_ColText=RGB( 255, 0, 0);//文本颜色
    //m_ColProgress=RGB( 255, 255, 255);//进度条颜色
    m_ColBlank=RGB( 255, 192, 192);//空白区域颜色

	//创建位图对象  
    CBitmap bitmap;  
    //加载位图资源  
	bitmap.LoadBitmap(IDB_BITMAP2);  
    //创建位图画刷
	brush.CreatePatternBrush(&bitmap);  
	
	
}


CMyProCtrl::~CMyProCtrl(void)
{
}
BEGIN_MESSAGE_MAP(CMyProCtrl, CProgressCtrl)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CMyProCtrl::OnPaint()
{
	//CPaintDC dc(this); // device context for painting

	// TODO: 在此处添加消息处理程序代码
	PAINTSTRUCT ps;//声明一个绘画区域
   CDC *pDC=BeginPaint(&ps);//把绘画区域选入设备上下文并开始
int AdrPos=GetPos();//获取进度条的进度位置
CString StrPos;//声明字符串，用于显示进度条的进度
StrPos.Format ("%d%%",AdrPos);//把进度位置复制到StrPos
CRect ClientRC;
GetClientRect(&ClientRC);//获取客户区矩形
CSize CsText=pDC->GetTextExtent (StrPos);//获取显示StrPos的规模大小
int nX=(ClientRC.Width ()-CsText.cx )/2;//获取显示字符串的X
int nY=(ClientRC.Height ()-CsText.cy )/2;//获取显示字符串的Y
pDC->SetBkMode (TRANSPARENT);//设置背景模式为透明
int nMin,nMax;//声明进度条的最大最小限制
GetRange(nMin,nMax);//获取限制
double Every=(double)ClientRC.Width ()/(nMax-nMin);//获取单位刻度
int Now=Every*AdrPos;//当前长度
CRect LeftRC,RightRC;//声明进度条区域和空白区域
LeftRC=RightRC=ClientRC;
LeftRC.right =Now;//进度条区域
RightRC.left =Now;//空白区域
pDC->FillRect (LeftRC, &brush);//画进度条区     
pDC->FillRect (RightRC,&(CBrush)m_ColBlank);//画空白区域
pDC->SetTextColor (m_ColText);//设置文本颜色
pDC->TextOutA (nX,nY,StrPos);//写文本
ReleaseDC(pDC);//销毁设备上下文
EndPaint(&ps);//结束绘画区域绘画
		// 不为绘图消息调用 CProgressCtrl::OnPaint()
}
