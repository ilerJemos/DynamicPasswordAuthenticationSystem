#include "stdafx.h"
#include "MyProCtrl.h"


CMyProCtrl::CMyProCtrl(void)
{
	m_ColText=RGB( 255, 0, 0);//�ı���ɫ
    //m_ColProgress=RGB( 255, 255, 255);//��������ɫ
    m_ColBlank=RGB( 255, 192, 192);//�հ�������ɫ

	//����λͼ����  
    CBitmap bitmap;  
    //����λͼ��Դ  
	bitmap.LoadBitmap(IDB_BITMAP2);  
    //����λͼ��ˢ
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

	// TODO: �ڴ˴������Ϣ����������
	PAINTSTRUCT ps;//����һ���滭����
   CDC *pDC=BeginPaint(&ps);//�ѻ滭����ѡ���豸�����Ĳ���ʼ
int AdrPos=GetPos();//��ȡ�������Ľ���λ��
CString StrPos;//�����ַ�����������ʾ�������Ľ���
StrPos.Format ("%d%%",AdrPos);//�ѽ���λ�ø��Ƶ�StrPos
CRect ClientRC;
GetClientRect(&ClientRC);//��ȡ�ͻ�������
CSize CsText=pDC->GetTextExtent (StrPos);//��ȡ��ʾStrPos�Ĺ�ģ��С
int nX=(ClientRC.Width ()-CsText.cx )/2;//��ȡ��ʾ�ַ�����X
int nY=(ClientRC.Height ()-CsText.cy )/2;//��ȡ��ʾ�ַ�����Y
pDC->SetBkMode (TRANSPARENT);//���ñ���ģʽΪ͸��
int nMin,nMax;//�����������������С����
GetRange(nMin,nMax);//��ȡ����
double Every=(double)ClientRC.Width ()/(nMax-nMin);//��ȡ��λ�̶�
int Now=Every*AdrPos;//��ǰ����
CRect LeftRC,RightRC;//��������������Ϳհ�����
LeftRC=RightRC=ClientRC;
LeftRC.right =Now;//����������
RightRC.left =Now;//�հ�����
pDC->FillRect (LeftRC, &brush);//����������     
pDC->FillRect (RightRC,&(CBrush)m_ColBlank);//���հ�����
pDC->SetTextColor (m_ColText);//�����ı���ɫ
pDC->TextOutA (nX,nY,StrPos);//д�ı�
ReleaseDC(pDC);//�����豸������
EndPaint(&ps);//�����滭����滭
		// ��Ϊ��ͼ��Ϣ���� CProgressCtrl::OnPaint()
}
