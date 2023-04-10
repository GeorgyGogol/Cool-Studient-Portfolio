#ifndef FIELDSETTINGSFORM_H
#define FIELDSETTINGSFORM_H

#include <QDialog>

namespace Ui {
class FieldSettingsForm;
}

class FieldSettingsForm : public QDialog
{
    Q_OBJECT

public:
    explicit FieldSettingsForm(QWidget *parent = nullptr);
    ~FieldSettingsForm();

private:
    Ui::FieldSettingsForm *ui;

public:
    int getHeight() const noexcept;
    int getWidth() const noexcept;
    QString getName() const noexcept;
    bool getTopBottomClose() const noexcept;
    bool getLeftRightClose() const noexcept;

    int isNeedAutofill() const noexcept;

private slots:
    void UserChangeAutofill();
    void AutoDesideAutofill();

};

#endif // FIELDSETTINGSFORM_H
