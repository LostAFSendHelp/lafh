#include "PlannerColumn.h"
#include "ui_PlannerColumn.h"

PlannerColumn::PlannerColumn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlannerColumn)
{
    ui->setupUi(this);
    setupView();
}

PlannerColumn::~PlannerColumn() {
    delete ui;
}

void PlannerColumn::setupView() {
    ui->vLayout->setAlignment(Qt::AlignTop);
    ui->verticalLayout->setAlignment(Qt::AlignTop);
}

void PlannerColumn::on_pbNew_clicked() {
    ui->vLayout->insertWidget(0, new QPushButton{ "My dude" });
    qInfo() << "Dude width " << size().width() << "Dude height " << size().height() << "\n";
}
