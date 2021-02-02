#include "PlannerItemDetailsDialog.h"
#include "ui_PlannerItemDetailsDialog.h"

PlannerItemDetailsDialog::PlannerItemDetailsDialog(QWidget *parent, const QString& title, const QString& description):
    QDialog(parent),
    ui(new Ui::PlannerItemDetailsDialog)
{
    ui->setupUi(this);
    ui->leditItemTitle->setText(title);
    ui->pleditItemDescription->setPlainText(description);
}

PlannerItemDetailsDialog::~PlannerItemDetailsDialog()
{
    delete ui;
}

void PlannerItemDetailsDialog::on_buttonBoxMain_accepted()
{
    emit onAcceptedSignal(ui->leditItemTitle->text(), ui->pleditItemDescription->toPlainText());
}
