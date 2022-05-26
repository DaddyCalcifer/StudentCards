#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MyCards13::LoginForm form;
	Application::Run(% form);
}
MyCards13::LoginForm::LoginForm(void)
{
	InitializeComponent();
	if (ReadLogin() != "") LoginTextbox->Text = ReadLogin();
	if (ReadPassword() != "")
	{
		PasswordTextbox->Text = ReadPassword();
		saveLoginInfo->Checked = true;
	}
}
System::Void MyCards13::LoginForm::button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	GuestForm^ form = gcnew GuestForm();
	this->Hide();
	form->ShowDialog();
	this->Show();
}
System::Void MyCards13::LoginForm::button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
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
	else 
	{
		MessageBox::Show("Неправильный логин или пароль!", "Ошибка входа");
		PasswordTextbox->Clear();
	}
}