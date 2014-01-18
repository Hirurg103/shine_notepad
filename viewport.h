#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QWidget>
#include <QGLWidget>

namespace Ui {
class Viewport;
}

class Viewport : public QGLWidget
{
    Q_OBJECT

public:
    explicit Viewport(QWidget *parent = 0);
    ~Viewport();

private:
    Ui::Viewport *ui;
};

#endif // VIEWPORT_H
