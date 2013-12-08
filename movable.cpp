#include "movable.h"

Movable::Movable(QWidget *parent) :
    QWidget(parent)
{
    setCursor(Qt::SizeHorCursor);
}

Movable::~Movable()
{
    delete delta;
}

void Movable::mousePressEvent(QMouseEvent *event) {
    event->accept();
    if(isWindow())
        offset = event->globalPos() - event->pos();
    else
        offset = event->pos();
}

void Movable::mouseMoveEvent(QMouseEvent *event) {
    event->accept();
    delta = new  QPoint((event->pos() - offset).x(), 0);
    if(isWindow())
        move(pos() + *delta);
    else
        move(mapToParent(*delta));
    emit positionChanged(delta);
}

void Movable::mouseReleaseEvent(QMouseEvent *event) {
    event->accept();
    offset = event->pos();
}

