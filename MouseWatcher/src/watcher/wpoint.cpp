#include "wpoint.h"

#include <cmath>

WPoint::WPoint() :
    X(0), Y(0),
    Button(Qt::MouseButton::NoButton),
    Delay(0)
{
}

WPoint::WPoint(const WPoint& src) :
    X(src.X), Y(src.Y),
    Button(src.Button),
    Delay(src.Delay)
{
}

WPoint::WPoint(int x, int y, Qt::MouseButton mb, int delay) :
    X(x), Y(y), Button(mb),
    Delay(static_cast<unsigned int>(delay))
{
}

WPoint::WPoint(const QPoint& p, Qt::MouseButton mb, int delay) :
    X(p.x()), Y(p.y()), Button(mb),
    Delay(static_cast<unsigned int>(delay))
{
}

WPoint::~WPoint()
{}

WPoint WPoint::operator-(const WPoint& aim) const
{
    WPoint out;
    out.X = X - aim.X;
    out.Y = Y - aim.Y;
    return out;
}

WPoint WPoint::operator+(const WPoint& aim) const
{
    WPoint out;
    out.X = X - aim.X;
    out.Y = Y - aim.Y;
    out.Delay = Delay + aim.Delay;
    return out;
}

WPoint WPoint::operator=(const WPoint& src)
{
    X = src.X;
    Y = src.Y;
    Button = src.Button;
    Delay = src.Delay;
    return *this;
}

bool WPoint::operator==(const WPoint& aim) const
{
    bool bX = X == aim.X;
    bool bY = Y == aim.Y;

    return bX & bY;
}

bool WPoint::operator==(const QPoint& aim) const
{
    bool bX = X == aim.x();
    bool bY = Y == aim.y();

    return bX & bY;
}

double WPoint::getFRangeTo(const WPoint& aim) const
{
    using namespace std;

    WPoint vectr = aim - *this;

    return sqrt(pow(vectr.X, 2) + pow(vectr.Y, 2));
}

int WPoint::getRangeTo(const WPoint& aim) const
{
    using namespace std;

    WPoint vectr = aim - *this;

    double R = sqrt(pow(vectr.X, 2) + pow(vectr.Y, 2));

    return int(R);
}
