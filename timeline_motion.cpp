#include "timeline_motion.h"

TimelineMotion::TimelineMotion(QWidget *parent) :
    QWidget(parent)
{
    p_movable = new Movable(this);
    p_movable->setFixedWidth(maxMovableWidth);
    setMovablePos();
    connect(p_movable, SIGNAL(positionChanged(QPoint *)), this, SLOT(changeSize(QPoint *)));
}

TimelineMotion::~TimelineMotion() {
    delete p_movable;
    delete newSize;
}

void TimelineMotion::changeSize(QPoint *delta) {
    newSize = new QSize(size() + QSize(delta->x(), delta->y()));
    if(newSize->width() > 1)
    {
        resize(*newSize);
        emit sizeChanged(newSize);
    } else
        setMovablePos();
}

void TimelineMotion::resizeEvent(QResizeEvent *event) {
    if(width() < 2 * maxMovableWidth)
        p_movable->setFixedWidth(width() / 2);
    else
        p_movable->setFixedWidth(maxMovableWidth);

    setMovablePos();
}

void TimelineMotion::setMovablePos() {
    p_movable->setGeometry(width() - p_movable->width(), 0, p_movable->width(), height());
}

Movable *TimelineMotion::movable() {
    return p_movable;
}
