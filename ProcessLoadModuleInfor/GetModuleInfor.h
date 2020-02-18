#pragma once

#include <QObject>
#include <Windows.h>
#include <Psapi.h>
#include <strsafe.h>
//#include <afx.h>
#include "TlHelp32.h"
class GetModuleInfor : public QObject
{
	Q_OBJECT	
public:
	struct ProInfo
	{
		// �������PID
		unsigned int uPID;
		// ���������
		QString strPrceName;
		// �������·��
		QString strFullPath;
		// ����ý��̵���dll����·��
		std::vector<QString> strDLLNameArr;
		ProInfo() :uPID(0), strPrceName(QString()), strFullPath(QString()), strDLLNameArr({})
		{};
	};
	GetModuleInfor(QObject *parent=nullptr);
	~GetModuleInfor();
public slots:
	void GetProcessName(void);
	std::vector<ProInfo> setProcessInformation(void) const;
private:
	bool EnableDebugPrivilege(bool fEnable);
	std::vector<ProInfo> m_proceInfoVector;



};
