История изменений
=================

# Alfa 3

10.04.2023

Ага-ага, даты тоже важны XD

- [x] **Защитить клетки от нажатия мыши во время симуляции**
- [x] **Возможность масштабирования**
- [x] Внедрить статус-бар
  - [x] Корректная настройка
- [x] Мини-карта
- [x] Возможность регулировать скорость
- [x] Случайное заполнение всей карты
- [x] Загрузка разных версий файлов

Дополнительно:

- **Перенес настройку интерфейса на машину состояний**
- Небольшое усовершенствование репозитория
- Изменил графический интерфейс основной формы
- Добавил информацию о версии
- Пункт правила и описание классических правил
- Очистка карты
- Скрыть/показать миникарту
- Состояние "игра окончена", когда живых клеток не остается
- Исправлено кодирование кириллицы
- Добавлен вывод информации о поле
- Поправлена отрисовка ячеек

К концу этого этапа было решено разбить приложение на три 
самостоятельные части:

1. Библиотка с самим клеточным автоматом
2. Исполняемый файл приложения
3. Библиотека с кастомными виджетами (не уверен)

Мотивацией послужила нарастающая громоздкость проекта, относительно 
долгая разработка над графической частью, желание иметь возможность
развивать автомат независимо от графического интерфейса (усложнить,
так сказать).

В связи с чем проект проект отправляется в отдельный репозиторий.

# Alfa 2

Вполне рабочая вещь. Минимальный функционал для клеточного автомата
реализован.

- [x] **Настройка замкнутости поля**
- [x] **Правила для замкнутого поля**
- [x] **Настройка размеров**
  - [x] Форма настроек
  - [x] Ограничение на максимальное поле: 512
- [x] **Создание нового поля не в момент загрузки**
  - [x] Форма нового поля
- [x] Сохранение (с GUI)
- [x] Загрузка (с GUI)
- [x] Возможность дать название полю
- [x] Убрать сохранение при закрытии
- [x] Статус-бар отдельным объектом

# Alfa 1

Фиксация достижений на 08.02.2023

- [x] **Классический алгоритм рассчета поля**
- [x] **Графический вывод поля**
  - [x] Разобраться с Qt-средствами рисования
  - [x] Объект для отрисовки
  - [x] Считывание состояния объекта (связь с тем, что находится в автомате)
  - [x] Возможность графического редактирования
  - [x] Запуск симуляции
- [x] Ввод/вывод поля
- [x] Ручное изменение поля
