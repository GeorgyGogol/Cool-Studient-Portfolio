#ifndef CFILESERVER_H
#define CFILESERVER_H


#include "cfield.h"

namespace automat {
    
class cFileServer
{
public:
    cFileServer();

private:

public:
    void SaveTo(cField* field, const char* path);
    cField* LoadFrom(const char* path);

};

}

#endif // CFILESERVER_H
