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
    ui->vLayoutGrBoxDude->setAlignment(Qt::AlignTop);
    ui->vLayoutItems->setAlignment(Qt::AlignTop);
}

void PlannerColumn::on_pbNew_clicked() {
    ui->vLayoutItems->insertWidget(0, new QPushButton{ "My dude" });

#ifdef QT_DEBUG
    qDebug() << objectName() << " size " << size()
             << ui->grBoxDude->objectName() << " size " << ui->grBoxDude->size() << "\n";
#endif
}
