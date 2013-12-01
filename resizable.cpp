#include "resizable.h"

Resizable::Resizable(QWidget *parent) :
    QWidget(parent)
{
    setMouseTracking(true);
}

Resizable::~Resizable() {
    delete draggableArea;
}

void Resizable::mousePressEvent(QMouseEvent *event) {
    if(draggableArea->contains(event->pos()) && (event->buttons() & Qt::LeftButton)) {
        previousMousePosition = event->pos();
        resizeStarted = true;
    }
}

void Resizable::mouseMoveEvent(QMouseEvent *event) {
    if(resizeStarted) {
        int delta = event->pos().x() - previousMousePosition.x();
        previousMousePosition = event->pos();
        if(geometry().width() + delta > 0)
            setFixedWidth(geometry().width() + delta);
    } else {
        if(draggableArea->contains(event->pos())) {
            setCursor(Qt::SizeHorCursor);
        } else {
            setCursor(Qt::ArrowCursor);
        }
    }
}

void Resizable::mouseReleaseEvent(QMouseEvent *event) {
    if(resizeStarted) {
        if(draggableArea->contains(event->pos())) {
            setCursor(Qt::SizeHorCursor);
        } else {
            setCursor(Qt::ArrowCursor);
        }
        resizeStarted = false;
    }
}

void Resizable::resizeEvent(QResizeEvent *) {
    draggableArea = new QRect(
        rect().width() - 5 ,
        0,
        5,
        rect().height()
    );
}
