#include <windows.h>
#include <netfw.h>
#include <iostream>
#include <vector>
#include "atlstr.h"

#pragma once
#pragma comment( lib, "ole32.lib" )
#pragma comment( lib, "oleaut32.lib" )

std::string makeRuleName(std::vector<std::wstring> &vFwAddedRules);

HRESULT WFCOMInitialize(INetFwPolicy2** ppNetFwPolicy2);

class cFwAccess
{
public:
	cFwAccess(void);
	~cFwAccess(void);
	void ruleMaker(std::wstring &sName, std::wstring &sDscr, std::wstring &sAddr, int nAction, NET_FW_RULE_DIRECTION_ dir);
	void cleanup(
		BSTR &bstrRuleName, BSTR &bstrRuleDescription, BSTR &bstrRuleGroup, BSTR &bstrRuleRemoteAdresses, BSTR &bstrVal,
		INetFwRule *pFwRule, INetFwRules *pFwRules,  INetFwPolicy2 *pNetFwPolicy2,
		HRESULT &hrComInit
		);
	std::wstring makeRuleName();
	void controlFw();
	void controlFwGUI(std::wstring &sIP, int nAction);
private:
	std::vector<std::wstring> vFwAddedRules;
};

