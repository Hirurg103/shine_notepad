#ifndef RESIZABLE_H
#define RESIZABLE_H

#include <QWidget>
#include <QMouseEvent>

class Resizable : public QWidget
{
    Q_OBJECT

public:
    explicit Resizable(QWidget *parent = 0);
    ~Resizable();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);

private:
    QRect *draggableArea;
    QPoint previousMousePosition;
    int startWidth;
    bool resizeStarted = false;
};

#endif // RESIZABLE_H
