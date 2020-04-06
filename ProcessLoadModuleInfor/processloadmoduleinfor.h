#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_processloadmoduleinfor.h"
#include "GetModuleInfor.h"
class ProcessLoadModuleInfor : public QMainWindow
{
	Q_OBJECT

public:
	ProcessLoadModuleInfor(QWidget *parent = Q_NULLPTR);
private slots:
	void getProcessInformationList();
	void displayLaodModuleInformation(const QModelIndex &index);
	void searchProcessEditor(QString inputStr);
	void searchModuleEditor(QString inputStr);

private:
	void initUI();

	Ui::ProcessLoadModuleInforClass ui;
	GetModuleInfor							m_getProcessTool;
	std::vector<GetModuleInfor::ProInfo>	m_proceInfoVector;
	std::unique_ptr<QStandardItemModel>		m_processTableViewModel{ std::make_unique<QStandardItemModel>(this) };
	std::unique_ptr<QStandardItemModel>		m_moduleTableViewModel{ std::make_unique<QStandardItemModel>(this) };
	std::unique_ptr<QSortFilterProxyModel>	m_processFilterProxyModel{ std::make_unique<QSortFilterProxyModel>(this) };
	std::unique_ptr<QSortFilterProxyModel>	m_moduleFilterProxyModel{ std::make_unique<QSortFilterProxyModel>(this)  };
};
