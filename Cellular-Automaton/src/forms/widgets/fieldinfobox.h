#ifndef FIELDINFOBOX_H
#define FIELDINFOBOX_H

#include <QGroupBox>
#include "core.h"

namespace Ui {
class FieldInfoBox;
}

class FieldInfoBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit FieldInfoBox(QWidget *parent = nullptr);
    ~FieldInfoBox();

private:
    Ui::FieldInfoBox *ui;

public:
    void UpdateInfo(const automat::cField* field);
    void ResetInfo();

};

#endif // FIELDINFOBOX_H
