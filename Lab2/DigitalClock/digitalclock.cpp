#include "digitalclock.h"
#include <QTimer>
#include <QTime>
#include <QTextEdit>

DigitalClock::DigitalClock()
{

    m_layout = new QVBoxLayout(this);
    setLayout(m_layout);

    m_TimeText = new QLabel();
    m_TimeText->setStyleSheet("font-size: 18pt;");
    m_layout->addWidget(m_TimeText);
    QTimer *timer = new QTimer();

    QPushButton* switchToStopwatchButton = new QPushButton("Stopwatch");
    m_layout->addWidget(switchToStopwatchButton);
    connect(switchToStopwatchButton, &QPushButton::clicked, [=]() {
        disconnect(timer, 0, 0, 0);
        connect(timer, &QTimer::timeout, [=]() { m_TimeText->setText(QString::number(m_TimeText->text().toInt() + 1)); timeout(); });
    });

    QTextEdit* textEdit = new QTextEdit();
    m_layout->addWidget(textEdit);
    textEdit->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    textEdit->setMaximumHeight(40);

    QPushButton* switchToTimerButton = new QPushButton("Timer");
    m_layout->addWidget(switchToTimerButton);
    connect(switchToTimerButton, &QPushButton::clicked, [=]() {
        QRegExp re("\\d*");  // Check if string has only numbers
        if(textEdit->toPlainText().length() == 0 || !re.exactMatch(textEdit->toPlainText()) || textEdit->toPlainText().toInt() == 0)
            return;
        disconnect(timer, 0, 0, 0);
        m_TimeText->setText(textEdit->toPlainText());
        connect(timer, &QTimer::timeout, [=]() {
            int timeLeft = m_TimeText->text().toInt() - 1;
            if(timeLeft <= 0)
            {
                timeout();
                disconnect(timer, 0, 0, 0);
            }
            m_TimeText->setText(QString::number(timeLeft));
        });
    });

    QPushButton* switchToWatchButton = new QPushButton("Watch");
    m_layout->addWidget(switchToWatchButton);

    connect(switchToWatchButton, &QPushButton::clicked, [=]() {
        disconnect(timer, 0, 0, 0);
        connect(timer, &QTimer::timeout, [=]() { m_TimeText->setText(QTime::currentTime().toString("hh:mm:ss")); });
    });
    timer->start(1000);

}
