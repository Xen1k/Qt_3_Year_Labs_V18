#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QTabWidget>

class MainWindow
{
public:
    MainWindow();
    void Show();
private:
    QGridLayout *m_layout;
    QWidget *m_window;
    QTabWidget *m_TabWidget;
    void InitializeWindow();
    QWidget* GetGameCard(QString title, QString image);
};

#endif // MAINWINDOW_H
