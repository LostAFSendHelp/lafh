#ifndef PLANNERCOLUMN_H
#define PLANNERCOLUMN_H

#include <QWidget>

namespace Ui {
class PlannerColumn;
}

class PlannerColumn : public QWidget
{
    Q_OBJECT

public:
    explicit PlannerColumn(QWidget *parent = nullptr);
    ~PlannerColumn();

private slots:
    void on_pbNew_clicked();

private:
    Ui::PlannerColumn *ui;

    void setupView();
};

#endif // PLANNERCOLUMN_H
