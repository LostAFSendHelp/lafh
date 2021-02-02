#include "PlannerItemCard.h"
#include "ui_PlannerItemCard.h"
#include "PlannerItemDetailsDialog.h"

PlannerItemCard::PlannerItemCard(QWidget *parent, const QString& title, const QString& description):
    QPushButton(parent),
    ui(new Ui::PlannerItemCard)
{
    ui->setupUi(this);
    ui->lblItemTitle->setText(title);
    ui->lblItemDescription->setText(description);

    QObject::connect(this,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onClick()));
}

PlannerItemCard::~PlannerItemCard()
{
    delete ui;
}

void PlannerItemCard::onPlannerItemUpdatedSlot(const QString& title, const QString& description) {
    ui->lblItemTitle->setText(title);
    ui->lblItemDescription->setText(description);
}

void PlannerItemCard::onClick() {
    PlannerItemDetailsDialog dialog{ this, ui->lblItemTitle->text(), ui->lblItemDescription->text() };

    QObject::connect(&dialog,
                     SIGNAL(onAcceptedSignal(const QString&, const QString&)),
                     this,
                     SLOT(onPlannerItemUpdatedSlot(const QString&, const QString&)));

    dialog.exec();
}
