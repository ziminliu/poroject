// PaintView.cpp : implementation of the CPaintView class
//

#include "stdafx.h"
#include "Paint.h"

#include "PaintDoc.h"
#include "PaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CView)

BEGIN_MESSAGE_MAP(CPaintView, CView)
	//{{AFX_MSG_MAP(CPaintView)
	ON_COMMAND(ID_LINE, OnLine)
	ON_COMMAND(ID_ZLINE, OnZline)
	ON_COMMAND(ID_RECT, OnRect)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_POINT, OnPoint)
	ON_COMMAND(ID_ARC, OnArc)
	ON_COMMAND(ID_ELLI, OnElli)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintView construction/destruction

CPaintView::CPaintView()
{
	// TODO: add construction code here

}

CPaintView::~CPaintView()
{
}

BOOL CPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPaintView drawing

void CPaintView::OnDraw(CDC* pDC)
{
	CPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPaintView printing

BOOL CPaintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPaintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPaintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPaintView diagnostics

#ifdef _DEBUG
void CPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintDoc* CPaintView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintDoc)));
	return (CPaintDoc*)m_pDocument;
} 
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaintView message handlers

void CPaintView::OnLine() 
{
	// TODO: Add your command handler code here
	/*
	CString str;
	str.Format(_T("%s"), _T("Hello world!"));
	MessageBox(str);*/
	type=ID_LINE;
	init=true;
}

void CPaintView::OnZline() 
{
	// TODO: Add your command handler code here
	type=ID_ZLINE;
	init=true;
}

void CPaintView::OnRect() 
{
	// TODO: Add your command handler code here
	type=ID_RECT;
}

void CPaintView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox("LEFT");

	CClientDC dc(this);
	//按下鼠标左键后设置为绘制状态
	m_bDraw = true;
	//根据传递的type绘制图形
	switch(type){
	case ID_POINT:
		m_ptOrigin = point;
	case ID_LINE:
		//画线时 设置初始位置与末位置为当前鼠标按下的位置
		m_ptOrigin = point;
		m_ptEnd = point;
	break;
	case ID_ZLINE:
		m_ptOrigin = m_ptEnd;
	break;
	case ID_RECT:
		m_ptOrigin = point;
		break;
	}
	CView::OnLButtonDown(nFlags, point);
}

void CPaintView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	if(init)
	{
	   m_ptOrigin=point;
	  init=false;
	}
	//鼠标左键松开，解除绘制状态
	m_bDraw = false;

	//记录松开位置为结束点
	m_ptEnd = point;

	//不是画点状态下，橡皮筋绘制会导致最后一条线与已有的线交叉处为空白，即最后一条线绘制两次即可
	if(type==ID_LINE||type==ID_ZLINE){
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(m_ptEnd);
	}
}

void CPaintView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
  CClientDC dc(this);

		CRect rec(m_ptOrigin,point);
  //判断鼠标左键是否处于按下状态
if(m_bDraw)
 {
	switch(type){
	case ID_POINT:
		dc.SetPixelV(point,RGB(0,0,0));
		break;
	case ID_LINE:
	case ID_ZLINE:
		//使用屏幕颜色相反的颜色(白色）绘制上一条线，实现只在屏幕上留下一条直线，
	  dc.SetROP2(R2_NOT);     //1
	  dc.MoveTo(m_ptOrigin);  //2
	  dc.LineTo(m_ptEnd);    //3

	  //实现橡皮筋效果
	  //设置直线终点位置为当前点,绘制由m_ptOrigin 到当前鼠标位置point 即m_ptEnd 位置的直线  不断绘制
	  m_ptEnd = point;
	  dc.MoveTo(m_ptOrigin);
	  dc.LineTo(m_ptEnd);
	  break;
	case ID_RECT:
		dc.Rectangle(rec);
		break;
	case ID_ARC:
		break;
	case ID_ELLI:
		break;
	}
 }
	CView::OnMouseMove(nFlags, point);
}

void CPaintView::OnPoint() 
{
	// TODO: Add your command handler code here
	type=ID_POINT;
	//点击后设置为停止绘制状态，解决按下按钮后一直绘制的bug
	m_bDraw = false;
}

void CPaintView::OnArc() 
{
	// TODO: Add your command handler code here
	type=ID_ARC;
}

void CPaintView::OnElli() 
{
	// TODO: Add your command handler code here	
	type=ID_ELLI;
}
