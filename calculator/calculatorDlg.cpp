
// calculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "math.h"

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define POWER 5

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CcalculatorDlg 대화 상자



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	  DDX_Text(pDX, IDC_EDIT1, m_result);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT0, &CcalculatorDlg::OnClickedBut0)
	ON_BN_CLICKED(IDC_BUT1, &CcalculatorDlg::OnClickedBut1)
	ON_BN_CLICKED(IDC_BUT2, &CcalculatorDlg::OnClickedBut2)
	ON_BN_CLICKED(IDC_BUT3, &CcalculatorDlg::OnClickedBut3)
	ON_BN_CLICKED(IDC_BUT4, &CcalculatorDlg::OnClickedBut4)
	ON_BN_CLICKED(IDC_BUT5, &CcalculatorDlg::OnClickedBut5)
	ON_BN_CLICKED(IDC_BUT6, &CcalculatorDlg::OnClickedBut6)
	ON_BN_CLICKED(IDC_BUT7, &CcalculatorDlg::OnClickedBut7)
	ON_BN_CLICKED(IDC_BUT8, &CcalculatorDlg::OnClickedBut8)
	ON_BN_CLICKED(IDC_BUT9, &CcalculatorDlg::OnClickedBut9)
	ON_BN_CLICKED(IDC_POINT, &CcalculatorDlg::OnClickedPoint)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &CcalculatorDlg::OnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &CcalculatorDlg::OnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &CcalculatorDlg::OnClickedDiv)
	ON_BN_CLICKED(IDC_EQUAL, &CcalculatorDlg::OnClickedEqual)
	ON_BN_CLICKED(IDC_CLEAR, &CcalculatorDlg::OnClickedClear)
	ON_BN_CLICKED(IDC_SIN, &CcalculatorDlg::OnClickedSin)
	ON_BN_CLICKED(IDC_COS, &CcalculatorDlg::OnClickedCos)
	ON_BN_CLICKED(IDC_TAN, &CcalculatorDlg::OnClickedTan)
	ON_BN_CLICKED(IDC_LOG, &CcalculatorDlg::OnClickedLog)
	ON_BN_CLICKED(IDC_INV, &CcalculatorDlg::OnClickedInv)
	ON_BN_CLICKED(IDC_ROOT, &CcalculatorDlg::OnClickedRoot)
	ON_BN_CLICKED(IDC_POWER, &CcalculatorDlg::OnClickedPower)
	ON_BN_CLICKED(IDC_LN, &CcalculatorDlg::OnClickedLn)
END_MESSAGE_MAP()


// CcalculatorDlg 메시지 처리기

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnClickedBut0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("0");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedBut1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("1");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedBut2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("2");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedBut3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("3");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedBut4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("4");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedBut5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("5");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedBut6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("6");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedBut7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("7");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedBut8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("8");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedBut9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("9");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedPoint()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T(".");
	UpdateData(false);
}


void CcalculatorDlg::OnClickedAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_OpType = ADD;
	m_buf = m_result;
	m_result.Empty();
}


void CcalculatorDlg::OnClickedSub()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_OpType = SUB;
	m_buf = m_result;
	m_result.Empty();
}


void CcalculatorDlg::OnClickedMul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_OpType = MUL;
	m_buf = m_result;
	m_result.Empty();
}


void CcalculatorDlg::OnClickedDiv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_OpType = DIV;
	m_buf = m_result;
	m_result.Empty();
}


void CcalculatorDlg::OnClickedEqual()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double op1, op2, result;
	op1 = _tstof(m_buf);
	op2 = _tstof(m_result);
	switch (m_OpType)
	{
	case ADD:
		result = op1 + op2;
		break;
	case SUB:
		result = op1 - op2;
		break;
	case MUL:
		result = op1 * op2;
		break;
	case DIV:
		result = op1 / op2;
		break;
	case POWER:
		result = pow(op1, op2);
		break;
	}
	m_result.Format(_T("%6.6f"), result);
	UpdateData(false);
	m_bEqualClk = true;
}

void CcalculatorDlg::OnClickedClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_result.Empty();
	UpdateData(false);
}


void CcalculatorDlg::OnClickedSin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double a;
	a = _tstof(m_result);
	a = sin(a * 3.141592 / 180.0);
	m_result.Format(_T("%f"), a);
	UpdateData(false);
}


void CcalculatorDlg::OnClickedCos()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double a;
	a = _tstof(m_result);
	a = cos(a * 3.141592 / 180.0);
	m_result.Format(_T("%f"), a);
	UpdateData(false);
}


void CcalculatorDlg::OnClickedTan()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double a;
	a = _tstof(m_result);
	a = tan(a * 3.141592 / 180.0);
	m_result.Format(_T("%.4f"), a);
	UpdateData(false);
}


void CcalculatorDlg::OnClickedLog()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double a;
	a = _tstof(m_result);
	a = log10(a);
	m_result.Format(_T("%f"), a);
	UpdateData(false);
}


void CcalculatorDlg::OnClickedInv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double a;
	a = _tstof(m_result);
	a = 1 / a;
	m_result.Format(_T("%f"), a);
	UpdateData(false);
}


void CcalculatorDlg::OnClickedRoot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double a;
	a = _tstof(m_result);
	a = sqrt(a);
	m_result.Format(_T("%f"), a);
	UpdateData(false);
}


void CcalculatorDlg::OnClickedPower()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_OpType = POWER;
	m_buf = m_result;
	m_result.Empty();
}


void CcalculatorDlg::OnClickedLn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double a;
	a = _tstof(m_result);
	a = log(a);
	m_result.Format(_T("%f"), a);
	UpdateData(false);
}
