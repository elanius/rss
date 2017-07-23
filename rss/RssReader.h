#pragma once

#include <vector>
#include <QObject>
#include "Channel.h"

class CRssReader : public QObject
{
	Q_OBJECT

public:
	CRssReader();
	~CRssReader();

	bool AddChannel(TChannel&& channel);
	bool RemoveChannel(const CChannel* channel);
	void RefreshAll();

	bool SaveToFile();
	bool LoadFromFile();

public slots:
	void onNewChannel(CChannel* channel) { NewChannel(channel); };

signals:
	void NewChannel(CChannel* channel);

private:
	std::vector<TChannel> channels;
	QString fileName;
};

