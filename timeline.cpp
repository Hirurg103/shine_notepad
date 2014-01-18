#include "timeline.h"
#include "ui_timeline.h"

Timeline::Timeline(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Timeline)
{
    ui->setupUi(this);
    setWindowTitle(tr("Timeline"));
}

Timeline::~Timeline()
{
    delete ui;
}
