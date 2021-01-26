#include "AddColumnView.h"
#include "ui_AddColumnView.h"

AddColumnView::AddColumnView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddColumnView)
{
    ui->setupUi(this);
    setupView();
}

AddColumnView::~AddColumnView()
{
    delete ui;
}

void AddColumnView::on_pbConfirm_clicked()
{
    auto columnName = ui->leditColumnName->text();
    if (columnName.size()) {
        ui->leditColumnName->setText("");
        emit onColumnCreatedSignal(columnName);
    }
}

void AddColumnView::setupView() {
    ui->leditColumnName->setPlaceholderText("Column name here...");
}
