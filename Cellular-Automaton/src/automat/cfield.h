#ifndef CFIELD_H
#define CFIELD_H


#include "ccell.h"
#include "cfieldsettings.h"

namespace automat {
/** -------------------------------------------------------------------
 * @brief Класс поля
 * 
 * @details Основной класс автомата. Представляет поле, на котором
 * все происходит. Помимо поля, содержит настройки и правила вычисления
 * нового состояния (следующей итерации)
 * 
 * ----------------------------------------------------------------- */
class cField
{
public:
    cField(unsigned int width, unsigned int height);
    cField(unsigned int width, unsigned int height, char* fieldName);
    cField(const FieldSettings& settings);
    ~cField();

private:
    FieldSettings fSettings; ///< Настройки поля
    cCell** Field; ///< Матрица поля
    unsigned int Age; ///< Возраст
    unsigned int LastAliveCount;

    cCell** createField() const noexcept; ///< Создать пустое поле
    void deleteField(cCell*** pField) const; ///< Удалить поле
    /// @brief Количество соседей у заданной точки
    unsigned int getCountNeighbors(unsigned int X, unsigned int Y) const;

    //bool validePos(int& pos, const bool& close, const unsigned int& max) const;

    bool valideY(int& outY) const;
    bool valideX(int& outX) const;

public:
    int getHeight() const noexcept; ///< Получить Высоту
    int getWidth() const noexcept; ///< Получить ширину

    int getAge() const noexcept; ///< Получить возраст

    void SetCloseTopBottom(bool state) noexcept; ///< Установить замкнутость верх-низ
    bool GetCloseTopBottom() const noexcept;

    void SetCloseLeftRight(bool state) noexcept; ///< Установить замкнутость парво-лево
    bool GetCloseLeftRight() const noexcept;

    const char* getFieldName() const noexcept;

    /// @brief Получить клетку в координате
    /// @{
    cCell* getCell(unsigned int x, unsigned int y) const;
    cCell* getCell(int x, int y) const;
    /// @}

    /// @brief Получить состояние клетки
    bool getCellStatus(int x, int y) const;

    /// @brief Установить состояние клетки
    /// @{
    void setCell(unsigned int x, unsigned int y, bool status);
    void setCell(int x, int y, bool status);
    /// @}

    void reverseCell(unsigned int x, unsigned int y); ///< Переключить состояние

    bool step(); ///< Сделать шаг
    unsigned int getAliveCount() const noexcept; ///< Количество живых клеток

    unsigned int getSize() const noexcept; ///< Размер объекта


};

}

#endif // CFIELD_H
