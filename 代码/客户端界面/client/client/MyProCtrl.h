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

	
COLORREF m_ColProgress;//��������ɫ
COLORREF m_ColBlank;//�հ�������ɫ
COLORREF m_ColText;//�ı���ɫ

CBrush brush;
};

