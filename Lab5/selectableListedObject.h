#ifndef SELECTABLELISTEDOBJECT_H
#define SELECTABLELISTEDOBJECT_H


#include <QPushButton>
#include <functional>
#include <QListWidget>
#include <QGraphicsItem>

// Represents button in list view for editing and removing graphics object
class SelectableListedObject
{
protected:
    QPushButton *removeButton;
    QPushButton *selectButton;
    static QString selectedButtonStyle;
    static QString defaultButtonStyle;
    void HightlightObjectsButton();
public:
    SelectableListedObject(QString buttonText, QGraphicsItem *graphicsItem);
    static SelectableListedObject *lastSelectedObject;
    static void DiselectLast();
};
#endif // SELECTABLELISTEDOBJECT_H
