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
		EditCardForm(int ind, int fac)
		{
			index = ind;
			faculty_id = fac;
			InitializeComponent();
			//
			switch (faculty_id)
			{
			case 0:
				path_ = "math_fac.cdb";
				break;
			case 1:
				path_ = "tech_fac.cdb";
				break;
			case 2:
				path_ = "railway_fac.cdb";
				break;
			case 3:
				path_ = "roadt_fac.cdb";
				break;
			case 4:
				path_ = "ist_fac.cdb";
				break;
			case 5:
				path_ = "inat_fac.cdb";
				break;
			default:
				DoAlert("Вы не выбрали факультет!");
				break;
			}
			base = load_base(path_);
			NameBox->Text = stoS(base.at(index).GetName());
			LastnameBox->Text = stoS(base.at(index).GetLastname());
			GroupBox->Text = stoS(base.at(index).Group);
			if (base[index].PayForm == PAYMENT::PF_CONTRACT) PaymentBox->SelectedIndex = 0;
			if (base[index].PayForm == PAYMENT::PF_BUDGET) PaymentBox->SelectedIndex = 1;
			if (base[index].PayForm == PAYMENT::PF_TARGET) PaymentBox->SelectedIndex = 2;
		}
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
			this->NameBox->Location = System::Drawing::Point(223, 13);
			this->NameBox->Name = L"NameBox";
			this->NameBox->Size = System::Drawing::Size(149, 24);
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
			this->LastnameBox->Location = System::Drawing::Point(223, 41);
			this->LastnameBox->Name = L"LastnameBox";
			this->LastnameBox->Size = System::Drawing::Size(149, 24);
			this->LastnameBox->TabIndex = 3;
			// 
			// PaymentBox
			// 
			this->PaymentBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->PaymentBox->FormattingEnabled = true;
			this->PaymentBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Контракт", L"Бюджет", L"Направление" });
			this->PaymentBox->Location = System::Drawing::Point(223, 99);
			this->PaymentBox->Name = L"PaymentBox";
			this->PaymentBox->Size = System::Drawing::Size(149, 26);
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
			this->GroupBox->Location = System::Drawing::Point(223, 69);
			this->GroupBox->Name = L"GroupBox";
			this->GroupBox->Size = System::Drawing::Size(149, 24);
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
			this->SaveButton->Location = System::Drawing::Point(19, 139);
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
			this->CancelButton->Location = System::Drawing::Point(18, 200);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(354, 27);
			this->CancelButton->TabIndex = 11;
			this->CancelButton->Text = L"Отмена";
			this->CancelButton->UseVisualStyleBackColor = false;
			this->CancelButton->Click += gcnew System::EventHandler(this, &EditCardForm::CancelButton_Click);
			// 
			// EditCardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(385, 234);
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
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	//
	if (std::regex_match(Stos(NameBox->Text), NAME_REGEX))
		base.at(index).ChangeName(NameBox->Text);
	else DoAlert("Имя введено неккоректно!");
	if (std::regex_match(Stos(LastnameBox->Text), NAME_REGEX))
		base.at(index).ChangeLastname(LastnameBox->Text);
	else DoAlert("Фамилия введена некооректно!");
	if (std::regex_match(Stos(GroupBox->Text), GROUP_REGEX))
		base.at(index).Group = Stos(GroupBox->Text);
	else DoAlert("Формат группы ведён неверно!");

	if (PaymentBox->SelectedIndex == 0) base.at(index).PayForm = PAYMENT::PF_CONTRACT;
	if (PaymentBox->SelectedIndex == 1) base.at(index).PayForm = PAYMENT::PF_BUDGET;
	if (PaymentBox->SelectedIndex == 2) base.at(index).PayForm = PAYMENT::PF_TARGET;
	//
	if (std::regex_match(Stos(NameBox->Text), NAME_REGEX) && std::regex_match(Stos(LastnameBox->Text), NAME_REGEX) && std::regex_match(Stos(GroupBox->Text), GROUP_REGEX)) 
	{
		if (!isExist(CardToRF(base[index]), path_))
		{
			RewriteBase(base, path_);
			this->Close();
		}
		else DoAlert("Такой студент уже есть в базе!");
	}
}
};
}
