#include "InfoForm.h"

MyCards13::InfoForm::InfoForm(Card& card, int c_ind, int f_ind, bool canEdit)
{
	InitializeComponent();

	card_index = c_ind; facultyIndex = f_ind;
	if (!canEdit) EditButton->Enabled = false;
	InfoText->Text += "Имя: " + stoS(card.GetName()); InfoText->Text += System::Environment::NewLine;
	InfoText->Text += "Фамилия: " + stoS(card.GetLastname()); InfoText->Text += System::Environment::NewLine;
	InfoText->Text += "Год поступления: " + card.GetAYear().ToString(); InfoText->Text += System::Environment::NewLine;
	InfoText->Text += "Группа: " + stoS(card.Group); InfoText->Text += System::Environment::NewLine;

	if (card.PayForm == PAYMENT::PF_BUDGET) InfoText->Text += "Бюджетное обучение";
	if (card.PayForm == PAYMENT::PF_CONTRACT) InfoText->Text += "Контрактное обучение";
	if (card.PayForm == PAYMENT::PF_TARGET) InfoText->Text += "Обучение по целевому направлению";
	if (card.PayForm == PAYMENT::PF_NONE) InfoText->Text += "Тип оплаты за обучение не указан";
	InfoText->Text += System::Environment::NewLine;

	if (card.StudyForm == STUDY_TYPE::ST_COLLEGE) InfoText->Text += "Форма обучения: Колледж";
	if (card.StudyForm == STUDY_TYPE::ST_SEMI_HIGH) InfoText->Text += "Форма обучения: Неполное высшее (Бакалавр)";
	if (card.StudyForm == STUDY_TYPE::ST_FULL_HIGH) InfoText->Text += "Форма обучения: Полное высшее (Магистр)";
	if (card.StudyForm == STUDY_TYPE::ST_SPECIALIST) InfoText->Text += "Форма обучения: Специалитет";
	InfoText->Text += System::Environment::NewLine;

	InfoText->Text += "Доп. сведения: " + card.GetDescription();
}
System::Void MyCards13::InfoForm::EditButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	EditCardForm^ form = gcnew EditCardForm(card_index, facultyIndex);
	form->ShowDialog();
	this->Close();
}
System::Void MyCards13::InfoForm::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}