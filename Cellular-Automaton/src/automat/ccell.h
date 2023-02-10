#ifndef CCELL_H
#define CCELL_H
/** @file
 * @brief Файл с ячейкой автомата
*/

namespace automat {
/** @brief Класс клетки автомата
 * 
*/
class cCell
{
public:
    cCell();
    cCell(const bool& state);
    cCell(const cCell&);

    cCell operator=(const cCell& aim);
    cCell operator=(const bool& src);

private:
    bool Status;

public:
    bool getStatus() const noexcept;
    void setStatus(const bool& state) noexcept;
    void switchStatus() noexcept;

};

}

#endif // CCELL_H
