#include "../wwatcher.h"

bool Test_Points()
{
    bool result = true;
    WWatcher* aim = new WWatcher();

    QPoint p1(1, 1);
    QPoint p2(2, 2);
    QPoint p3(3, 3);

    aim->AddPoint(p1);
    aim->AddPoint(p2);
    aim->AddPoint(p3);

    result *= aim->CountPoints() == 3;

    if (result) {
        QPoint* pPoint;

        pPoint = aim->First();
        result *= *pPoint == p1;

        pPoint = aim->Current();
        result *= *pPoint == p1;

        pPoint = aim->Next();
        result *= *pPoint == p2;

        pPoint = aim->Current();
        result *= *pPoint == p2;

        pPoint = aim->Last();
        result *= *pPoint == p3;

        pPoint = aim->Current();
        result *= *pPoint == p3;

        pPoint = aim->Prev();
        result *= *pPoint == p2;
    }

    delete aim;
    return result;
}

bool Test_isEnd()
{
    bool result = true;
    WWatcher* aim = new WWatcher();

    QPoint p1(1, 1);
    QPoint p2(2, 2);
    QPoint p3(3, 3);

    aim->AddPoint(p1);
    aim->AddPoint(p2);
    aim->AddPoint(p3);

    aim->Last();

    result *= aim->isEnd();

    delete aim;
    return result;
}

bool Test_isBegin()
{
    bool result = true;
    WWatcher* aim = new WWatcher();

    QPoint p1(1, 1);
    QPoint p2(2, 2);
    QPoint p3(3, 3);

    aim->AddPoint(p1);
    aim->AddPoint(p2);
    aim->AddPoint(p3);

    aim->First();

    result *= aim->isBegin();

    delete aim;
    return result;
}

bool Test_AddPointPointer()
{
    bool result = true;
    WWatcher* aim = new WWatcher();

    QPoint* p1 = new QPoint(1, 1);
    aim->AddPoint(p1);
    aim->AddPoint(p1);
    aim->AddPoint(p1);

    for (QPoint* f = aim->First(); !aim->isEnd(); f = aim->Next()) {
        result *= f != p1;
        result *= *f == *p1;
    }

    delete aim;
    return result;
}
