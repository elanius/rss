#include <QFile>

#include "RssReader.h"




CRssReader::CRssReader() : fileName("Channels.rss")
{
}


CRssReader::~CRssReader()
{
}


bool CRssReader::AddChannel(TChannel&& channel)
{
	auto found = std::find_if(channels.begin(), channels.end(), [&channel](TChannel& ch) {
		return channel->Url() == ch->Url();
	});

	if (found == channels.end())
	{
		connect(channel.get(), &CChannel::NewChannel, this, &CRssReader::onNewChannel);
		channels.push_back(std::move(channel));
		return true;
	}

	return false;
}


bool CRssReader::RemoveChannel(const CChannel* channel)
{
	auto found = std::find_if(channels.begin(), channels.end(), [channel](TChannel& ch) {
		return channel == ch.get();
	});

	if (found != channels.end())
	{
		channels.erase(found);
		return true;
	}

	return false;
}


void CRssReader::RefreshAll()
{
	for (auto& ch : channels)
	{
		ch->Refresh();
	}
}


bool CRssReader::SaveToFile()
{
	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream stream(&file);
		for (auto& ch : channels)
		{
			stream << ch->Url().toString() << "\n";
		}
	}

	return true;
}

bool CRssReader::LoadFromFile()
{
	QFile file(fileName);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream(&file);

		while (stream.atEnd() == false)
		{
			AddChannel(std::make_unique<CChannel>(QUrl::fromUserInput(stream.readLine())));
		}
	}

	return true;
}