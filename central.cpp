#include "central.h"
#include "ui_central.h"

Central::Central(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Central)
{
    ui->setupUi(this);
    layout = new QGridLayout(this);

    motionsTable = new MotionsTable(this);
    layout->addWidget(motionsTable, 1, 1, 1, 1, Qt::AlignTop);

    viewport = new Viewport(this);
    layout->addWidget(viewport, 1, 2, 1, 1, Qt::AlignTop);

    timeline = new Timeline(this);
    layout->addWidget(timeline, 2, 1, 1, 2);
}

Central::~Central()
{
    delete ui;
    delete layout;
    delete motionsTable;
    delete viewport;
    delete timeline;
}
