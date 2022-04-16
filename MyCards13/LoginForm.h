#pragma once
#include "GuestForm.h"
#include "ModerForm.h"

namespace MyCards13 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			if (ReadLogin() != "") LoginTextbox->Text = ReadLogin();
			if (ReadPassword() != "") 
			{ 
				PasswordTextbox->Text = ReadPassword();
				saveLoginInfo->Checked = true;
			}
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ LoginTextbox;
	protected:
	private: System::Windows::Forms::TextBox^ PasswordTextbox;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ logAsGuest;
	private: System::Windows::Forms::CheckBox^ saveLoginInfo;
	private: System::Windows::Forms::CheckBox^ autoExit;


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
			this->LoginTextbox = (gcnew System::Windows::Forms::TextBox());
			this->PasswordTextbox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->logAsGuest = (gcnew System::Windows::Forms::Button());
			this->saveLoginInfo = (gcnew System::Windows::Forms::CheckBox());
			this->autoExit = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// LoginTextbox
			// 
			this->LoginTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17));
			this->LoginTextbox->Location = System::Drawing::Point(12, 12);
			this->LoginTextbox->Name = L"LoginTextbox";
			this->LoginTextbox->Size = System::Drawing::Size(298, 40);
			this->LoginTextbox->TabIndex = 0;
			this->LoginTextbox->Text = L"ЛОГИН";
			this->LoginTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// PasswordTextbox
			// 
			this->PasswordTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17));
			this->PasswordTextbox->Location = System::Drawing::Point(12, 58);
			this->PasswordTextbox->MinimumSize = System::Drawing::Size(240, 34);
			this->PasswordTextbox->Name = L"PasswordTextbox";
			this->PasswordTextbox->PasswordChar = '*';
			this->PasswordTextbox->Size = System::Drawing::Size(298, 40);
			this->PasswordTextbox->TabIndex = 1;
			this->PasswordTextbox->Text = L"ПАРОЛЬ";
			this->PasswordTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17));
			this->button1->Location = System::Drawing::Point(11, 164);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(298, 45);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Войти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// logAsGuest
			// 
			this->logAsGuest->Location = System::Drawing::Point(12, 215);
			this->logAsGuest->Name = L"logAsGuest";
			this->logAsGuest->Size = System::Drawing::Size(297, 29);
			this->logAsGuest->TabIndex = 3;
			this->logAsGuest->Text = L"Сведения об Университете";
			this->logAsGuest->UseVisualStyleBackColor = true;
			this->logAsGuest->Click += gcnew System::EventHandler(this, &LoginForm::button2_Click);
			// 
			// saveLoginInfo
			// 
			this->saveLoginInfo->AutoSize = true;
			this->saveLoginInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->saveLoginInfo->Location = System::Drawing::Point(12, 104);
			this->saveLoginInfo->Name = L"saveLoginInfo";
			this->saveLoginInfo->Size = System::Drawing::Size(286, 24);
			this->saveLoginInfo->TabIndex = 4;
			this->saveLoginInfo->Text = L"Запомнить данные для входа";
			this->saveLoginInfo->UseVisualStyleBackColor = true;
			// 
			// autoExit
			// 
			this->autoExit->AutoSize = true;
			this->autoExit->Checked = true;
			this->autoExit->CheckState = System::Windows::Forms::CheckState::Checked;
			this->autoExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->autoExit->Location = System::Drawing::Point(12, 134);
			this->autoExit->Name = L"autoExit";
			this->autoExit->Size = System::Drawing::Size(230, 24);
			this->autoExit->TabIndex = 5;
			this->autoExit->Text = L"Автоматический выход";
			this->autoExit->UseVisualStyleBackColor = true;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(322, 256);
			this->Controls->Add(this->autoExit);
			this->Controls->Add(this->saveLoginInfo);
			this->Controls->Add(this->logAsGuest);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->PasswordTextbox);
			this->Controls->Add(this->LoginTextbox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(282, 234);
			this->Name = L"LoginForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вход";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			GuestForm^ form = gcnew GuestForm();
			this->Hide();
			form->ShowDialog();
			this->Show();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int auth_ = log_in(LoginTextbox->Text, PasswordTextbox->Text);
	if (auth_ != -1) 
	{
		if (saveLoginInfo->Checked) SaveLoginInfo(LoginTextbox->Text, PasswordTextbox->Text);
		else SaveLoginInfo("", "");
		if (auth_ == 1) 
		{
			ModerForm^ form = gcnew ModerForm();
			this->Hide();
			form->ShowDialog();
			if (autoExit->Checked) this->Close();
			else this->Show();
		}
		if (auth_ == 0)
		{
			MessageBox::Show("Форма студента находится в разработке :(", "недодел");
		}
	}
	else { 
		MessageBox::Show("Неправильный логин или пароль!", "Ошибка входа"); 
		PasswordTextbox->Clear();
	}
}
private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
