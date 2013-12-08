#ifndef RESIZABLE_H
#define RESIZABLE_H

#include <QWidget>
#include "movable.h"

class Resizable : public QWidget
{
    Q_OBJECT

public:
    explicit Resizable(QWidget *parent = 0);
    ~Resizable();
    Movable *movable(void);

signals:
    void sizeChanged(QSize *);

private slots:
    void changeSize(QPoint *);

protected:
    void resizeEvent(QResizeEvent *);

private:
    void setMovablePos();

private:
    int maxMovableWidth = 5;
    Movable *p_movable;
    QSize *newSize;
};

#endif // RESIZABLE_H
