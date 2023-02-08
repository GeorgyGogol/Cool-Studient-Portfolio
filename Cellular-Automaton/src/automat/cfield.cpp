#include "cfield.h"

namespace automat {

cField::cField(unsigned int width, unsigned int height) :
    Height(height), Width(width), Age(0)
{
    Field = createField();
}

cField::~cField()
{
    deleteField(&Field);
}


cCell** cField::createField() const noexcept
{
    cCell** out = new cCell*[Height];
    for (unsigned int y = 0; y < Height; ++y) {
        out[y] = new cCell[Width];
        for (unsigned int x = 0; x < Width; ++x) {
            out[y][x] = false;
        }
    }
    return out;
}

void cField::deleteField(cCell*** pField) const
{
    cCell** toDel = *pField;
    for (unsigned int x = 0; x < Width; ++x) {
        delete[] toDel[x];
    }
    delete[] toDel;
    *pField = nullptr;
}

unsigned int cField::getCountNeighbors(unsigned int X, unsigned int Y) const
{
    unsigned int out = 0;

    for (int y = int(Y) - 1; y <= int(Y) + 1; ++y) {
        if (y < 0 || y >= int(Height)) continue;
        for (int x = int(X) - 1; x <= int(X) + 1; ++x) {
            if (x < 0 || x >= int(Width)) continue;
            if (x == int(X) && y == int(Y)) continue;
            if (Field[y][x].getStatus()) ++out;
        }
    }

    return out;
}

int cField::getHeight() const noexcept
{
    return int(Height);
}

int cField::getWidth() const noexcept
{
    return int(Width);
}

int cField::getAge() const noexcept
{
    return int(Age);
}

cCell* cField::getCell(unsigned int x, unsigned int y) const
{
    if (y > Height || x > Width) throw "cField::getCell cell not defined!";
    return &Field[y][x];
}

cCell* cField::getCell(int x, int y) const
{
    return getCell(static_cast<unsigned int>(x), static_cast<unsigned int>(y));
}

bool cField::getCellStatus(int x, int y) const
{
    return getCell(x, y)->getStatus();
}

void cField::setCell(unsigned int x, unsigned int y, bool status)
{
    if (y > Height || x > Width) throw "cField::getCell cell not defined!";
    Field[y][x].setStatus(status);
}

void cField::setCell(int x, int y, bool status){
    setCell(static_cast<unsigned int>(x), static_cast<unsigned int>(y), status);
}

void cField::reverseCell(unsigned int x, unsigned int y)
{
    if (y > Height || x > Width) throw "cField::getCell cell not defined!";
    Field[y][x].switchStatus();
}

bool cField::step()
{
    cCell** newField = createField();

    unsigned int nNeighbors;
    for (unsigned int y = 0; y < Height; ++y) {
        for (unsigned int x = 0; x < Width; ++x) {
            nNeighbors = getCountNeighbors(x, y);
            //newField[y][x] = Rule(x, y, nNeighbors);

            switch (nNeighbors) {
            case 2:
                newField[y][x] = Field[y][x];
                break;
            case 3:
                newField[y][x] = true;
                break;
            default:
                newField[y][x] = false;
                break;
            }
        }
    }


    for (unsigned int y = 0; y < Height; ++y) {
        for (unsigned int x = 0; x < Width; ++x) {
            Field[y][x] = newField[y][x];
        }
    }

    deleteField(&newField);

    ++Age;
    return getAliveCount() > 0;
}

unsigned int cField::getAliveCount() const noexcept
{
    unsigned int count = 0;

    for (int y = 0; y < int(Height); ++y) {
        for (int x = 0; x < int(Width); ++x) {
            if (Field[y][x].getStatus()) ++count;
        }
    }

    return count;
}

unsigned int cField::getSize() const noexcept
{
    unsigned int out = sizeof(*this);

    out += static_cast<unsigned int>(sizeof(cCell)) * Height * Width;

    return out;
}

}

