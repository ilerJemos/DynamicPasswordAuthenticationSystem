#pragma once
#include "afxwin.h"
class CMyButton :
	public CButton
{
public:
	CMyButton(void);
	~CMyButton(void);

	//��ť����ͼ��
	CImage m_imgButton;
	//��ťpng·��
	CString m_strImgPath;
	//�����ڱ���ͼƬ����·��
	CString m_strImgParentPath;
	void SetImagePath(CString strImgPath , CString strParentImgPath);
	bool InitMyButton(int nX , int nY , int nW , int nH , bool bIsPng);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
};

