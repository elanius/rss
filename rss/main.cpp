#include "rss.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	rss w;
	w.show();
	return a.exec();
}
