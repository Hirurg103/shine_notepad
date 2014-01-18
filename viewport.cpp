#include "viewport.h"
#include "ui_viewport.h"

Viewport::Viewport(QWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::Viewport)
{
    ui->setupUi(this);
    setFixedSize(800, 500);
}

Viewport::~Viewport()
{
    delete ui;
}
