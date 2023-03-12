#include "qpoisson.h"
#include <QtWidgets/QApplication>

#ifdef QT_NO_DEBUG
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);
Q_IMPORT_PLUGIN(QICOPlugin);
#endif

extern "C"
{
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QPoisson w;
	w.show();
	return a.exec();
}
