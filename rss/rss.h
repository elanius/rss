#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_rss.h"

class rss : public QMainWindow
{
	Q_OBJECT

public:
	rss(QWidget *parent = Q_NULLPTR);

private:
	Ui::rssClass ui;
};
