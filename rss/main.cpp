#include "rss.h"
#include <QtWidgets/QApplication>

#ifndef _UNITTEST
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	rss w;
	w.show();
	return a.exec();
}
#else
#include "Channel.h"
#include "FeedParser.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	a.setAttribute(Qt::AA_Use96Dpi, true);
	QTEST_DISABLE_KEYPAD_NAVIGATION;

	int status = 0;

	{
		CChannel channel(QUrl::fromUserInput("http://feeds.bbci.co.uk/news/rss.xml?edition=uk"));
		status |= QTest::qExec(&channel, argc, argv);
	}

	{
		CFeedParser parser;
		status |= QTest::qExec(&parser, argc, argv);
	}

	return status;
}
#endif
