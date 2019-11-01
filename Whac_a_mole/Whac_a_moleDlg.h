// Whac_a_moleDlg.h : header file
//

#if !defined(AFX_WHAC_A_MOLEDLG_H__9EC5B8CC_C31D_46EF_97C3_B990129720CD__INCLUDED_)
#define AFX_WHAC_A_MOLEDLG_H__9EC5B8CC_C31D_46EF_97C3_B990129720CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWhac_a_moleDlg dialog

class CWhac_a_moleDlg : public CDialog
{
// Construction
public:
	CWhac_a_moleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWhac_a_moleDlg)
	enum { IDD = IDD_WHAC_A_MOLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWhac_a_moleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWhac_a_moleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WHAC_A_MOLEDLG_H__9EC5B8CC_C31D_46EF_97C3_B990129720CD__INCLUDED_)
