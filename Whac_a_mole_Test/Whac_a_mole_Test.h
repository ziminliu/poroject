// Whac_a_mole_Test.h : main header file for the WHAC_A_MOLE_TEST application
//

#if !defined(AFX_WHAC_A_MOLE_TEST_H__EDD466C4_73A4_440C_878B_A45D92DD3620__INCLUDED_)
#define AFX_WHAC_A_MOLE_TEST_H__EDD466C4_73A4_440C_878B_A45D92DD3620__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWhac_a_mole_TestApp:
// See Whac_a_mole_Test.cpp for the implementation of this class
//

class CWhac_a_mole_TestApp : public CWinApp
{
public:
	CWhac_a_mole_TestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWhac_a_mole_TestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWhac_a_mole_TestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WHAC_A_MOLE_TEST_H__EDD466C4_73A4_440C_878B_A45D92DD3620__INCLUDED_)
