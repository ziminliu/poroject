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
	m_lTime = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWhac_a_mole_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWhac_a_mole_TestDlg)
	DDX_Control(pDX, IDC_BUTTON9, m_Button9);
	DDX_Control(pDX, IDC_BUTTON8, m_Button8);
	DDX_Control(pDX, IDC_BUTTON7, m_Button7);
	DDX_Control(pDX, IDC_BUTTON6, m_Button6);
	DDX_Control(pDX, IDC_BUTTON5, m_Button5);
	DDX_Control(pDX, IDC_BUTTON4, m_Button4);
	DDX_Control(pDX, IDC_BUTTON3, m_Button3);
	DDX_Control(pDX, IDC_BUTTON2, m_Button2);
	DDX_Control(pDX, IDC_BUTTON1, m_Button1);
	DDX_Control(pDX, IDC_PROGRESS, m_time);
	DDX_Control(pDX, IDC_COMBO1, m_ComLevel);
	DDX_Text(pDX, IDC_SCORE, m_nScore);
	DDV_MinMaxInt(pDX, m_nScore, 0, 999);
	DDX_CBString(pDX, IDC_COMBO1, m_Level);
	DDX_Text(pDX, IDC_TIME, m_lTime);
	DDV_MinMaxInt(pDX, m_lTime, 0, 60);
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
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton)
	ON_WM_SETCURSOR()
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
	
	
	HICON hIcon=AfxGetApp()->LoadIcon(IDI_ICON1);
	SetClassLong(m_hWnd,GCL_HICON,(long)hIcon); 
	// TODO: Add extra initialization here
	m_ComLevel.InsertString(0,"简单");
	m_ComLevel.InsertString(1,"中等");
	m_ComLevel.InsertString(2,"困难");
	button[0]=&m_Button1;
	button[1]=&m_Button2;
	button[2]=&m_Button3;
	button[3]=&m_Button4;
	button[4]=&m_Button5;
	button[5]=&m_Button6;
	button[6]=&m_Button7;
	button[7]=&m_Button8;
	button[8]=&m_Button9;	
	((CButton *)GetDlgItem(IDC_BUTTON1))->SetBitmap(::LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
	((CButton *)GetDlgItem(IDC_BUTTON2))->SetBitmap(::LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
	((CButton *)GetDlgItem(IDC_BUTTON3))->SetBitmap(::LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
	((CButton *)GetDlgItem(IDC_BUTTON4))->SetBitmap(::LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
	((CButton *)GetDlgItem(IDC_BUTTON5))->SetBitmap(::LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
	((CButton *)GetDlgItem(IDC_BUTTON6))->SetBitmap(::LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
	((CButton *)GetDlgItem(IDC_BUTTON7))->SetBitmap(::LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
	((CButton *)GetDlgItem(IDC_BUTTON8))->SetBitmap(::LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
	((CButton *)GetDlgItem(IDC_BUTTON9))->SetBitmap(::LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
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
		/*CPaintDC   dc(this);   
		CRect   rect;   
		GetClientRect(&rect);                                 //获取对话框长宽       
		CDC   dcBmp;                                           //定义并创建一个内存设备环境
		dcBmp.CreateCompatibleDC(&dc);                         //创建兼容性DC
		CBitmap   bmpBackground;   
		bmpBackground.LoadBitmap(IDB_BITMAP1);                 //载入资源中的IDB_BITMAP1图片
		BITMAP   m_bitmap;                                     //图片变量                
		bmpBackground.GetBitmap(&m_bitmap);                    //将图片载入位图中
		CBitmap   *pbmpOld=dcBmp.SelectObject(&bmpBackground); //将位图选入临时内存设备环境  
		//调用函数显示图片 StretchBlt显示形状可变
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,
			m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);*/
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
	WORD id=LOWORD(GetCurrentMessage()->wParam);  //获取当前响应ON_CLICKED消息的控件ID
	CButton* pBtn=(CButton*)GetDlgItem(id);
	((CButton *)GetDlgItem(id))->SetBitmap(::LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP2)));
	pBtn->ShowWindow(FALSE); //隐藏当前按钮
	UpdateData(FALSE);
}

void CWhac_a_mole_TestDlg::OnOver() 
{
	// TODO: Add your control notification handler code here
	//杀死所有计时器
	for(int n=1;n<=13;n++)
	{
		KillTimer(n);
	}
	m_time.SetPos(0);
	CString prompt;
	//隐藏所有按钮
	for(int i = 0;i<9;i++ ) 
	{
		button[i]->ShowWindow(FALSE);
	}
	prompt.Format("你的得分是：  %d",m_nScore);
	m_nScore=0;
	MessageBox(prompt);
	m_time.SetPos(0);
	UpdateData(FALSE);//变量向控件传输
}

void CWhac_a_mole_TestDlg::OnStar() 
{
	int interval=0;//设置时间间隔
	if(m_ComLevel.GetCurSel()==CB_ERR){
		MessageBox("请选择游戏难度");
		return ;
	}
	UpdateData();
	m_nScore=0;
	int index=m_ComLevel.GetCurSel();
	switch (index){
	case 0:
		interval=1000; //启动简单模式计时器,时间间隔为1000毫秒
		break;
	case 1:
		interval=500; //启动简单模式计时器,时间间隔为500毫秒
		break;
	case 2:
		interval=300; //启动简单模式计时器,时间间隔为300毫秒
		break;
	default:
		MessageBox("请选择游戏难度");
	}
	SetTimer(11,interval,NULL); //启动计时器
	//隐藏所有按钮
	for(int i = 0;i<9;i++ ) 
	{
		button[i]->ShowWindow(FALSE);
	}
	// TODO: Add your control notification handler code here
	m_time.SetRange(0,59); //设置进展条时间范围59秒
	LeftTime=59;
	SetTimer(10,1000,NULL); //启动计时器

}
void CWhac_a_mole_TestDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	//随机显示按钮
	//随机数范围(rand() % (b-a+1))+ a；产生0-9的随机数，包含山下界
	
	//
	if(nIDEvent==11)
	{
		ShowButton();
	}
	if(nIDEvent==10)//进展条触发的OnTimer事件
	{
		m_lTime=LeftTime;
		UpdateData(FALSE);
		LeftTime-=1;
		m_time.SetPos(LeftTime);
	}
	if(nIDEvent<10)				//按钮触发的OnTimer事件
	{
		button[nIDEvent]->ShowWindow(FALSE);
		KillTimer(nIDEvent);
	}

	if(LeftTime==0)
	{
		OnOver();
	}

	CDialog::OnTimer(nIDEvent);
}

void CWhac_a_mole_TestDlg::ShowButton()
{
	srand((unsigned)time(NULL));
	int index=(rand() % (9))+0; //产生0-9的随机数
	SetTimer(index,1000,NULL); //启动计时器,时间间隔为一秒
	button[index]->ShowWindow(TRUE);
}

BOOL CWhac_a_mole_TestDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default


	BOOL bRes=CDialog::OnSetCursor(pWnd, nHitTest, message);
	m_hCursor=AfxGetApp()->LoadCursor(IDC_CURSOR1);
	SetCursor(m_hCursor);

/*	HCURSOR hCursor=AfxGetApp()->LoadCursor(IDC_CURSOR2);
	SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)hCursor);*/

	HWND btwnd = GetDlgItem(IDC_BUTTON1)->m_hWnd;
	SetClassLong(btwnd,GCL_HCURSOR,(long)m_hCursor);

	return TRUE;
}
