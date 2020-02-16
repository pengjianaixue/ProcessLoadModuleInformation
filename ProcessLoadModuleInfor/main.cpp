#include "stdafx.h"
#include "processloadmoduleinfor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ProcessLoadModuleInfor w;
	w.show();
	return a.exec();
}
