#include "cfield.h"

#include <random>
#include <time.h>

namespace automat {

cField::cField(unsigned int width, unsigned int height) :
    Age(0), LastAliveCount(0)
{
    fSettings.Height = height;
    fSettings.Width = width;
    fSettings.CloseLeftRight = false;
    fSettings.CloseTopBottom = false;
    fSettings.FieldName = "Unnamed map";
    
    Field = createField();
}

cField::cField(unsigned int width, unsigned int height, char* fieldName) :
    Age(0), LastAliveCount(0)
{
    fSettings.Height = height;
    fSettings.Width = width;
    fSettings.CloseLeftRight = false;
    fSettings.CloseTopBottom = false;
    fSettings.FieldName = fieldName;
    if (fSettings.FieldName.length() < 1) fSettings.FieldName = "Unnamed map";
    
    Field = createField();
}

cField::cField(const FieldSettings& settings) :
    Age(0), LastAliveCount(0)
{
    fSettings = settings;

    Field = createField();
}

cField::~cField()
{
    deleteField(&Field);
}


cCell** cField::createField() const noexcept
{
    cCell** out = new cCell*[fSettings.Height];
    for (unsigned int y = 0; y < fSettings.Height; ++y) {
        out[y] = new cCell[fSettings.Width];
        for (unsigned int x = 0; x < fSettings.Width; ++x) {
            out[y][x] = false;
        }
    }
    return out;
}

void cField::deleteField(cCell*** pField) const
{
    cCell** toDel = *pField;
    for (unsigned int x = 0; x < fSettings.Width; ++x) {
        delete[] toDel[x];
    }
    delete[] toDel;
    *pField = nullptr;
}

unsigned int cField::getCountNeighbors(unsigned int X, unsigned int Y) const
{
    unsigned int out = 0;

    int posY, posX;
    for (int y = int(Y) - 1; y <= int(Y) + 1; ++y){
        posY = y;
        if (!valideY(posY)) continue;

        for (int x = int(X) - 1; x <= int(X) + 1; ++x){
            posX = x;
            if (!valideX(posX)) continue;
            if (posX == int(X) && posY == int(Y)) continue;
            if (Field[posY][posX].getStatus()) ++out;
        }

    }

    return out;
}

bool cField::valideY(int& outY) const
{
    bool out = true;

    if (fSettings.CloseTopBottom) {
        while (outY < 0) {
            outY += int(fSettings.Height);
        }
        while (outY > int(fSettings.Height) - 1) {
            outY -= int(fSettings.Height);
        }
    }
    else {
        out = outY > -1 && outY < int(fSettings.Height);
    }

    return out;
}

bool cField::valideX(int& outX) const
{
    bool out = true;

    if (fSettings.CloseLeftRight) {
        while (outX < 0) {
            outX += int(fSettings.Width);
        }
        while (outX > int(fSettings.Width) - 1) {
            outX -= int(fSettings.Width);
        }
    }
    else {
        out = outX > -1 && outX < int(fSettings.Width);
    }

    return out;
}

int cField::getHeight() const noexcept
{
    return static_cast<int>(fSettings.Height);
}

int cField::getWidth() const noexcept
{
    return static_cast<int>(fSettings.Width);
}

unsigned int cField::getAge() const noexcept
{
    return Age;
}

void cField::SetCloseTopBottom(bool state) noexcept
{
    fSettings.CloseTopBottom = state;
}

bool cField::GetCloseTopBottom() const noexcept
{
    return fSettings.CloseTopBottom;
}

void cField::SetCloseLeftRight(bool state) noexcept
{
    fSettings.CloseLeftRight = state;
}

const char* cField::getFieldName() const noexcept
{
    return fSettings.FieldName.c_str();
}

bool cField::GetCloseLeftRight() const noexcept
{
    return fSettings.CloseLeftRight;
}

cCell* cField::getCell(unsigned int x, unsigned int y) const
{
    if (y > fSettings.Height || x > fSettings.Width) 
        throw "cField::getCell cell not defined!";
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
    if (y > fSettings.Height || x > fSettings.Width) 
        throw "cField::getCell cell not defined!";
    Field[y][x].setStatus(status);
}

void cField::setCell(int x, int y, bool status){
    setCell(static_cast<unsigned int>(x), static_cast<unsigned int>(y), status);
}

void cField::reverseCell(unsigned int x, unsigned int y)
{
    if (y > fSettings.Height || x > fSettings.Width) 
        throw "cField::getCell cell not defined!";
    Field[y][x].switchStatus();
}

bool cField::step()
{
    cCell** newField = createField();

    unsigned int nNeighbors;
    for (unsigned int y = 0; y < fSettings.Height; ++y) {
        for (unsigned int x = 0; x < fSettings.Width; ++x) {
            nNeighbors = getCountNeighbors(x, y);

            // Rule
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

    LastAliveCount = 0;
    for (unsigned int y = 0; y < fSettings.Height; ++y) {
        for (unsigned int x = 0; x < fSettings.Width; ++x) {
            Field[y][x] = newField[y][x];
            if (Field[y][x].getStatus()) ++LastAliveCount;
        }
    }

    deleteField(&newField);

    ++Age;
    return LastAliveCount > 0;
}

unsigned int cField::getAliveCount() const noexcept
{
    unsigned int cnt = 0;

    for (unsigned int y = 0; y < fSettings.Height; ++y) {
        for (unsigned int x = 0; x < fSettings.Width; ++x) {
            if (Field[y][x].getStatus()) ++cnt;
        }
    }

    return cnt;
}

unsigned int cField::getSize() const noexcept
{
    unsigned int out = sizeof(*this);

    out += static_cast<unsigned int>(sizeof(cCell)) * fSettings.Height * fSettings.Width;

    return out;
}

void cField::Clear()
{
    for (unsigned int y = 0; y < fSettings.Height; ++y) {
        for (unsigned int x = 0; x < fSettings.Width; ++x) {
            Field[y][x] = false;
        }
    }
}

void cField::FillRandome()
{
    srand(uint32_t(time(nullptr)));
    for (unsigned int y = 0; y < fSettings.Height; ++y) {
        for (unsigned int x = 0; x < fSettings.Width; ++x) {
            setCell(x, y, rand() % 2);
        }
    }
}

}

