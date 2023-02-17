#ifndef WPOINT_H
#define WPOINT_H


#include <QPoint>
#include <qnamespace.h>

class WPoint
{
public:
    WPoint();
    WPoint(const WPoint&);
    WPoint(int x, int y, Qt::MouseButton mb = Qt::MouseButton::NoButton, int delay = 0);
    WPoint(const QPoint& p, Qt::MouseButton mb = Qt::MouseButton::NoButton, int delay = 0);
    ~WPoint();

    WPoint operator-(const WPoint& aim) const;
    WPoint operator+(const WPoint& aim) const;
    WPoint operator=(const WPoint& src);
    bool operator==(const WPoint& aim) const;
    bool operator==(const QPoint& aim) const;

public:
    int X, Y;
    Qt::MouseButton Button;
    unsigned int Delay;

    inline int getDelay() const { return static_cast<int>(Delay); }

    double getFRangeTo(const WPoint& aim) const;
    int getRangeTo(const WPoint& aim) const;

};

#endif // WPOINT_H
