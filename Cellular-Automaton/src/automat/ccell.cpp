#include "ccell.h"

namespace automat {

cCell::cCell() :
    Status(false)
{

}

cCell::cCell(const bool& state) :
    Status(state)
{

}

cCell::cCell(const cCell& aim)
{
    Status = aim.Status;
}

cCell cCell::operator=(const cCell& aim)
{
    Status = aim.Status;

    return *this;
}

cCell cCell::operator=(const bool& src)
{
    Status = src;

    return *this;
}


bool cCell::getStatus() const noexcept
{
    return Status;
}

void cCell::setStatus(const bool& state) noexcept
{
    Status = state;
}

void cCell::switchStatus() noexcept
{
    Status = !Status;
}

}

