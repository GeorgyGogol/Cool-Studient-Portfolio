#ifndef AUTOFILLSETTINGSFORM_H
#define AUTOFILLSETTINGSFORM_H

#include <QDialog>

namespace Ui {
class AutoFillSettingsForm;
}

class AutoFillSettingsForm : public QDialog
{
    Q_OBJECT

public:
    explicit AutoFillSettingsForm(int width, int height, QWidget *parent = nullptr);
    ~AutoFillSettingsForm();

private:
    Ui::AutoFillSettingsForm *ui;

private slots:
    void on_cbEnableAutoFill_stateChanged(int arg1);
    void on_spb_InRadius_valueChanged(int arg1);
    void on_rbFillWithPercent_toggled(bool checked);
    void on_rbFillWithCount_toggled(bool checked);

public:
    int getNedeedAliveCount() const noexcept;
    int getNeededPercentCount() const noexcept;

};

#endif // AUTOFILLSETTINGSFORM_H
