#include "PlannerItem.h"

uint32_t PlannerItem::sCount = 0;

PlannerItem::PlannerItem(const QString& title, const QString& description):
    mID(++sCount),
    mTitle(title),
    mDescription(description)
{

}
