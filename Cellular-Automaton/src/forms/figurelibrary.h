#ifndef FIGURELIBRARY_H
#define FIGURELIBRARY_H

#include <QFrame>

namespace Ui {
class figureLibrary;
}

class figureLibrary : public QFrame
{
    Q_OBJECT

public:
    explicit figureLibrary(QWidget *parent = nullptr);
    ~figureLibrary();

private:
    Ui::figureLibrary *ui;
};

#endif // FIGURELIBRARY_H
