#ifndef WIOMANAGER_H
#define WIOMANAGER_H


#include "wwatcher.h"
#include "wpoint.h"

class WIOManager
{
public:
    WIOManager();

private:
    const char* PackData(const WPoint* p) const;

public:
    void Save(WWatcher* watcher, const char* path) const;
    WWatcher* Load(const char* path) const;

};

#endif // WIOMANAGER_H
