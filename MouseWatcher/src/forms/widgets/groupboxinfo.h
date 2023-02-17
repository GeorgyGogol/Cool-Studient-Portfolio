#ifndef GROUPBOXINFO_H
#define GROUPBOXINFO_H

#include <QGroupBox>

namespace Ui {
class GroupBoxInfo;
}

class GroupBoxInfo : public QGroupBox
{
    Q_OBJECT

public:
    explicit GroupBoxInfo(QWidget *parent = nullptr);
    ~GroupBoxInfo();

public slots:
    void UpdateCurrentPos(int X, int Y);
    void UpdateDelta(int delta);

private:
    Ui::GroupBoxInfo *ui;
};

#endif // GROUPBOXINFO_H
