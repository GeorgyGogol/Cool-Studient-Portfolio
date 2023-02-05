#ifndef CFIELD_H
#define CFIELD_H


namespace automat {
class cField
{
public:
    cField(unsigned int height, unsigned int width);
    ~cField();

private:
    unsigned int Height, Width;
    bool** Field;

//protected:
    bool** createField() const noexcept;
    void deleteField(bool*** pField) const;
    unsigned int getCountNeighbors(unsigned int X, unsigned int Y) const;
    //bool Rule(unsigned int nNeighbors) const;

public:
    int getHeight() const noexcept;
    int getWidth() const noexcept;

    bool getCell(unsigned int x, unsigned int y) const;
    bool getCell(int x, int y) const;
    void setCell(unsigned int x, unsigned int y, bool cell);
    void setCell(int x, int y, bool cell);
    void reverseCell(unsigned int x, unsigned int y);

    bool step();
    unsigned int getAliveCount() const noexcept;
};

}

#endif // CFIELD_H
