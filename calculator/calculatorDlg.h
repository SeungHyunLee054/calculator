
// calculatorDlg.h: 헤더 파일
//

#pragma once


// CcalculatorDlg 대화 상자
class CcalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CcalculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_result;
	CString m_buf;
	BOOL m_bEqualClk;
	int m_OpType;
	afx_msg void OnClickedBut0();
	afx_msg void OnClickedBut1();
	afx_msg void OnClickedBut2();
	afx_msg void OnClickedBut3();
	afx_msg void OnClickedBut4();
	afx_msg void OnClickedBut5();
	afx_msg void OnClickedBut6();
	afx_msg void OnClickedBut7();
	afx_msg void OnClickedBut8();
	afx_msg void OnClickedBut9();
	afx_msg void OnClickedPoint();
	afx_msg void OnClickedAdd();
	afx_msg void OnClickedSub();
	afx_msg void OnClickedMul();
	afx_msg void OnClickedDiv();
	afx_msg void OnClickedEqual();
	afx_msg void OnClickedClear();
	afx_msg void OnClickedSin();
	afx_msg void OnClickedCos();
	afx_msg void OnClickedTan();
	afx_msg void OnClickedLog();
	afx_msg void OnClickedInv();
	afx_msg void OnClickedRoot();
	afx_msg void OnClickedPower();
	afx_msg void OnClickedLn();
};
