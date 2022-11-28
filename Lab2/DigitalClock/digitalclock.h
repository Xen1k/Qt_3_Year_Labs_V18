#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "DigitalClock_global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class XenonForm; }
QT_END_NAMESPACE


class DIGITALCLOCK_EXPORT DigitalClock : public QWidget
{
    Q_OBJECT

public:
    DigitalClock();
signals:
    void timeout();
private:
    Ui::XenonForm *m_ui;
    QVBoxLayout *m_layout;
    QLabel *m_TimeText;

};

#endif // DIGITALCLOCK_H
