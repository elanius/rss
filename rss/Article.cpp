#include "Article.h"



CArticle::CArticle(QString& title, QString& link, QString& date, QString& description) :
	title(title),
	link(link),
	date(date),
	description(description)
{
}


CArticle::CArticle(CArticle&& other)
{
	title = std::move(other.title);
	link = std::move(other.link);
	date = std::move(other.date);
	description = std::move(other.description);
}

CArticle::~CArticle()
{
}

