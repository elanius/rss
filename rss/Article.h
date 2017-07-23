#pragma once

#include <QString>

class CArticle
{
public:
	CArticle(QString& title, QString& link, QString& date, QString& description);
	CArticle(CArticle&& other);
	~CArticle();

	const QString& Title() const { return title; };
	const QString& Description() const { return description; };
	const QString& Link() const { return link; };

private:

	QString title;
	QString date;
	QString link;
	QString description;
};

