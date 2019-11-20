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
	
}

void CPaintView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox("LEFT");
	if(init)
	{
		m_ptOrigin = point;
		init=false;
	}else{
	m_bDraw = true;
	switch(type){
	case ID_POINT:
		m_ptOrigin = point;
	case ID_LINE:
		m_ptOrigin = point;
		m_ptEnd = point; 
	break;
	case ID_ZLINE:
		m_ptOrigin = m_ptEnd;
	break;
	}
	}
	CView::OnLButtonDown(nFlags, point);
}

void CPaintView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	m_bDraw = false;
	m_ptEnd = point;
	if(type!=ID_POINT){
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(m_ptEnd);
	}
}

void CPaintView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
  CClientDC dc(this);

if(m_bDraw)
 {
	switch(type){
	case ID_LINE:
	case ID_ZLINE:
	  dc.SetROP2(R2_NOT);     //1
	  dc.MoveTo(m_ptOrigin);  //2
	  dc.LineTo(m_ptEnd);    //3
	  m_ptEnd = point;
	  dc.MoveTo(m_ptOrigin);
	  dc.LineTo(m_ptEnd);
	  break;
	case ID_POINT:
		dc.SetPixelV(point,RGB(0,0,0));
		break;
	}
 }
	CView::OnMouseMove(nFlags, point);
}

void CPaintView::OnPoint() 
{
	// TODO: Add your command handler code here
	type=ID_POINT;
}
