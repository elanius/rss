#include <memory>
#include <QTest>
#include "FeedParser.h"
#include "Channel.h"
#include "Article.h"


CFeedParser::CFeedParser()
{
}


CFeedParser::~CFeedParser()
{
}


bool CFeedParser::Parse(QXmlStreamReader& xml, CChannel* channel)
{
	QString currentTag;
	QString link;
	QString title;
	QString date;
	QString desc;

	while (!xml.atEnd())
	{
		xml.readNext();
		if (xml.isStartElement())
		{
			if (xml.name() == "item")
			{
				if (title != "")
				{
					channel->SetTitle(title);
				}

				title.clear();
				link.clear();
				date.clear();
				desc.clear();
			}

			currentTag = xml.name().toString();
		}
		else if (xml.isEndElement())
		{
			if (xml.name() == "item")
			{
				channel->AddArticle(CArticle(title, link, date, desc));

				title.clear();
				link.clear();
				date.clear();
				desc.clear();
			}
		}
		else if (xml.isCharacters() && !xml.isWhitespace())
		{
			if (currentTag == "title")
				title += xml.text().toString();
			else if (currentTag == "link")
				link += xml.text().toString();
			else if (currentTag == "pubDate")
				date += xml.text().toString();
			else if (currentTag == "description")
				desc += xml.text().toString();
		}
	}
	if (xml.error() && xml.error() != QXmlStreamReader::PrematureEndOfDocumentError)
	{
		return false;
	}

	return true;
}


void CFeedParser::testParser()
{
	QString input = \
		R"(<?xml version="1.0" encoding="Windows-1250"?>
<rss version="2.0"
 xmlns:content="http://purl.org/rss/1.0/modules/content/"
 xmlns:dc="http://purl.org/dc/elements/1.1/"
 xmlns:sy="http://purl.org/rss/1.0/modules/syndication/"
 xmlns:admin="http://webns.net/mvcb/"
 xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">
<channel>
<title>RSS</title>
<link>http://www.sme.sk/</link>
<pubDate>Sat, 22 Jul 2017 05:40:00 GMT</pubDate>

<item>
<title>article_1</title>
<link>http://example.com/1</link>
<description>description_1</description>
<pubDate>Wed, 19 Jul 2017 10:50:26 GMT</pubDate>
</item>

<item>
<title>article_2</title>
<link>http://example.com/2</link>
<description>description_2</description>
<pubDate>Wed, 19 Jul 2017 10:50:26 GMT</pubDate>
</item>

<item>
<title>article_3</title>
<link>http://example.com/3</link>
<description>description_3</description>
<pubDate>Wed, 19 Jul 2017 10:50:26 GMT</pubDate>
</item>

</channel>
</rss>
)";

	QXmlStreamReader xml;
	xml.addData(input);

	auto channel = std::make_unique<CChannel>(QUrl::fromUserInput("http://rssfeed"));

	CFeedParser::Parse(xml, channel.get());

	QVERIFY(channel->Title() == "RSS");
	QVERIFY(channel->Count() == 3);
	QVERIFY(channel->Title() == "RSS");

	int counter = 1;

	channel->ForEachArticle([&counter](const CArticle& article) {
		QString title = QString("article_%1").arg(counter);
		QString link = QString("http://example.com/%1").arg(counter);
		QString description = QString("description_%1").arg(counter);

		QVERIFY(article.Title() == title);
		QVERIFY(article.Link() == link);
		QVERIFY(article.Description() == description);

		counter++;
	});

}