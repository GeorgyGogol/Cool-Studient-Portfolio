#include "wwatcher.h"

WWatcher::WWatcher()
{
    it = ListPoints.begin();
}

void WWatcher::correctAddPoint(const WPoint& point)
{
    bool isNew = true;
    for (auto i = ListPoints.begin(); i != ListPoints.end(); ++i) {
        if ((*i) == point) {
            i->Delay++;
            isNew = false;
        }
    }

    if (isNew) ListPoints.push_back(point);
}

void WWatcher::AddPoint(const QPoint& point)
{
    correctAddPoint(point);
}

void WWatcher::AddPoint(QPoint* pPoint)
{
    correctAddPoint(*pPoint);
}

void WWatcher::AddPoint(const WPoint& point)
{
    correctAddPoint(point);
}

void WWatcher::AddPoint(WPoint* pPoint)
{
    correctAddPoint(*pPoint);
}

WPoint* WWatcher::First()
{
    it = ListPoints.begin();
    return &ListPoints.first();
}

WPoint* WWatcher::Next()
{
    if (!isEnd()) {
        ++it;
    }
    return Current();
}

WPoint* WWatcher::Prev()
{
    if (!isBegin()) {
        --it;
    }
    return Current();
}

WPoint* WWatcher::Last()
{
    if (ListPoints.size() == 0) return nullptr;
    it = ListPoints.end();
    return &ListPoints.back();
}

WPoint* WWatcher::Current() const
{
    return &(*it);
}

bool WWatcher::isEnd() const
{
    return it == ListPoints.end();
}

bool WWatcher::isBegin() const
{
    return it == ListPoints.begin();
}

int WWatcher::CountPoints() const noexcept
{
    return ListPoints.count();
}
