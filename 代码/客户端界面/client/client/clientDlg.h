
// clientDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "PictureEx.h"
#include <gdiplus.h>
#include "MyButton.h"
#include "MyProCtrl.h"
#include "afxcmn.h"
#include "Resource.h"
#include "shockwaveflash.h"

// CclientDlg 对话框
class CclientDlg : public CDialogEx
{
// 构造
public:
	CclientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

public:
	int nPos; //进度条当前位置

	CStatic m_static;

private:
	CFont m_Font;

	
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

public:
	
	void ChgStaticText(CStatic *cTxt, const CString sContect);

protected:
	CBrush m_brush;
	CBrush m_brush1;

public:
	//CPictureEx m_picture;
	afx_msg LRESULT OnNcHitTest(CPoint point);
	//CButton m_btnClose;
	//CButton m_btnMin;
	CMyButton m_btnClose;
	afx_msg void OnBnClickedButtonClose();
	//CMyProCtrl m_ProCtrl;

	
	//void ChangeBK(void);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	CMyProCtrl m_progress;
	CShockwaveflash flashshow;

	int time;
	int i;
};
