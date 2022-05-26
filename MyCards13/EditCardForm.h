#pragma once
#include "funcsHeader.h"
namespace MyCards13 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для EditCardForm
	/// </summary>
	static int index, faculty_id;
	static std::vector<Card> base;
	static std::string path_;
	public ref class EditCardForm : public System::Windows::Forms::Form
	{
	public:
		EditCardForm(int ind, int fac);
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EditCardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ NameBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ LastnameBox;
	private: System::Windows::Forms::ComboBox^ PaymentBox;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ GroupBox;
	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::Button^ SaveButton;
	private: System::Windows::Forms::Button^ CancelButton;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ editInfoBox;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->NameBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->LastnameBox = (gcnew System::Windows::Forms::TextBox());
			this->PaymentBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->GroupBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->editInfoBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(15, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Имя";
			// 
			// NameBox
			// 
			this->NameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->NameBox->Location = System::Drawing::Point(169, 13);
			this->NameBox->Name = L"NameBox";
			this->NameBox->Size = System::Drawing::Size(203, 24);
			this->NameBox->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(12, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Фамилия";
			// 
			// LastnameBox
			// 
			this->LastnameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->LastnameBox->Location = System::Drawing::Point(169, 41);
			this->LastnameBox->Name = L"LastnameBox";
			this->LastnameBox->Size = System::Drawing::Size(203, 24);
			this->LastnameBox->TabIndex = 3;
			// 
			// PaymentBox
			// 
			this->PaymentBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->PaymentBox->FormattingEnabled = true;
			this->PaymentBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Контракт", L"Бюджет", L"Направление" });
			this->PaymentBox->Location = System::Drawing::Point(169, 99);
			this->PaymentBox->Name = L"PaymentBox";
			this->PaymentBox->Size = System::Drawing::Size(203, 26);
			this->PaymentBox->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(12, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Форма оплаты";
			// 
			// GroupBox
			// 
			this->GroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->GroupBox->Location = System::Drawing::Point(169, 69);
			this->GroupBox->Name = L"GroupBox";
			this->GroupBox->Size = System::Drawing::Size(203, 24);
			this->GroupBox->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(15, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Группа";
			this->label4->Click += gcnew System::EventHandler(this, &EditCardForm::label4_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->SaveButton->Location = System::Drawing::Point(19, 225);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(354, 55);
			this->SaveButton->TabIndex = 10;
			this->SaveButton->Text = L"Сохранить изменения";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &EditCardForm::SaveButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->CancelButton->Location = System::Drawing::Point(18, 286);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(354, 27);
			this->CancelButton->TabIndex = 11;
			this->CancelButton->Text = L"Отмена";
			this->CancelButton->UseVisualStyleBackColor = false;
			this->CancelButton->Click += gcnew System::EventHandler(this, &EditCardForm::CancelButton_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(15, 133);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(132, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Доп. сведения";
			// 
			// editInfoBox
			// 
			this->editInfoBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->editInfoBox->Location = System::Drawing::Point(169, 131);
			this->editInfoBox->Multiline = true;
			this->editInfoBox->Name = L"editInfoBox";
			this->editInfoBox->Size = System::Drawing::Size(203, 88);
			this->editInfoBox->TabIndex = 13;
			// 
			// EditCardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(385, 325);
			this->Controls->Add(this->editInfoBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->GroupBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->PaymentBox);
			this->Controls->Add(this->LastnameBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->NameBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EditCardForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Редактировать информацию";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e) {this->Close();}
private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
