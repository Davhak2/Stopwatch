#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class Stopwatch : public QWidget
{
	Q_OBJECT

public:
	explicit Stopwatch(QWidget *parent = nullptr);

private slots:
	void start();
	void stop();
	void reset();
	void updateDisplay();

private:
	QLabel *display;
	QPushButton *startBtn;
	QPushButton *stopBtn;
	QPushButton *resetBtn;
	QTimer *timer;
	int time;
};

#endif
