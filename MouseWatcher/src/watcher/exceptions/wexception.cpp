#include "wexception.h"

WException::WException(std::string message) :
    std::exception(),
    Message(message)
{
}

const char* WException::what() const noexcept
{
    return Message.c_str();
}

