#include "stopwatch.h"
#include <QVBoxLayout>
#include <QTime>

Stopwatch::Stopwatch(QWidget *parent): QWidget(parent), time(0)
{
	display = new QLabel("00:00:00.000", this);
	display->setAlignment(Qt::AlignCenter);
	display->setStyleSheet("font-size: 24px; font-family: monospace; background-color: #f0f0f0; padding: 10px; border: 2px solid #ccc;");

	startBtn = new QPushButton("Start", this);
	stopBtn = new QPushButton("Stop", this);
	resetBtn = new QPushButton("Reset", this);

	startBtn->setMinimumSize(100, 40);
	stopBtn->setMinimumSize(100, 40);
	resetBtn->setMinimumSize(100, 40);

	startBtn->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; font-size: 14px; } QPushButton:hover { background-color: #45a049; }");
	stopBtn->setStyleSheet("QPushButton { background-color: #f44336; color: white; font-size: 14px; } QPushButton:hover { background-color: #da190b; }");
	resetBtn->setStyleSheet("QPushButton { background-color: #008CBA; color: white; font-size: 14px; } QPushButton:hover { background-color: #007B9A; }");

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(display);
	layout->addWidget(startBtn);
	layout->addWidget(stopBtn);
	layout->addWidget(resetBtn);
	setLayout(layout);

	setWindowTitle("Stopwatch");
	setFixedSize(500, 300);

	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &Stopwatch::updateDisplay);
	connect(startBtn, &QPushButton::clicked, this, &Stopwatch::start);
	connect(stopBtn, &QPushButton::clicked, this, &Stopwatch::stop);
	connect(resetBtn, &QPushButton::clicked, this, &Stopwatch::reset);
}

void Stopwatch::start()
{
	if (!timer->isActive())
	{
		timer->start(10);
		startBtn->setText("Pause");
	}
	else
	{
		timer->stop();
		startBtn->setText("Start");
	}
}

void Stopwatch::stop()
{
	timer->stop();
	startBtn->setText("Start");
}

void Stopwatch::reset()
{
	timer->stop();
	time = 0;
	display->setText("00:00:00.000");
	startBtn->setText("Start");
}

void Stopwatch::updateDisplay()
{
	time += 10;
	QTime t(0, 0, 0);
	t = t.addMSecs(time);
	display->setText(t.toString("hh:mm:ss.zzz"));
}
