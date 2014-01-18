#include "motions_table.h"
#include "ui_motions_table.h"

MotionsTable::MotionsTable(QWidget *parent) :
    QTableView(parent),
    ui(new Ui::MotionsTable)
{
    ui->setupUi(this);
    setFixedHeight(500);
}

MotionsTable::~MotionsTable()
{
    delete ui;
}
