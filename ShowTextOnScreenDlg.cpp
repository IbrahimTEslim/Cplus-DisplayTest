
// ShowTextOnScreenDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ShowTextOnScreen.h"
#include "ShowTextOnScreenDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


int X_Coordinate;
int Y_Coordinate;

int Font_High;
int Font_Width;

CString Text;
int Text_Length; // How many Letters


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShowTextOnScreenDlg dialog



CShowTextOnScreenDlg::CShowTextOnScreenDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOWTEXTONSCREEN_DIALOG, pParent)
	, m_text(_T(""))
	, m_abscissa(0)
	, m_Ordinate(0)
	, m_FontHigh(0)
	, m_FontWidth(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShowTextOnScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_text);
	DDX_Text(pDX, IDC_EDIT2, m_abscissa);
	DDX_Text(pDX, IDC_EDIT3, m_Ordinate);
	DDX_Text(pDX, IDC_EDIT4, m_FontHigh);
	DDX_Text(pDX, IDC_EDIT5, m_FontWidth);
}

BEGIN_MESSAGE_MAP(CShowTextOnScreenDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CShowTextOnScreenDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CShowTextOnScreenDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CShowTextOnScreenDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON3, &CShowTextOnScreenDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT4, &CShowTextOnScreenDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CShowTextOnScreenDlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON1, &CShowTextOnScreenDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CShowTextOnScreenDlg message handlers

BOOL CShowTextOnScreenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	//==> "Welcome" Part's
	CFont* Welcome_font = new CFont();
	Welcome_font->CreatePointFont(170, _T("Arial"));
	GetDlgItem(IDC_STATIC)->SetFont(Welcome_font, TRUE);


	//==> "Type Here" Part's
	CFont* TyperHere_font = new CFont();
	TyperHere_font->CreatePointFont(100, _T("Arial"));
	GetDlgItem(IDC_STATIC_2)->SetFont(TyperHere_font, TRUE);

	//==> Font using into the edit control
	CFont* Edit_Font = new CFont();
	Edit_Font->CreatePointFont(120, _T("Arial"));
	GetDlgItem(IDC_EDIT1)->SetFont(Edit_Font, TRUE);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShowTextOnScreenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShowTextOnScreenDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShowTextOnScreenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShowTextOnScreenDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShowTextOnScreenDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShowTextOnScreenDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

UINT Draw(LPVOID lparam)
{
	DEVMODE dv;
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dv);
	int Mid_Width = dv.dmPelsWidth;
	int Mid_High = dv.dmPelsHeight;

	HDC hdc = GetDC(NULL);

	HFONT h_font = CreateFont(Font_High, Font_Width, 0, 0, 0, TRUE, 0, 0, 0, 0, 0, 0, 0, L"Arial");

	SelectObject(hdc, h_font);


	while (1)
	{
		TextOut(hdc, X_Coordinate, Y_Coordinate, CT2CW(Text), Text_Length);
	}

	return TRUE;
}

void CShowTextOnScreenDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	X_Coordinate = m_abscissa;
	Y_Coordinate = m_Ordinate;

	Font_High = m_FontHigh;
	Font_Width = m_FontWidth;

	Text = m_text;
	Text_Length = m_text.GetLength();


	AfxBeginThread(Draw, 0);
}


void CShowTextOnScreenDlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShowTextOnScreenDlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShowTextOnScreenDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	exit(1);
}
