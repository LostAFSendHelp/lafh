#ifndef PLANNERITEMCARD_H
#define PLANNERITEMCARD_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class PlannerItemCard;
}

class PlannerItemCard : public QPushButton
{
    Q_OBJECT

public:
    explicit PlannerItemCard(QWidget *parent = nullptr, const QString& title = "<Title goes here>", const QString& description = "<Description goes here>");
    ~PlannerItemCard();

private slots:
    void onPlannerItemUpdatedSlot(const QString& title, const QString& description);
    void onClick();

private:
    Ui::PlannerItemCard *ui;

};

#endif // PLANNERITEMCARD_H
