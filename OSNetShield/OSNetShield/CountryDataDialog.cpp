// CountryDataDialog.cpp: ���� ����������
//

#include "stdafx.h"
#include "CountryDataDialog.h"
#include "afxdialogex.h"
#include "resource.h"
#include "Country_Data.h"
// ���������� ���� CountryDataDialog

IMPLEMENT_DYNAMIC(CountryDataDialog, CDialogEx)

void StartCountryDataWindow()
{
	CountryDataDialog CountryDataDialog;
	CountryDataDialog.DoModal();
	
}

CountryDataDialog::CountryDataDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CountryDataDialog::IDD, pParent)
{
	DataBase.UpdateDB();
}

CountryDataDialog::~CountryDataDialog()
{
}

void CountryDataDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, Combo);
}


BEGIN_MESSAGE_MAP(CountryDataDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CountryDataDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CountryDataDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CountryDataDialog::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CountryDataDialog::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// ����������� ��������� CountryDataDialog


void CountryDataDialog::OnBnClickedButton1()
{
	std::set<std::string> ComboList;
	Combo.ResetContent();
	for (int i = 0; i < DataBase.amount; i++)
	{
		if (ComboList.find(DataBase.Base[i].ShortName) == ComboList.end())
		{
			ComboList.insert(DataBase.Base[i].ShortName);
			//������� ���������� �����
			Combo.AddString((LPCTSTR)DataBase.Base[i].ShortName.c_str());
		}
	}
	// TODO: �������� ���� ��� ����������� �����������
}


void CountryDataDialog::OnBnClickedButton2()
{
	
	CString s;
	Combo.GetWindowTextW(s);
	for (int i = 0; i < DataBase.amount; i++)
	{
		//
		// �������� �������� ������ s � DataBase.Base[i].ShortName, ���� ����� ��
		// ������������� �������� DataBase.Base[i].from - DataBase.Base[i].to
	}
	
}


void CountryDataDialog::OnBnClickedButton3()
{
	CString s;
	Combo.GetWindowTextW(s);
	for (int i = 0; i < DataBase.amount; i++)
	{
		//
		// �������� �������� ������ s � DataBase.Base[i].ShortName, ���� ����� ��
		// �������������� �������� DataBase.Base[i].from - DataBase.Base[i].to
	}
}


void CountryDataDialog::OnCbnSelchangeCombo1()
{
	// TODO: �������� ���� ��� ����������� �����������
}
