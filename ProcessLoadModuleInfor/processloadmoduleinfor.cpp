#include "stdafx.h"
#include "processloadmoduleinfor.h"

ProcessLoadModuleInfor::ProcessLoadModuleInfor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initUI();
	connect(this->ui.update_pushButton, &QPushButton::clicked, this, &ProcessLoadModuleInfor::getProcessInformationList);
	connect(this->ui.process_tableView, &QTableView::clicked, this, &ProcessLoadModuleInfor::displayLaodModuleInformation);
	connect(this->ui.lineEdit_searchProcess, &QLineEdit::textChanged, this, &ProcessLoadModuleInfor::searchProcessEditor);
	connect(this->ui.lineEdit_lineEdit_searchModule, &QLineEdit::textChanged, this, &ProcessLoadModuleInfor::searchModuleEditor);
	getProcessInformationList();

}

void ProcessLoadModuleInfor::getProcessInformationList()
{
	m_proceInfoVector.clear();
	this->m_getProcessTool.GetProcessName();
	m_proceInfoVector = this->m_getProcessTool.setProcessInformation();
	this->m_processTableViewModel->clear();
	this->m_processTableViewModel->setRowCount(m_proceInfoVector.size());
	for (size_t i = 0; i < m_proceInfoVector.size(); i++)
	{
		this->m_processTableViewModel->setItem(i, 0, new QStandardItem(QString::number(m_proceInfoVector.at(i).uPID)));
		this->m_processTableViewModel->setItem(i, 1, new QStandardItem(m_proceInfoVector.at(i).strPrceName));
		this->m_processTableViewModel->setItem(i, 2, new QStandardItem(m_proceInfoVector.at(i).strFullPath));
	}


}

void ProcessLoadModuleInfor::displayLaodModuleInformation(const QModelIndex &index)
{
#ifdef _DEBUG
	
#endif // _DEBUG
	unsigned int acctullyRow = m_processFilterProxyModel->headerData(index.row(), Qt::Orientation::Vertical).toUInt() - 1;
	if (acctullyRow >= 0)
	{
		this->m_moduleTableViewModel->clear();
		this->m_moduleTableViewModel->setRowCount(m_proceInfoVector.at(acctullyRow).strDLLNameArr.size());
		for (size_t i = 0; i < m_proceInfoVector.at(acctullyRow).strDLLNameArr.size(); i++)
		{
			this->m_moduleTableViewModel->setItem(i, 0, new QStandardItem(m_proceInfoVector.at(acctullyRow).strDLLNameArr.at(i)));
		}
	}
	
	

}

void ProcessLoadModuleInfor::searchProcessEditor(QString inputStr)
{
	m_processFilterProxyModel->setFilterRegExp(".*" + inputStr + ".*");

}

void ProcessLoadModuleInfor::searchModuleEditor(QString inputStr)
{
	m_moduleFilterProxyModel->setFilterRegExp(".*" + inputStr + ".*");
}

void ProcessLoadModuleInfor::initUI()
{
	this->ui.process_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.moduleInformation_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.process_tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	this->m_processTableViewModel->setColumnCount(3);
	this->m_moduleTableViewModel->setColumnCount(1);
	this->ui.process_tableView->horizontalHeader()->setStretchLastSection(true);	
	this->ui.moduleInformation_tableView->horizontalHeader()->setStretchLastSection(true);
	this->m_processTableViewModel->setHorizontalHeaderLabels(QStringList() << "PID" << "Process Name" << "Process Path");
	this->m_moduleTableViewModel->setHorizontalHeaderLabels(QStringList() << " Process Load Module");
	m_processFilterProxyModel->setSourceModel(m_processTableViewModel.get());
	m_moduleFilterProxyModel->setSourceModel(m_moduleTableViewModel.get());
	m_processFilterProxyModel->setFilterKeyColumn(1);
	m_moduleFilterProxyModel->setFilterKeyColumn(0);
	this->ui.process_tableView->setModel(m_processFilterProxyModel.get());
	this->ui.moduleInformation_tableView->setModel(m_moduleFilterProxyModel.get());
	m_processFilterProxyModel->setDynamicSortFilter(true);
	m_moduleFilterProxyModel->setDynamicSortFilter(true);
	
}
