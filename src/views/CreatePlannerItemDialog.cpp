#include "CreatePlannerItemDialog.h"
#include "ui_CreatePlannerItemDialog.h"

CreatePlannerItemDialog::CreatePlannerItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePlannerItemDialog)
{
    ui->setupUi(this);
}

CreatePlannerItemDialog::~CreatePlannerItemDialog()
{
    delete ui;
}

void CreatePlannerItemDialog::on_buttonBoxMain_accepted()
{
    emit onPlannerItemCreatedSignal(ui->leditItemTitle->text(), QString(""));
}
