#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_processloadmoduleinfor.h"
#include "GetModuleInfor.h"
class ProcessLoadModuleInfor : public QMainWindow
{
	Q_OBJECT

public:
	ProcessLoadModuleInfor(QWidget *parent = Q_NULLPTR);
public slots:
	void getProcessInformationList();
	void displayLaodModuleInformation(QTableWidgetItem *item);
private:
	void initUI();

	Ui::ProcessLoadModuleInforClass ui;
	GetModuleInfor					m_getProcessTool;
	std::vector<GetModuleInfor::ProInfo> m_proceInfoVector;
};
