#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_processloadmoduleinfor.h"

class ProcessLoadModuleInfor : public QMainWindow
{
	Q_OBJECT

public:
	ProcessLoadModuleInfor(QWidget *parent = Q_NULLPTR);

private:
	Ui::ProcessLoadModuleInforClass ui;
};
