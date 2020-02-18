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
		// 保存进程PID
		unsigned int uPID;
		// 保存进程名
		QString strPrceName;
		// 保存进程路径
		QString strFullPath;
		// 保存该进程调用dll名和路径
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
