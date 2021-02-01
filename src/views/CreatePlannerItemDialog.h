#ifndef CREATEPLANNERITEMDIALOG_H
#define CREATEPLANNERITEMDIALOG_H

#include <QDialog>

namespace Ui {
class CreatePlannerItemDialog;
}

class CreatePlannerItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePlannerItemDialog(QWidget *parent = nullptr);
    ~CreatePlannerItemDialog();

signals:
    void onPlannerItemCreatedSignal(const QString& title, const QString& description);

private slots:
    void on_buttonBoxMain_accepted();

private:
    Ui::CreatePlannerItemDialog *ui;
};

#endif // CREATEPLANNERITEMDIALOG_H
