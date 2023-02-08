#ifndef CFIELD_H
#define CFIELD_H


#include "ccell.h"

namespace automat {
class cField
{
public:
    cField(unsigned int width, unsigned int height);
    ~cField();

private:
    unsigned int Height, Width;
    cCell** Field;
    unsigned int Age;

//protected:
    cCell** createField() const noexcept;
    void deleteField(cCell*** pField) const;
    unsigned int getCountNeighbors(unsigned int X, unsigned int Y) const;
    //bool Rule(unsigned int nNeighbors) const;

public:
    int getHeight() const noexcept;
    int getWidth() const noexcept;

    int getAge() const noexcept;

    cCell* getCell(unsigned int x, unsigned int y) const;
    cCell* getCell(int x, int y) const;
    bool getCellStatus(int x, int y) const;

    void setCell(unsigned int x, unsigned int y, bool status);
    void setCell(int x, int y, bool status);

    void reverseCell(unsigned int x, unsigned int y);

    bool step();
    unsigned int getAliveCount() const noexcept;

    unsigned int getSize() const noexcept;
};

}

#endif // CFIELD_H
