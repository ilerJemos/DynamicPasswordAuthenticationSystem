#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "PictureEx.h"
#include <gdiplus.h>
#include "MyButton.h"
#include "MyProCtrl.h"
#include "Resource.h"

class CMyProCtrl :
	public CProgressCtrl
{
public:
	CMyProCtrl(void);
	~CMyProCtrl(void);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

	
COLORREF m_ColProgress;//进度条颜色
COLORREF m_ColBlank;//空白区域颜色
COLORREF m_ColText;//文本颜色

CBrush brush;
};

