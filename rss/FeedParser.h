#pragma once

#include <QObject>
#include <QXmlStreamReader>
#include "RssReader.h"

class CFeedParser : public QObject
{
	Q_OBJECT;
public:
	CFeedParser();
	~CFeedParser();

	static bool Parse(QXmlStreamReader& xml, CChannel* channel);

private slots :
	void testParser();
};

