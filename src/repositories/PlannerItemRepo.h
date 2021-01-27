#ifndef PLANNERITEMREPO_H
#define PLANNERITEMREPO_H

#include <QObject>
#include <models/PlannerItem.h>

class PlannerItemRepo : public QObject
{
    Q_OBJECT
public:
    explicit PlannerItemRepo();

    void addPlannerItem(const PlannerItem& plannerItem);
    void removePlannerItem(const PlannerItem& plannerItem);
    void removePlannerItemById(uint32_t id);

signals:

private:
    QList<QList<PlannerItem>> mPlannerItems;
};

#endif // PLANNERITEMREPO_H
