#include "MainForm.h"
#include "Core.h"

#define MIN_VAL 0
#define MAX_VAL 5

using namespace Proj;

char* StrToChar(System::String^ bid)
{
	return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(bid);
}
int StrToInt(System::String^ num)
{
	if (num->Length < 1) return 0;
	return System::Convert::ToInt32(num);
}
System::String^ NumToString(int num)
{
	return System::Convert::ToString(num);
}

MainForm::MainForm(void)
{
	InitializeComponent();
	
	inputMassiveFormX = gcnew MassiveInputForm;
	inputMassiveFormX->SetFormHeader("������ X");

	inputMassiveFormY = gcnew MassiveInputForm;
	inputMassiveFormY->SetFormHeader("������ Y");

	inputMassiveFormZ = gcnew MassiveInputForm;
	inputMassiveFormZ->SetFormHeader("������ Z");
	inputMassiveFormZ->SetFormToOutptut();

	DG_InputData->RowCount = 3;
	DG_InputData[0, 0]->Value = "m";
	DG_InputData[0, 1]->Value = "n";
	DG_InputData[0, 2]->Value = "k";

	InfoToolStripMenuItem_Click(this, nullptr);
}

MainForm::~MainForm()
{
	if (components)
	{
		delete components;
	}
	delete inputMassiveFormX;
	delete inputMassiveFormY;
	delete inputMassiveFormZ;
}


System::Void MainForm::ClearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < 3; i++) DG_InputData[1, i]->Value = "";
	showToolStripMenuItem->Enabled = false;
	return System::Void();
}

System::Void MainForm::RunToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	toolStripStatusLabel1->Text = "���������";
	if (!CheckInputData()) {
		MessageBox::Show("��������� �������� �����������! ���������� �������������� � ������������ �������� ��������: ����� ������ ���� ������ ������ 0", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		toolStripStatusLabel1->Text = "��������� �������� �����������!";
		return System::Void();
	}

	int buf;
	int m, n, k, n0; // X(m,n), Y(n,k), Z(n2, n)
	
	m = StrToInt(DG_InputData[1, 0]->Value->ToString());
	n = StrToInt(DG_InputData[1, 1]->Value->ToString());
	k = StrToInt(DG_InputData[1, 2]->Value->ToString());

	if (k < n) {
		MessageBox::Show("���������� ��������� ��������� � ��������� ����������: ���������� ������� � ������� Y ������ ���� ������ ��� ����� ���������� �������� ������� X.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		toolStripStatusLabel1->Text = "���������� ��������� �������� ��������!";
		return System::Void();
	}

	Core::cMatrix X(m, n);
	inputMassiveFormX->SetSize(m, n);
	
	Core::cMatrix Y(n, k);
	inputMassiveFormY->SetSize(n, k);

	m > n ? n0 = n : n0 = m;
	Core::cMatrix Z(n0, n);
	inputMassiveFormZ->SetSize(n0, n);

	// input
	switch(MessageBox::Show("���� ����������� ������������� ������� �������������. ������� �� ������������� ������� ������������� (��) ��� ������ �� � ������ (���)?\n"
		L"������������� ��������� ������ ����� ����� ���������������.",
		"������� �����", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
	{
	case ::DialogResult::No:

		inputMassiveFormX->SetFormToInput();
		inputMassiveFormX->ShowDialog(this);
		if (inputMassiveFormX->DialogResult == ::DialogResult::Cancel) return System::Void();

		inputMassiveFormY->SetFormToInput();
		inputMassiveFormY->ShowDialog(this);
		if (inputMassiveFormY->DialogResult == ::DialogResult::Cancel) return System::Void();
		
		// ���������� ��������
		for (int x = 0; x < m; x++) {
			for (int y = 0; y < n; y++)
			{
				X.set(x, y, inputMassiveFormX->GetValue(x, y));
			}
		}
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < k; y++)
			{
				Y.set(x, y, inputMassiveFormY->GetValue(x, y));
			}
		}

		break;
	case ::DialogResult::Yes:
		// �������� �������		
		inputMassiveFormX->SetFormToOutptut();
		toolStripStatusLabel1->Text = "�������� ������� �";
		statusStrip1->Update();
		toolStripProgressBar1->Value = 0;
		toolStripProgressBar1->Maximum = m * n;
		for (int x = 0; x < m; x++) {
			for (int y = 0; y < n; y++)
			{
				buf = Core::GetRandom(MIN_VAL, MAX_VAL);
				X.set(x, y, buf);
				inputMassiveFormX->SetValue(x, y, buf);
				toolStripProgressBar1->PerformStep();
			}
		}
		inputMassiveFormX->ShowDialog(this);

		inputMassiveFormY->SetFormToOutptut();
		toolStripStatusLabel1->Text = "�������� ������� Y";
		statusStrip1->Update();
		toolStripProgressBar1->Value = 0;
		toolStripProgressBar1->Maximum = n * k;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < k; y++)
			{
				buf = Core::GetRandom(MIN_VAL, MAX_VAL);
				Y.set(x, y, buf);
				inputMassiveFormY->SetValue(x, y, buf);
				toolStripProgressBar1->PerformStep();
			}
		}
		inputMassiveFormY->ShowDialog(this);
		
		break;
	}

	// work
	toolStripStatusLabel1->Text = "������� ������� Z";
	statusStrip1->Update();
	toolStripProgressBar1->Value = 0;
	toolStripProgressBar1->Maximum = n0 * n;
	int prod;
	for (int i = 0; i < n0; i++)
	{
		prod = Y.get_productRow(i);
		for (int j = 0; j < n; j++)
		{
			buf = X.get(i, j) + prod;
			Z.set(i, j, buf);
			inputMassiveFormZ->SetValue(i, j, buf);
			toolStripProgressBar1->PerformStep();
		}
	}

	// output
	toolStripStatusLabel1->Text = "������";
	inputMassiveFormZ->ShowDialog(this);
	showToolStripMenuItem->Enabled = true;

	return System::Void();
}

System::Void MainForm::InfoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show(
		L"������������ ������ � " LAB_NUM L"\n" LAB_TEXT L"\n"
		L"������� " VAR L"\n\n"
		L"�������: " VAR_TEXT L"\n\n"
		L"������ ��������: " FIO "\n"
		L"������: " GROUP,
		"���������� � ������",
		MessageBoxButtons::OK, MessageBoxIcon::Information);
	return System::Void();
}

bool Proj::MainForm::CheckInputData()
{
	// TODO: �������� �� ������������� ������
	for (int i = 0; i < 3; i++)
	{
		if (StrToInt(DG_InputData[1, i]->Value->ToString()) < 1) return false;
	}
	return true;
}

System::Void Proj::MainForm::ShowToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	inputMassiveFormX->SetFormToOutptut();
	inputMassiveFormY->SetFormToOutptut();
	if (inputMassiveFormX->Visible == false) inputMassiveFormX->Show(this);
	if (inputMassiveFormY->Visible == false) inputMassiveFormY->Show(this);
	if (inputMassiveFormZ->Visible == false) inputMassiveFormZ->Show(this);
	return System::Void();
}

