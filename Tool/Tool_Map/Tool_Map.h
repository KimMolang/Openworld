#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tool_Map.h"

class Tool_Map : public QMainWindow
{
	Q_OBJECT

public:
	Tool_Map(QWidget *parent = Q_NULLPTR);

private:
	Ui::Tool_MapClass ui;
};
