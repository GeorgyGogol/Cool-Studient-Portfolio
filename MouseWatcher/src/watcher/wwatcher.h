#ifndef WWATCHER_H
#define WWATCHER_H


#include <QList>
#include "wpoint.h"

class WWatcher
{
public:
    WWatcher();

private:
    QList<WPoint> ListPoints;
    QList<WPoint>::iterator it;

    void correctAddPoint(const WPoint& point);

public:
    void AddPoint(const QPoint& point);
    void AddPoint(QPoint* pPoint);

    void AddPoint(const WPoint& point);
    void AddPoint(WPoint* pPoint);

    WPoint* First();
    WPoint* Next();
    WPoint* Prev();
    WPoint* Last();
    WPoint* Current() const;

    bool isEnd() const;
    bool isBegin() const;

    int CountPoints() const noexcept;
};

#endif // WWATCHER_H
