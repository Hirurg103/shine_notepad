#ifndef TIMELINE_H
#define TIMELINE_H

#include <QDockWidget>

namespace Ui {
class Timeline;
}

class Timeline : public QDockWidget
{
    Q_OBJECT

public:
    explicit Timeline(QWidget *parent = 0);
    ~Timeline();

private:
    Ui::Timeline *ui;
};

#endif // TIMELINE_H
