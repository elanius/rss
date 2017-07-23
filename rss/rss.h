#pragma once

#include <QtWidgets/QMainWindow>
#include <QCloseEvent>
#include <QTimer>
#include <QTest>
#include "RssReader.h"
#include "ui_rss.h"

class rss : public QMainWindow
{
	Q_OBJECT

public:
	rss(QWidget *parent = Q_NULLPTR);

public slots:

	void onAdd();
	void onRemove();
	void onRefresh();
	void onChannelSelect(QListWidgetItem* item);

	void onNewChannel(CChannel* channel);
	void onArticleClicked(QListWidgetItem *item);

	void closeEvent(QCloseEvent *event);
private:
	Ui::rssClass ui;
	CRssReader rssReader;
	QTimer timer;

	void showArticles(const CChannel* channel);
	bool customValid(QUrl& url);
};
