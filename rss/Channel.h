#pragma once

#include <memory>
#include <vector>
#include <functional>
#include <QObject>
#include <QNetworkAccessManager>
#include <QString>
#include <QUrl>
#include "Article.h"

class CChannel : public QObject
{
	Q_OBJECT
public:
	CChannel(QUrl& url);
	~CChannel();

	void SetTitle(QString& str) { title = str; };

	const QString& Title() const { return title; };
	const QUrl& Url() { return url; };
	size_t Count() const { return articles.size(); };
	void AddArticle(CArticle&& article);

	void Refresh();

	void ForEachArticle(std::function<void(const CArticle&)> lambda) const;

	bool IsValid() { return valid; };

public slots:
	void httpFinished(QNetworkReply* reply);

signals:
	void NewChannel(CChannel* channel);

private:

	QString title;

	QUrl url;
	QNetworkAccessManager qnam;

	bool completed = false;
	bool valid = false;
	std::vector<CArticle> articles;

private slots:
	void createChannel();
};

using TChannel = std::unique_ptr<CChannel>;