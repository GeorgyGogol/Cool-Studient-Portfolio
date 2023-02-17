#ifndef WIOEXCEPTION_H
#define WIOEXCEPTION_H


#include "wexception.h"

#define IOE_REASON_SAVE "Cannot open save file"
#define IOE_REASON_LOAD "Cannot open load file"

class WIOException : public WException
{
public:
    WIOException(const char* message);
};

class WFileNotFound : public WIOException
{
public:
    WFileNotFound(const char* message);
};

#endif // WIOEXCEPTION_H
