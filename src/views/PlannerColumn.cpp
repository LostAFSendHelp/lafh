#include "PlannerColumn.h"
#include "ui_PlannerColumn.h"

uint16_t PlannerColumn::sCount = 0;

PlannerColumn::PlannerColumn(QWidget *parent, const QString& columnName) :
    QWidget(parent),
    mColumnName(columnName),
    ui(new Ui::PlannerColumn)
{
    ui->setupUi(this);
    ++sCount;
    setupView();
}

PlannerColumn::~PlannerColumn() {
    delete ui;
}

void PlannerColumn::setupView() {
    ui->vLayoutGrBoxDude->setAlignment(Qt::AlignTop);
    ui->vLayoutItems->setAlignment(Qt::AlignTop);
    ui->grBoxDude->setTitle(mColumnName);
}

void PlannerColumn::on_pbNew_clicked() {
    ui->vLayoutItems->insertWidget(0, new QPushButton{ "My dude" });

#ifdef QT_DEBUG
    qDebug() << objectName() << " size " << size()
             << ui->grBoxDude->objectName() << " size " << ui->grBoxDude->size() << "\n";
#endif
}
