#include <QtNetwork>
#include <QTest>
#include <QSignalSpy>

#include "FeedParser.h"
#include "Channel.h"


CChannel::CChannel(QUrl& url) : url(url)
{
	articles.reserve(10);
}


CChannel::~CChannel()
{
}


void CChannel::AddArticle(CArticle&& article)
{
	articles.push_back(std::move(article));
}


void CChannel::Refresh()
{
	valid = false;
	articles.clear();

	connect(&qnam, &QNetworkAccessManager::finished, this, &CChannel::httpFinished);
	qnam.get(QNetworkRequest(url));
}


void CChannel::httpFinished(QNetworkReply* reply)
{
	if (reply->error() == QNetworkReply::NoError)
	{
		QXmlStreamReader xml;
		xml.addData(reply->readAll());

		if (CFeedParser::Parse(xml, this))
		{
			valid = true;
			if (completed == false)
			{
				completed = true;
				NewChannel(this);
			}

			return;
		}
	}
	
	reply->deleteLater();
	NewChannel(this);
}


void CChannel::ForEachArticle(std::function<void(const CArticle&)> lambda) const 
{
	for (auto& a : articles)
	{
		lambda(a);
	}
}


void CChannel::createChannel()
{
	Refresh();

	QSignalSpy spy(this, &CChannel::NewChannel);
	QVERIFY(spy.wait());

	QVERIFY(articles.size() > 0);
}