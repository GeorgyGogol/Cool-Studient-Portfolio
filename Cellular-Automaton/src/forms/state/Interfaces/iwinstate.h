#ifndef IWINSTATE_H
#define IWINSTATE_H


namespace states {

class IWinState
{
public:
    virtual ~IWinState() = 0;

public:
    virtual void Enter() = 0;
    virtual void Exit() = 0;

    virtual bool isRunning() const = 0;
    
};

}

#endif // IWINSTATE_H

