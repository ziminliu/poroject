// Whac_a_moleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Whac_a_mole.h"
#include "Whac_a_moleDlg.h"

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
// CWhac_a_moleDlg dialog

CWhac_a_moleDlg::CWhac_a_moleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWhac_a_moleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWhac_a_moleDlg)
	m_nScore = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWhac_a_moleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWhac_a_moleDlg)
	DDX_Text(pDX, IDC_SCORE, m_nScore);
	DDV_MinMaxInt(pDX, m_nScore, 0, 999);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWhac_a_moleDlg, CDialog)
	//{{AFX_MSG_MAP(CWhac_a_moleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWhac_a_moleDlg message handlers

BOOL CWhac_a_moleDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWhac_a_moleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWhac_a_moleDlg::OnPaint() 
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
	/*文件加载图片
	CDialog::OnPaint();
		//CDialogEx::OnPaint();
		HBITMAP   hBitmap;
		hBitmap = (HBITMAP)::LoadImage(
			NULL,
			_T("rats.bmp"),                           // 图片路径（放到.cpp和.h的文件夹下） 
			IMAGE_BITMAP,                          // 图片格式  
			0, 0,
			LR_LOADFROMFILE | LR_CREATEDIBSECTION);  // 注意LR_LOADFROMFILE  IDC_BUTTON1
		*/

		//资源加载图片
		HBITMAP   hBitmap;   
		hBitmap = LoadBitmap(AfxGetInstanceHandle(),   
		MAKEINTRESOURCE(IDB_BITMAP1)); // IDB_BITMAP_TEST为资源图片ID  
		((CButton *)GetDlgItem(IDC_BUTTON1))->SetBitmap(hBitmap);

	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWhac_a_moleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWhac_a_moleDlg::OnButton() 
{
	// TODO: Add your control notification handler code here

}
