#ifndef MOVABLE_H
#define MOVABLE_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Movable;
}

class Movable : public QWidget
{
    Q_OBJECT

public:
    explicit Movable(QWidget *parent = 0);
    ~Movable();

signals:
    void positionChanged(QPoint *);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QPoint offset;
    QPoint *delta;
};

#endif // MOVABLE_H
