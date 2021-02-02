#ifndef PLANNERITEMDETAILSDIALOG_H
#define PLANNERITEMDETAILSDIALOG_H

#include <QDialog>

namespace Ui {
class PlannerItemDetailsDialog;
}

class PlannerItemDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlannerItemDetailsDialog(QWidget *parent = nullptr, const QString& title = "<Title goes here>", const QString& description = "<Description goes here>");
    ~PlannerItemDetailsDialog();

signals:
    void onAcceptedSignal(const QString& title, const QString& description);

private slots:
    void on_buttonBoxMain_accepted();

private:
    Ui::PlannerItemDetailsDialog *ui;
};

#endif // PLANNERITEMDETAILSDIALOG_H
