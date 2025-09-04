#include <QApplication>
#include "stopwatch.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	Stopwatch w;
	w.show();
	return app.exec();
}
