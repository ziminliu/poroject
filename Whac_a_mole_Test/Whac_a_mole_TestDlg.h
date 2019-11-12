// Whac_a_mole_TestDlg.h : header file
//

#if !defined(AFX_WHAC_A_MOLE_TESTDLG_H__FFE5266D_F89D_4204_A067_692CD6ACF787__INCLUDED_)
#define AFX_WHAC_A_MOLE_TESTDLG_H__FFE5266D_F89D_4204_A067_692CD6ACF787__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWhac_a_mole_TestDlg dialog

class CWhac_a_mole_TestDlg : public CDialog
{
// Construction
public:
	HCURSOR m_hCursor;
	void ShowButton();
	CButton* button[9];
	int LeftTime;
	CWhac_a_mole_TestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWhac_a_mole_TestDlg)
	enum { IDD = IDD_WHAC_A_MOLE_TEST_DIALOG };
	CButton	m_Button9;
	CButton	m_Button8;
	CButton	m_Button7;
	CButton	m_Button6;
	CButton	m_Button5;
	CButton	m_Button4;
	CButton	m_Button3;
	CButton	m_Button2;
	CButton	m_Button1;
	CProgressCtrl	m_time;
	CComboBox	m_ComLevel;
	int		m_nScore;
	CString	m_Level;
	int		m_lTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWhac_a_mole_TestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWhac_a_mole_TestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton();
	afx_msg void OnOver();
	afx_msg void OnStar();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WHAC_A_MOLE_TESTDLG_H__FFE5266D_F89D_4204_A067_692CD6ACF787__INCLUDED_)
