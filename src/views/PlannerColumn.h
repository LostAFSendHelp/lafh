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
    const QString mColumnName;

    explicit PlannerColumn(QWidget *parent = nullptr, const QString& columnName = QString("Column %0").arg(sCount));
    ~PlannerColumn();

private slots:
    void on_pbNew_clicked();
    void onPlannerItemCreatedSlot(const QString& title, const QString& description);

private:
    Ui::PlannerColumn *ui;

    void setupView();

    static uint16_t sCount;
};

#endif // PLANNERCOLUMN_H
