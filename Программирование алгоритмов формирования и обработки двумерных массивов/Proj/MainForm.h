#pragma once

#include "MassiveInputForm.h"

namespace Proj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public: MainForm(void);


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm();
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ workToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ RunToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ infoToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ DG_InputData;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumnNames;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumnValues;
	private: System::Windows::Forms::Label^ label1;
	private: MassiveInputForm^ inputMassiveFormX;
	private: MassiveInputForm^ inputMassiveFormY;
	private: MassiveInputForm^ inputMassiveFormZ;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBar1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripMenuItem^ showToolStripMenuItem;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->workToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RunToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DG_InputData = (gcnew System::Windows::Forms::DataGridView());
			this->ColumnNames = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnValues = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DG_InputData))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->workToolStripMenuItem,
					this->infoToolStripMenuItem, this->showToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(434, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// workToolStripMenuItem
			// 
			this->workToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->clearToolStripMenuItem,
					this->RunToolStripMenuItem1
			});
			this->workToolStripMenuItem->Name = L"workToolStripMenuItem";
			this->workToolStripMenuItem->Size = System::Drawing::Size(84, 20);
			this->workToolStripMenuItem->Text = L"Программа";
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->clearToolStripMenuItem->Text = L"Очистить";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ClearToolStripMenuItem_Click);
			// 
			// RunToolStripMenuItem1
			// 
			this->RunToolStripMenuItem1->Name = L"RunToolStripMenuItem1";
			this->RunToolStripMenuItem1->Size = System::Drawing::Size(136, 22);
			this->RunToolStripMenuItem1->Text = L"Выполнить";
			this->RunToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::RunToolStripMenuItem1_Click);
			// 
			// infoToolStripMenuItem
			// 
			this->infoToolStripMenuItem->Name = L"infoToolStripMenuItem";
			this->infoToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->infoToolStripMenuItem->Text = L"Инфо";
			this->infoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::InfoToolStripMenuItem_Click);
			// 
			// showToolStripMenuItem
			// 
			this->showToolStripMenuItem->Enabled = false;
			this->showToolStripMenuItem->Name = L"showToolStripMenuItem";
			this->showToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->showToolStripMenuItem->Text = L"Результаты";
			this->showToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ShowToolStripMenuItem_Click);
			// 
			// DG_InputData
			// 
			this->DG_InputData->AllowUserToAddRows = false;
			this->DG_InputData->AllowUserToDeleteRows = false;
			this->DG_InputData->AllowUserToResizeColumns = false;
			this->DG_InputData->AllowUserToResizeRows = false;
			this->DG_InputData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DG_InputData->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->ColumnNames,
					this->ColumnValues
			});
			this->DG_InputData->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DG_InputData->Location = System::Drawing::Point(0, 44);
			this->DG_InputData->MultiSelect = false;
			this->DG_InputData->Name = L"DG_InputData";
			this->DG_InputData->RowHeadersVisible = false;
			this->DG_InputData->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->DG_InputData->Size = System::Drawing::Size(434, 92);
			this->DG_InputData->TabIndex = 1;
			// 
			// ColumnNames
			// 
			this->ColumnNames->Frozen = true;
			this->ColumnNames->HeaderText = L"Параметр";
			this->ColumnNames->Name = L"ColumnNames";
			this->ColumnNames->Width = 300;
			// 
			// ColumnValues
			// 
			this->ColumnValues->Frozen = true;
			this->ColumnValues->HeaderText = L"Значение";
			this->ColumnValues->Name = L"ColumnValues";
			this->ColumnValues->Width = 75;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Location = System::Drawing::Point(0, 24);
			this->label1->MinimumSize = System::Drawing::Size(0, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(354, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Необходимо задать начальные значения массивов X(m, n) и Y(n, k). ";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripProgressBar1,
					this->toolStripStatusLabel2, this->toolStripStatusLabel1
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 136);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(434, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Maximum = 0;
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(100, 16);
			this->toolStripProgressBar1->Step = 1;
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(46, 17);
			this->toolStripStatusLabel2->Text = L"Статус:";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(98, 17);
			this->toolStripStatusLabel1->Text = L"Ожидание ввода";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(434, 158);
			this->Controls->Add(this->DG_InputData);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(450, 195);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Гоголев Георгий Михайлович БИК2051 - Работа №7";
			this->TopMost = true;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DG_InputData))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void ClearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void RunToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void InfoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: bool CheckInputData();
private: System::Void ShowToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
