#include <QListWidgetItem>
#include <QDesktopServices>
#include <QMessageBox>
#include "FeedParser.h"
#include "rss.h"

Q_DECLARE_METATYPE(const CArticle*);
Q_DECLARE_METATYPE(CChannel*);

rss::rss(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(&rssReader, &CRssReader::NewChannel, this, &rss::onNewChannel);

	rssReader.LoadFromFile();
	rssReader.RefreshAll();

	timer.start(10*60*1000);

	connect(&timer, &QTimer::timeout, this, &rss::onRefresh);
	connect(ui.lArticles, &QListWidget::itemClicked, this, &rss::onArticleClicked);
}


void rss::onAdd()
{
	if ( ui.leNewFeed->text().isEmpty() == false )
	{
		QUrl url = QUrl::fromUserInput(ui.leNewFeed->text().trimmed());
		if (url.isValid() && customValid(url))
		{
			auto channel = std::make_unique<CChannel>(url);
			CChannel* channelPtr = channel.get();
			if (rssReader.AddChannel(std::move(channel)))
			{
				channelPtr->Refresh();
			}
			else
			{
				QMessageBox messageBox;
				messageBox.critical(0, "Error", QString("RSS feed already in list"));
			}
			
		}
		else
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", QString("RSS feed (%1) is not valid http link!").arg(ui.leNewFeed->text()));
		}

		ui.leNewFeed->clear();
	}
}


void rss::onRemove()
{
	auto item = ui.lChannels->currentItem();
	if ( item )
	{
		rssReader.RemoveChannel(item->data(1000).value<CChannel*>());
		delete ui.lChannels->takeItem(ui.lChannels->currentRow());

		ui.lArticles->clear();
	}
}


void rss::onRefresh()
{
	rssReader.RefreshAll();
}

void rss::onNewChannel(CChannel* channel)
{
	if (channel->IsValid() == false)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString("Obtain RSS feed failed!"));
		rssReader.RemoveChannel(channel);
	}
	else
	{
		auto channelItem = new QListWidgetItem(channel->Title());
		channelItem->setData(1000, QVariant::fromValue<CChannel*>(channel));
		ui.lChannels->addItem(channelItem);
	}
}


void rss::onChannelSelect(QListWidgetItem* item)
{
	const CChannel* channel = item->data(1000).value<CChannel*>();

	showArticles(channel);
}


void rss::onArticleClicked(QListWidgetItem *item)
{
	const CArticle* article = item->data(1000).value<const CArticle*>();

	QDesktopServices::openUrl(QUrl(article->Link()));
}


void rss::showArticles(const CChannel* channel)
{
	Q_ASSERT(channel);

	ui.lArticles->clear();

	channel->ForEachArticle([this](const CArticle& article) {
		auto item = new QListWidgetItem(article.Title());
		item->setToolTip(article.Description());
		item->setData(1000, QVariant::fromValue<const CArticle*>(&article));
		ui.lArticles->addItem(item);
	});
}


void rss::closeEvent(QCloseEvent *event)
{
	rssReader.SaveToFile();
	event->accept();
}


bool rss::customValid(QUrl& url)
{
	if (url.toString().startsWith("http", Qt::CaseInsensitive))
		return true;

	return false;
}