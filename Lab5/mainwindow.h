#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow &GetInstance();
    ~MainWindow();
    Ui::MainWindow *ui;
protected:
    MainWindow(QWidget *parent = nullptr);
private slots:
    void on_addClockButton_clicked();

    void on_diselectButton_clicked();

    void on_addTextButton_clicked();

    void on_addFlowerButton_clicked();

private:
    QGraphicsScene *scene;
    MainWindow(MainWindow const&);
    void operator=(MainWindow const&);
};

#endif // MAINWINDOW_H
