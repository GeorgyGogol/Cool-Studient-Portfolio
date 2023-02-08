#ifndef CCELL_H
#define CCELL_H


namespace automat {
class cCell
{
public:
    cCell();
    cCell(const bool& state);
    cCell(const cCell&);

    cCell operator=(const cCell& aim);

private:
    bool Status;

public:
    bool getStatus() const noexcept;
    void setStatus(const bool& state) noexcept;
    void switchStatus() noexcept;

};

}

#endif // CCELL_H
