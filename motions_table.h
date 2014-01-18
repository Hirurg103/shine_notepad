#ifndef MOTIONS_TABLE_H
#define MOTIONS_TABLE_H

#include <QWidget>
#include <QTableView>

namespace Ui {
    class MotionsTable;
}

class MotionsTable : public QTableView
{
    Q_OBJECT

public:
    explicit MotionsTable(QWidget *parent = 0);
    ~MotionsTable();

private:
    Ui::MotionsTable *ui;
};

#endif // MOTIONS_TABLE_H
