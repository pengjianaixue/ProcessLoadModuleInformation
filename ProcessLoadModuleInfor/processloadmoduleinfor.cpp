#include "stdafx.h"
#include "processloadmoduleinfor.h"

ProcessLoadModuleInfor::ProcessLoadModuleInfor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initUI();
	connect(this->ui.update_pushButton, &QPushButton::clicked, this, &ProcessLoadModuleInfor::getProcessInformationList);
	connect(this->ui.process_tableWidget, &QTableWidget::itemClicked, this, &ProcessLoadModuleInfor::displayLaodModuleInformation);
	getProcessInformationList();

}

void ProcessLoadModuleInfor::getProcessInformationList()
{
	m_proceInfoVector.clear();
	this->m_getProcessTool.GetProcessName();
	m_proceInfoVector = this->m_getProcessTool.setProcessInformation();
	this->ui.process_tableWidget->clearContents();
	this->ui.process_tableWidget->setRowCount(m_proceInfoVector.size());
	for (size_t i = 0; i < m_proceInfoVector.size(); i++)
	{
		this->ui.process_tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(m_proceInfoVector.at(i).uPID)));
		this->ui.process_tableWidget->setItem(i, 1, new QTableWidgetItem(m_proceInfoVector.at(i).strPrceName));
		this->ui.process_tableWidget->setItem(i, 2, new QTableWidgetItem(m_proceInfoVector.at(i).strFullPath));
	}


}

void ProcessLoadModuleInfor::displayLaodModuleInformation(QTableWidgetItem *item)
{

	if (item->row()>0)
	{
		this->ui.moduleInformation_tableWidget->clearContents();
		this->ui.moduleInformation_tableWidget->setRowCount(m_proceInfoVector.at(item->row()).strDLLNameArr.size());
		for (size_t i = 0; i < m_proceInfoVector.at(item->row()).strDLLNameArr.size(); i++)
		{
			this->ui.moduleInformation_tableWidget->setItem(i, 0, new QTableWidgetItem(m_proceInfoVector.at(item->row()).strDLLNameArr.at(i)));
		}
	}
	
	

}

void ProcessLoadModuleInfor::initUI()
{
	this->ui.process_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.moduleInformation_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.process_tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	this->ui.process_tableWidget->setColumnCount(3);
	this->ui.moduleInformation_tableWidget->setColumnCount(1);
	this->ui.process_tableWidget->horizontalHeader()->setStretchLastSection(true);	
	this->ui.moduleInformation_tableWidget->horizontalHeader()->setStretchLastSection(true);
	this->ui.process_tableWidget->setHorizontalHeaderLabels(QStringList() << "PID" << "Process Name" << "Process Path");
	this->ui.moduleInformation_tableWidget->setHorizontalHeaderLabels(QStringList() << " Process Load Module");
}
