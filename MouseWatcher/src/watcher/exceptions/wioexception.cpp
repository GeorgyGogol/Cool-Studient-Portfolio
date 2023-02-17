#include "wioexception.h"

WIOException::WIOException(const char* message) :
    WException (message)
{

}

WFileNotFound::WFileNotFound(const char* message) :
    WIOException(message)
{
}
