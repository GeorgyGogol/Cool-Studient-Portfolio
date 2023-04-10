#ifndef WINDOWPOINTKEEPER_H
#define WINDOWPOINTKEEPER_H

template <class TyPoint>
class WindowPointKeeper
{
protected:
    WindowPointKeeper(TyPoint* pWindow) : PWindow(pWindow) {}
    ~WindowPointKeeper() { PWindow = nullptr; }

protected:
    TyPoint* PWindow;

};

#endif // WINDOWPOINTKEEPER_H
