// Whac_a_mole_TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Whac_a_mole_Test.h"
#include "Whac_a_mole_TestDlg.h"
#include "String.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWhac_a_mole_TestDlg dialog

CWhac_a_mole_TestDlg::CWhac_a_mole_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWhac_a_mole_TestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWhac_a_mole_TestDlg)
	m_nScore = 0;
	m_Level = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWhac_a_mole_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWhac_a_mole_TestDlg)
	DDX_Control(pDX, IDC_PROGRESS, m_time);
	DDX_Control(pDX, IDC_COMBO1, m_ComLevel);
	DDX_Text(pDX, IDC_SCORE, m_nScore);
	DDV_MinMaxInt(pDX, m_nScore, 0, 999);
	DDX_CBString(pDX, IDC_COMBO1, m_Level);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWhac_a_mole_TestDlg, CDialog)
	//{{AFX_MSG_MAP(CWhac_a_mole_TestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton)
	ON_BN_CLICKED(IDC_OVER, OnOver)
	ON_BN_CLICKED(IDC_STAR, OnStar)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWhac_a_mole_TestDlg message handlers

BOOL CWhac_a_mole_TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ComLevel.InsertString(0,"简单");
	m_ComLevel.InsertString(1,"中等");
	m_ComLevel.InsertString(2,"困难");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWhac_a_mole_TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWhac_a_mole_TestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWhac_a_mole_TestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWhac_a_mole_TestDlg::OnButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_nScore++;
	UpdateData(FALSE);
}

void CWhac_a_mole_TestDlg::OnOver() 
{
	// TODO: Add your control notification handler code here	
	KillTimer(1);
	m_time.SetPos(0);
	CString prompt;
	prompt.Format("你的得分是：  %d",m_nScore);
	m_nScore=0;
	MessageBox(prompt);
	m_time.SetPos(0);
	KillTimer(1);
}

void CWhac_a_mole_TestDlg::OnStar() 
{
	if(m_ComLevel.GetCurSel()==CB_ERR){
		MessageBox("请选择游戏难度");
		return ;
	}
	else{
	UpdateData();
	m_nScore=0;
	int index=m_ComLevel.GetCurSel();
	switch (index){
	case 0:
		MessageBox("简单");
		break;
	case 1:
		MessageBox("中等");
		break;
	case 2:
		MessageBox("困难");
		break;
	default:
		MessageBox("请选择游戏难度");
	}
	// TODO: Add your control notification handler code here
	m_time.SetRange(0,59); //设置进展条时间范围59秒
	LeftTime=59;
	SetTimer(1,200,NULL); //启动计时器
	}

}

void CWhac_a_mole_TestDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(FALSE);
	LeftTime-=1;
	m_time.SetPos(LeftTime);
	if(LeftTime==0)
		OnOver();
	CDialog::OnTimer(nIDEvent);
}
