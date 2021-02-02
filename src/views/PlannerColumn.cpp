#include "PlannerColumn.h"
#include "ui_PlannerColumn.h"
#include "CreatePlannerItemDialog.h"
#include "PlannerItemCard.h"

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
    CreatePlannerItemDialog dialog{ this };
    QObject::connect(&dialog,
                     SIGNAL(onPlannerItemCreatedSignal(const QString&, const QString&)),
                     this,
                     SLOT(onPlannerItemCreatedSlot(const QString&, const QString&)));
    dialog.exec();
}

void PlannerColumn::onPlannerItemCreatedSlot(const QString& title, const QString& description) {
    auto card = new PlannerItemCard{ nullptr, title, description };
    ui->vLayoutItems->addWidget(card);
}
