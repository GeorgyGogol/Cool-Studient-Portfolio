#include "cfield.h"

namespace automat {

cField::cField(unsigned int height, unsigned int width) :
    Height(height), Width(width)
{
    Field = createField();
}

cField::~cField()
{
    deleteField(&Field);
}


bool** cField::createField() const noexcept
{
    bool** out = new bool*[Height];
    for (unsigned int y = 0; y < Height; ++y) {
        out[y] = new bool[Width];
        for (unsigned int x = 0; x < Width; ++x) {
            out[y][x] = false;
        }
    }
    return out;
}

void cField::deleteField(bool*** pField) const
{
    bool** toDel = *pField;
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
            if (Field[y][x]) ++out;
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

bool cField::getCell(unsigned int x, unsigned int y) const
{
    if (y > Height || x > Width) throw "cField::getCell cell not defined!";
    return Field[y][x];
}

bool cField::getCell(int x, int y) const
{
    return getCell(static_cast<unsigned int>(x), static_cast<unsigned int>(y));
}

void cField::setCell(unsigned int x, unsigned int y, bool cell)
{
    if (y > Height || x > Width) throw "cField::getCell cell not defined!";
    Field[y][x] = cell;
}

void cField::setCell(int x, int y, bool cell){
    setCell(static_cast<unsigned int>(x), static_cast<unsigned int>(y), cell);
}

void cField::reverseCell(unsigned int x, unsigned int y)
{
    if (y > Height || x > Width) throw "cField::getCell cell not defined!";
    Field[y][x] = !Field[y][x];
}

bool cField::step()
{
    bool** newField = createField();

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

    deleteField(&Field);
    Field = newField;
    newField = nullptr;

    return getAliveCount() > 0;
}

unsigned int cField::getAliveCount() const noexcept
{
    unsigned int count = 0;

    for (int y = 0; y < int(Height); ++y) {
        for (int x = 0; x < int(Width); ++x) {
            if (Field[y][x]) ++count;
        }
    }

    return count;
}

}

