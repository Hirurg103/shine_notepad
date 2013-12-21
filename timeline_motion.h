#ifndef TIMELINE_MOTION
#define TIMELINE_MOTION

#include <QWidget>
#include "movable.h"

class TimelineMotion : public Movable
{
    Q_OBJECT

public:
    explicit TimelineMotion(QWidget *parent = 0);
    ~TimelineMotion();
    Movable *movable(void);

signals:
    void sizeChanged(QSize *);

private slots:
    void changeSize(QPoint *);

protected:
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    void setMovablePos();

private:
    int maxMovableWidth = 5;
    Movable *p_movable;
    QSize *newSize;
};

#endif // TIMELINE_MOTION_H
