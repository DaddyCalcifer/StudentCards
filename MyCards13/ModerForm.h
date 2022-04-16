#pragma once
#include "funcsHeader.h"
#include "EditCardForm.h"

namespace MyCards13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static std::vector<Card> _base;

	/// <summary>
	/// Сводка для ModerForm
	/// </summary>
	public ref class ModerForm : public System::Windows::Forms::Form
	{
	public:
		ModerForm(void)
		{
			InitializeComponent();
			addPaymentBox->SelectedIndex = 0;
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ModerForm()
		{
			if (components)
			{
				delete components;
			}
			_base.clear();
			//Application::Exit();
		}
	private: System::Windows::Forms::ListBox^ StudentsBox;
	protected:

	private: System::Windows::Forms::ComboBox^ facultiesBox;
	protected:


	private: System::Windows::Forms::Button^ ShowStuds;

	private: System::Windows::Forms::Button^ EditButton;
	private: System::Windows::Forms::Button^ DeleteButton;
	private: System::Windows::Forms::GroupBox^ AddStudentGBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ ClearAddButton;
	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::ComboBox^ addPaymentBox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ addGroupBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ addLNameBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ addNameBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ clearBool;



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
			this->StudentsBox = (gcnew System::Windows::Forms::ListBox());
			this->facultiesBox = (gcnew System::Windows::Forms::ComboBox());
			this->ShowStuds = (gcnew System::Windows::Forms::Button());
			this->EditButton = (gcnew System::Windows::Forms::Button());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->AddStudentGBox = (gcnew System::Windows::Forms::GroupBox());
			this->clearBool = (gcnew System::Windows::Forms::CheckBox());
			this->ClearAddButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->addPaymentBox = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->addGroupBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->addLNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->addNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->AddStudentGBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// StudentsBox
			// 
			this->StudentsBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->StudentsBox->FormattingEnabled = true;
			this->StudentsBox->ItemHeight = 20;
			this->StudentsBox->Location = System::Drawing::Point(12, 55);
			this->StudentsBox->Name = L"StudentsBox";
			this->StudentsBox->Size = System::Drawing::Size(589, 404);
			this->StudentsBox->TabIndex = 0;
			// 
			// facultiesBox
			// 
			this->facultiesBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->facultiesBox->FormattingEnabled = true;
			this->facultiesBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Математический факультет", L"Технический факультет",
					L"Железнодорожный факультет", L"Дорожно-транспортный факультет", L"Факультет информационных систем и технологий", L"Международный факультет"
			});
			this->facultiesBox->Location = System::Drawing::Point(212, 12);
			this->facultiesBox->Name = L"facultiesBox";
			this->facultiesBox->Size = System::Drawing::Size(569, 28);
			this->facultiesBox->TabIndex = 1;
			// 
			// ShowStuds
			// 
			this->ShowStuds->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->ShowStuds->Location = System::Drawing::Point(787, 12);
			this->ShowStuds->Name = L"ShowStuds";
			this->ShowStuds->Size = System::Drawing::Size(164, 28);
			this->ShowStuds->TabIndex = 3;
			this->ShowStuds->Text = L"Показать";
			this->ShowStuds->UseVisualStyleBackColor = true;
			this->ShowStuds->Click += gcnew System::EventHandler(this, &ModerForm::ShowStuds_Click);
			// 
			// EditButton
			// 
			this->EditButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->EditButton->Location = System::Drawing::Point(12, 465);
			this->EditButton->Name = L"EditButton";
			this->EditButton->Size = System::Drawing::Size(295, 45);
			this->EditButton->TabIndex = 5;
			this->EditButton->Text = L"Изменить выбранного";
			this->EditButton->UseVisualStyleBackColor = true;
			this->EditButton->Click += gcnew System::EventHandler(this, &ModerForm::EditButton_Click);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->DeleteButton->Location = System::Drawing::Point(313, 465);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(288, 45);
			this->DeleteButton->TabIndex = 6;
			this->DeleteButton->Text = L"Удалить выбранного";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &ModerForm::button3_Click);
			// 
			// AddStudentGBox
			// 
			this->AddStudentGBox->Controls->Add(this->clearBool);
			this->AddStudentGBox->Controls->Add(this->ClearAddButton);
			this->AddStudentGBox->Controls->Add(this->AddButton);
			this->AddStudentGBox->Controls->Add(this->addPaymentBox);
			this->AddStudentGBox->Controls->Add(this->label5);
			this->AddStudentGBox->Controls->Add(this->addGroupBox);
			this->AddStudentGBox->Controls->Add(this->label4);
			this->AddStudentGBox->Controls->Add(this->addLNameBox);
			this->AddStudentGBox->Controls->Add(this->label3);
			this->AddStudentGBox->Controls->Add(this->addNameBox);
			this->AddStudentGBox->Controls->Add(this->label2);
			this->AddStudentGBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->AddStudentGBox->Location = System::Drawing::Point(616, 55);
			this->AddStudentGBox->Name = L"AddStudentGBox";
			this->AddStudentGBox->Size = System::Drawing::Size(335, 244);
			this->AddStudentGBox->TabIndex = 7;
			this->AddStudentGBox->TabStop = false;
			this->AddStudentGBox->Text = L"Добавить студента";
			// 
			// clearBool
			// 
			this->clearBool->AutoSize = true;
			this->clearBool->Checked = true;
			this->clearBool->CheckState = System::Windows::Forms::CheckState::Checked;
			this->clearBool->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->clearBool->Location = System::Drawing::Point(9, 162);
			this->clearBool->Name = L"clearBool";
			this->clearBool->Size = System::Drawing::Size(311, 24);
			this->clearBool->TabIndex = 17;
			this->clearBool->Text = L"Очищать форму при добавлении";
			this->clearBool->UseVisualStyleBackColor = true;
			// 
			// ClearAddButton
			// 
			this->ClearAddButton->Location = System::Drawing::Point(289, 192);
			this->ClearAddButton->Name = L"ClearAddButton";
			this->ClearAddButton->Size = System::Drawing::Size(31, 42);
			this->ClearAddButton->TabIndex = 16;
			this->ClearAddButton->Text = L"#";
			this->ClearAddButton->UseVisualStyleBackColor = true;
			this->ClearAddButton->Click += gcnew System::EventHandler(this, &ModerForm::ClearAddButton_Click);
			// 
			// AddButton
			// 
			this->AddButton->Location = System::Drawing::Point(10, 192);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(273, 42);
			this->AddButton->TabIndex = 9;
			this->AddButton->Text = L"Добавить";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &ModerForm::AddButton_Click);
			// 
			// addPaymentBox
			// 
			this->addPaymentBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->addPaymentBox->FormattingEnabled = true;
			this->addPaymentBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Контракт\t", L"Бюджет", L"Направление" });
			this->addPaymentBox->Location = System::Drawing::Point(155, 130);
			this->addPaymentBox->Name = L"addPaymentBox";
			this->addPaymentBox->Size = System::Drawing::Size(165, 26);
			this->addPaymentBox->TabIndex = 9;
			this->addPaymentBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ModerForm::addPaymentBox_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(6, 130);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(134, 20);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Форма оплаты";
			// 
			// addGroupBox
			// 
			this->addGroupBox->Location = System::Drawing::Point(155, 95);
			this->addGroupBox->Name = L"addGroupBox";
			this->addGroupBox->Size = System::Drawing::Size(165, 26);
			this->addGroupBox->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(6, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 20);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Группа";
			// 
			// addLNameBox
			// 
			this->addLNameBox->Location = System::Drawing::Point(155, 63);
			this->addLNameBox->Name = L"addLNameBox";
			this->addLNameBox->Size = System::Drawing::Size(165, 26);
			this->addLNameBox->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(5, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Фамилия";
			// 
			// addNameBox
			// 
			this->addNameBox->Location = System::Drawing::Point(155, 31);
			this->addNameBox->Name = L"addNameBox";
			this->addNameBox->Size = System::Drawing::Size(165, 26);
			this->addNameBox->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(6, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 20);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Имя";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(12, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Выберете факульет";
			// 
			// ModerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(965, 522);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ShowStuds);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->EditButton);
			this->Controls->Add(this->facultiesBox);
			this->Controls->Add(this->StudentsBox);
			this->Controls->Add(this->AddStudentGBox);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"ModerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вы зашли как: Модератор";
			this->Load += gcnew System::EventHandler(this, &ModerForm::ModerForm_Load);
			this->AddStudentGBox->ResumeLayout(false);
			this->AddStudentGBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
		this->Close();
}
private: System::Void ModerForm_Load(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void ShowStuds_Click(System::Object^ sender, System::EventArgs^ e) 
{
	StudentsBox->Items->Clear();
	std::string path_ = GetPath(facultiesBox);
	_base = load_base(path_);
	ReadBase(StudentsBox, path_);
}
private: System::Void clearButt_Click(System::Object^ sender, System::EventArgs^ e) 
{
	StudentsBox->Items->Clear();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (StudentsBox->SelectedIndex >= 0)
	{
		_base.erase(_base.begin() + StudentsBox->SelectedIndex);
		std::string path_ = GetPath(facultiesBox);
		RewriteBase(_base, path_);
		StudentsBox->Items->Clear();
		ReadBase(StudentsBox, path_);
	} else { DoAlert("Вы не выбрали студента!"); }
}
private: System::Void EditButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (StudentsBox->SelectedIndex >= 0)
	{
		EditCardForm^ form = gcnew EditCardForm(StudentsBox->SelectedIndex, facultiesBox->SelectedIndex);
		form->ShowDialog();
		StudentsBox->Items->Clear();
		ReadBase(StudentsBox, GetPath(facultiesBox));
	}
	else { DoAlert("Вы не выбрали студента!"); }
}
private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string NewStudent = Stos(addNameBox->Text);
	NewStudent = NewStudent + " " + Stos(addLNameBox->Text);
	NewStudent = NewStudent + " " + Stos(addGroupBox->Text) + " ";
	NewStudent += std::to_string(addPaymentBox->SelectedIndex);
	std::string path_ = GetPath(facultiesBox);
	if (std::regex_match(NewStudent.c_str(), STUDENT_REGEX))
	{
		if (!isExist(NewStudent, path_))
		{
			BaseAppend(NewStudent, path_);
			_base.push_back(TextToCard(NewStudent));

			StudentsBox->Items->Clear();
			ReadBase(StudentsBox, path_);

			AddAccount(addLNameBox->Text, addGroupBox->Text + "_" + addLNameBox->Text, 0);

			if (clearBool->Checked)
			{
				addNameBox->Clear();
				addLNameBox->Clear();
				addGroupBox->Clear();
			}
		}
		else DoAlert("Такой студент уже есть в базе!");
	} else if(path_ != "") DoAlert("Вы не корректно ввели данные студента!");
}
private: System::Void ClearAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
	addNameBox->Clear();
	addLNameBox->Clear();
	addGroupBox->Clear();
	addPaymentBox->SelectedIndex = 0;
}
private: System::Void addPaymentBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
};
}
