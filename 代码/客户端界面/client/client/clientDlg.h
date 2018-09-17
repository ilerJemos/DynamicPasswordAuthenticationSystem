
// clientDlg.h : ͷ�ļ�
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

// CclientDlg �Ի���
class CclientDlg : public CDialogEx
{
// ����
public:
	CclientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

public:
	int nPos; //��������ǰλ��

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
