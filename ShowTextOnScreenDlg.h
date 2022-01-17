
// ShowTextOnScreenDlg.h : header file
//

#pragma once


// CShowTextOnScreenDlg dialog
class CShowTextOnScreenDlg : public CDialogEx
{
// Construction
public:
	CShowTextOnScreenDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOWTEXTONSCREEN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_text;
	afx_msg void OnEnChangeEdit1();
	int m_abscissa;
	afx_msg void OnEnChangeEdit2();
	int m_Ordinate;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton3();
	int m_FontHigh;
	afx_msg void OnEnChangeEdit4();
	int m_FontWidth;
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButton1();
};
