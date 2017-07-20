#pragma once

#include <QtWidgets/QMainWindow>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QXmlStreamReader>

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

	void httpFinished();
	void httpReadyRead();

private:
	Ui::rssClass ui;

	QUrl url;
	QNetworkAccessManager qnam;
	
	QNetworkReply *reply;

	void startRequest(const QUrl& requestedUrl);
	void parseXML(QXmlStreamReader& xml);
};
