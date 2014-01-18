#ifndef CENTRAL_H
#define CENTRAL_H

#include <QWidget>
#include <QGridLayout>
#include "motions_table.h"
#include "viewport.h"
#include "timeline.h"

namespace Ui {
class Central;
}

class Central : public QWidget
{
    Q_OBJECT

public:
    explicit Central(QWidget *parent = 0);
    ~Central();

private:
    Ui::Central *ui;
    QGridLayout *layout;
    MotionsTable *motionsTable;
    Viewport *viewport;
    Timeline *timeline;
};

#endif // CENTRAL_H
