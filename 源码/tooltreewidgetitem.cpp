#include "tooltreewidgetitem.h"


ToolTreeWidgetItem::ToolTreeWidgetItem(QTreeWidget *parent):QTreeWidgetItem()
{

}

ToolTreeWidgetItem::~ToolTreeWidgetItem()
{
//    delete  tool;
    //    tool=NULL;
}

void ToolTreeWidgetItem::ReloadData_tool(int index)
{
    itool.isUsing=1;
    itool.ToolName=this->text(0).data()->toLatin1();
}

_iTool ToolTreeWidgetItem::GetToolStruct(){
    return itool;
}


