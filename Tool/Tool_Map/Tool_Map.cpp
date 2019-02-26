#include "Tool_Map.h"

#include <QtCore>


Tool_Map::Tool_Map(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	const QString qVersion = QLatin1String(QT_VERSION_STR);
	ui.button_bag->setText(qVersion);
}
