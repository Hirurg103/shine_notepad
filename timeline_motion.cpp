#include "timeline_motion.h"

TimelineMotion::TimelineMotion(QWidget *parent) :
    Movable(parent)
{
    p_movable = new Movable(this);
    p_movable->setFixedWidth(maxMovableWidth);
    setMovablePos();
    setCursor(Qt::OpenHandCursor);
    connect(p_movable, SIGNAL(positionChanged(QPoint *)), this, SLOT(changeSize(QPoint *)));
}

TimelineMotion::~TimelineMotion() {
    delete newSize;
    delete p_movable;
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

void TimelineMotion::mousePressEvent(QMouseEvent *event) {
    Movable::mousePressEvent(event);
    setCursor(Qt::ClosedHandCursor);
}

void TimelineMotion::mouseReleaseEvent(QMouseEvent *event) {
    Movable::mouseReleaseEvent(event);
    setCursor(Qt::OpenHandCursor);
}

void TimelineMotion::setMovablePos() {
    p_movable->setGeometry(width() - p_movable->width(), 0, p_movable->width(), height());
}

Movable *TimelineMotion::movable() {
    return p_movable;
}
