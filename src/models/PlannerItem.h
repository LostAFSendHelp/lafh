#ifndef PLANNERITEM_H
#define PLANNERITEM_H

#include <cstdint>
#include <QString>

class PlannerItem
{
public:
    const uint32_t mID;
    QString mTitle;
    QString mDescription;

    explicit PlannerItem(const QString& title, const QString& description);

    const QString& getTitle() const;
    const QString& getDescription() const;

private:

    static uint32_t sCount;
};

#endif // PLANNERITEM_H
