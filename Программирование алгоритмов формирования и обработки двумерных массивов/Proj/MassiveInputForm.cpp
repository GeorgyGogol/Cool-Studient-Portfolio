#include "MassiveInputForm.h"

#define CELL_WIDTH 36

using namespace Proj;

MassiveInputForm::MassiveInputForm()
{
	InitializeComponent();

	buttonConfirm->DialogResult = ::DialogResult::OK;
	buttonCancel->DialogResult = ::DialogResult::Cancel;

	AcceptButton = buttonConfirm;
	CancelButton = buttonCancel;
}

MassiveInputForm::~MassiveInputForm()
{
	if (components)
	{
		delete components;
	}
}


System::Void Proj::MassiveInputForm::SetFormToInput()
{
	buttonClear->Enabled = true;
	buttonCancel->Enabled = true;
	return System::Void();
}

System::Void Proj::MassiveInputForm::SetFormToOutptut()
{
	buttonClear->Enabled = false;
	buttonCancel->Enabled = false;
	return System::Void();
}

System::Void Proj::MassiveInputForm::SetFormHeader(char* header)
{
	//System::String^ Header = ;
	this->Text = gcnew System::String(header);
	return System::Void();
}

System::Void Proj::MassiveInputForm::SetSize(int width, int height)
{
	dataGrid_MasEdit->ColumnCount = width;
	for (int i = 0; i < width; i++) {
		dataGrid_MasEdit->Columns[i]->Width = CELL_WIDTH;
	}

	dataGrid_MasEdit->RowCount = height;

	this->Width = width * CELL_WIDTH + 20;
	this->Height = height * dataGrid_MasEdit->Rows[0]->Height + 65;

	return System::Void();
}

System::Void Proj::MassiveInputForm::SetSize(int size)
{
	dataGrid_MasEdit->ColumnCount = size;
	for (int i = 0; i < size; i++) {
		dataGrid_MasEdit->Columns[i]->Width = CELL_WIDTH;
	}

	dataGrid_MasEdit->RowCount = size;

	this->Width = size * CELL_WIDTH + 20;
	this->Height = size * dataGrid_MasEdit->Rows[0]->Height + 65;

	return System::Void();
}

System::Void Proj::MassiveInputForm::ClearData(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < dataGrid_MasEdit->ColumnCount; i++) {
		for (int j = 0; j < dataGrid_MasEdit->RowCount; j++)
		{
			dataGrid_MasEdit[i, j]->Value = "";
		}
	}
	return System::Void();
}

int Proj::MassiveInputForm::GetValue(int x, int y)
{
	if (x < 0 || x >= dataGrid_MasEdit->ColumnCount) throw "error X";
	if (y < 0 || y >= dataGrid_MasEdit->RowCount) throw "error Y";
	if (dataGrid_MasEdit[x, y]->Value->ToString() == nullptr) return 0;
	return System::Convert::ToInt32(dataGrid_MasEdit[x, y]->Value->ToString());
}

System::Void Proj::MassiveInputForm::SetValue(int x, int y, int val)
{
	if (x < 0 || x >= dataGrid_MasEdit->ColumnCount) throw "error X";
	if (y < 0 || y >= dataGrid_MasEdit->RowCount) throw "error Y";
	dataGrid_MasEdit[x, y]->Value = val;
	return System::Void();
}

System::Void Proj::MassiveInputForm::ButtonConfirm_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	return System::Void();
}

