#include "selectableListedObject.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QListWidgetItem>
#include <QGraphicsView>

SelectableListedObject* SelectableListedObject::lastSelectedObject;
QString SelectableListedObject::selectedButtonStyle = "background-color: rgba(46, 204, 113, 0.4);";
QString SelectableListedObject::defaultButtonStyle = "background-color: rgba(255, 255, 255, 1.0);";

SelectableListedObject::SelectableListedObject(QString buttonText, QGraphicsItem *graphicsItem)
{
    QListWidget *listWidget = MainWindow::GetInstance().ui->itemsList;
    QGraphicsView *graphicsView = MainWindow::GetInstance().ui->graphicsView;
    // Add select button
    selectButton = new QPushButton();
    selectButton->setText("Select " + buttonText);
    selectButton->setStyleSheet(defaultButtonStyle);
    QListWidgetItem* selectButtonItem = new QListWidgetItem(listWidget);
    QObject::connect(selectButton, &QPushButton::clicked, [=]() {
        graphicsItem->setSelected(true);
        HightlightObjectsButton();
    });
    // Add remove button
    removeButton = new QPushButton();
    removeButton->setText("Remove " + buttonText);
    removeButton->setStyleSheet(defaultButtonStyle);
    QListWidgetItem* removeButtonItem = new QListWidgetItem(listWidget);
    QObject::connect(removeButton, &QPushButton::clicked, [=]() {
        listWidget->removeItemWidget(removeButtonItem);
        listWidget->removeItemWidget(selectButtonItem);
        graphicsView->scene()->removeItem(graphicsItem);
        delete removeButtonItem;
        delete removeButton;
        delete selectButtonItem;
        delete selectButton;
        if(lastSelectedObject == this) lastSelectedObject = nullptr;
    });
    listWidget->setItemWidget(removeButtonItem, removeButton);
    listWidget->setItemWidget(selectButtonItem, selectButton);
}

void SelectableListedObject::DiselectLast()
{
    if(lastSelectedObject)
    {
        lastSelectedObject->removeButton->setStyleSheet(defaultButtonStyle);
        lastSelectedObject->selectButton->setStyleSheet(defaultButtonStyle);
        lastSelectedObject = nullptr;
    }
}

void SelectableListedObject::HightlightObjectsButton()
{
    removeButton->setStyleSheet(selectedButtonStyle);
    selectButton->setStyleSheet(selectedButtonStyle);
    DiselectLast();
    lastSelectedObject = this;

}
