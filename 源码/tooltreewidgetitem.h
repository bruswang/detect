#ifndef TOOLTREEWIDGETITEM_H
#define TOOLTREEWIDGETITEM_H

#include <QObject>
#include <QTreeWidgetItem>
#include "my_tool.h"
#include "My_Struct.h"
class ToolTreeWidgetItem:public QObject ,public QTreeWidgetItem
{
    Q_OBJECT
public:
    ToolTreeWidgetItem(QTreeWidget *parent=nullptr);
    ~ToolTreeWidgetItem();
    void ReloadData_tool(int index);
    _iTool GetToolStruct();
private:
    My_Tool *tool;
    _iTool itool;

};

#endif // TOOLTREEWIDGETITEM_H
