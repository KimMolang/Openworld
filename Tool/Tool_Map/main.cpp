#include "Tool_Map.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Tool_Map w;
	w.show();
	return a.exec();
}
