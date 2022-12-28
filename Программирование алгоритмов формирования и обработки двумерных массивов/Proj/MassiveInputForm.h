#pragma once

namespace Proj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MassiveInputForm
	/// </summary>
	public ref class MassiveInputForm : public System::Windows::Forms::Form
	{
	public:
		MassiveInputForm();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MassiveInputForm();


	private: System::Windows::Forms::DataGridView^ dataGrid_MasEdit;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Button^ buttonConfirm;
	private: System::Windows::Forms::Button^ buttonClear;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MassiveInputForm::typeid));
			this->dataGrid_MasEdit = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonConfirm = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_MasEdit))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGrid_MasEdit
			// 
			this->dataGrid_MasEdit->AllowUserToAddRows = false;
			this->dataGrid_MasEdit->AllowUserToDeleteRows = false;
			this->dataGrid_MasEdit->AllowUserToResizeColumns = false;
			this->dataGrid_MasEdit->AllowUserToResizeRows = false;
			this->dataGrid_MasEdit->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid_MasEdit->ColumnHeadersVisible = false;
			this->dataGrid_MasEdit->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGrid_MasEdit->Location = System::Drawing::Point(0, 0);
			this->dataGrid_MasEdit->Name = L"dataGrid_MasEdit";
			this->dataGrid_MasEdit->RowHeadersVisible = false;
			this->dataGrid_MasEdit->Size = System::Drawing::Size(244, 158);
			this->dataGrid_MasEdit->TabIndex = 3;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->buttonCancel);
			this->panel1->Controls->Add(this->buttonClear);
			this->panel1->Controls->Add(this->buttonConfirm);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 158);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(244, 23);
			this->panel1->TabIndex = 1;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Dock = System::Windows::Forms::DockStyle::Left;
			this->buttonCancel->Location = System::Drawing::Point(150, 0);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 2;
			this->buttonCancel->Text = L"Отмена";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// buttonClear
			// 
			this->buttonClear->Dock = System::Windows::Forms::DockStyle::Left;
			this->buttonClear->Location = System::Drawing::Point(75, 0);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(75, 23);
			this->buttonClear->TabIndex = 1;
			this->buttonClear->Text = L"Очистить";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MassiveInputForm::ClearData);
			// 
			// buttonConfirm
			// 
			this->buttonConfirm->Dock = System::Windows::Forms::DockStyle::Left;
			this->buttonConfirm->Location = System::Drawing::Point(0, 0);
			this->buttonConfirm->Name = L"buttonConfirm";
			this->buttonConfirm->Size = System::Drawing::Size(75, 23);
			this->buttonConfirm->TabIndex = 0;
			this->buttonConfirm->Text = L"Принять";
			this->buttonConfirm->UseVisualStyleBackColor = true;
			this->buttonConfirm->Click += gcnew System::EventHandler(this, &MassiveInputForm::ButtonConfirm_Click);
			// 
			// MassiveInputForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(244, 181);
			this->ControlBox = false;
			this->Controls->Add(this->dataGrid_MasEdit);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(900, 900);
			this->MinimumSize = System::Drawing::Size(260, 220);
			this->Name = L"MassiveInputForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Редактор Массивов";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_MasEdit))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

public: System::Void SetFormToInput();
public: System::Void SetFormToOutptut();
public: System::Void SetFormHeader(char* header);
public: System::Void SetSize(int width, int height);
public: System::Void SetSize(int size);
public: System::Void ClearData(System::Object^ sender, System::EventArgs^ e);
public: int GetValue(int x, int y);
public: System::Void SetValue(int x, int y, int val);
private: System::Void ButtonConfirm_Click(System::Object^ sender, System::EventArgs^ e);
};
}
