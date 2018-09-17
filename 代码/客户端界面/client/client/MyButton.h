#pragma once
#include "afxwin.h"
class CMyButton :
	public CButton
{
public:
	CMyButton(void);
	~CMyButton(void);

	//°´Å¥±³¾°Í¼Ïñ
	CImage m_imgButton;
	//°´Å¥pngÂ·¾¶
	CString m_strImgPath;
	//¸¸´°¿Ú±³¾°Í¼Æ¬±³¾°Â·¾¶
	CString m_strImgParentPath;
	void SetImagePath(CString strImgPath , CString strParentImgPath);
	bool InitMyButton(int nX , int nY , int nW , int nH , bool bIsPng);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
};

