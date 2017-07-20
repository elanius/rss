#include <QtNetwork>

#include "rss.h"



rss::rss(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
}


void rss::onAdd()
{
	if ( ui.leNewFeed->text().isEmpty() == false )
	{
		QTreeWidgetItem* feed = new QTreeWidgetItem;
		feed->setText(0, ui.leNewFeed->text());

		QTreeWidgetItem* child = new QTreeWidgetItem;
		child->setText(0, "child");
		feed->addChild(child);

		ui.treeWidget->addTopLevelItem(feed);

		ui.leNewFeed->clear();
	}
}


void rss::onRemove()
{
	auto item = ui.treeWidget->currentItem();
	if ( item )
	{
		int index = ui.treeWidget->indexOfTopLevelItem(item);
		auto taken = ui.treeWidget->takeTopLevelItem(index);
		if ( taken )
		{
			delete taken;
		}
	}
}


void rss::onRefresh()
{
	QTreeWidgetItemIterator it(ui.treeWidget);

	while ( *it )
	{
		const QString urlSpec = (*it)->text(0).trimmed();
		const QUrl url = QUrl::fromUserInput(urlSpec);

		startRequest(url);

		++it;
	}
}


void rss::startRequest(const QUrl &requestedUrl)
{
	url = requestedUrl;

	reply = qnam.get(QNetworkRequest(url));
	connect(reply, &QNetworkReply::finished, this, &rss::httpFinished);
	connect(reply, &QIODevice::readyRead, this, &rss::httpReadyRead);
}


void rss::httpFinished()
{
	QXmlStreamReader xml;
	xml.addData(reply->readAll());
	parseXML(xml);
}


void rss::httpReadyRead()
{

}


void rss::parseXML(QXmlStreamReader& xml)
{
	QString currentTag;
	QString linkString;
	QString titleString;
	QString dateString;

	QTreeWidgetItem* feed = nullptr;

	while ( !xml.atEnd() )
	{
		xml.readNext();
		if ( xml.isStartElement() )
		{
			if ( xml.name() == "item" )
			{
				if ( titleString != "" )
				{
					feed = new QTreeWidgetItem;
					feed->setText(0, titleString);
					feed->setText(2, linkString);
					ui.treeWidget->addTopLevelItem(feed);
				}

				linkString.clear();
				titleString.clear();
				dateString.clear();
			}

			currentTag = xml.name().toString();
		}
		else if ( xml.isEndElement() )
		{
			if ( xml.name() == "item" )
			{

				QTreeWidgetItem *item = new QTreeWidgetItem(feed);
				item->setText(0, titleString);
				item->setText(1, dateString);
				item->setText(2, linkString);
				ui.treeWidget->addTopLevelItem(item);

				titleString.clear();
				linkString.clear();
				dateString.clear();
			}
		}
		else if ( xml.isCharacters() && !xml.isWhitespace() )
		{
			if ( currentTag == "title" )
				titleString += xml.text().toString();
			else if ( currentTag == "link" )
				linkString += xml.text().toString();
			else if ( currentTag == "pubDate" )
				dateString += xml.text().toString();
		}
	}
	if ( xml.error() && xml.error() != QXmlStreamReader::PrematureEndOfDocumentError )
	{
		qWarning() << "XML ERROR:" << xml.lineNumber() << ": " << xml.errorString();
		//http.abort();
	}
}
