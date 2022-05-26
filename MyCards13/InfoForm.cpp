#include "InfoForm.h"

MyCards13::InfoForm::InfoForm(Card& card, int c_ind, int f_ind, bool canEdit)
{
	InitializeComponent();

	card_index = c_ind; facultyIndex = f_ind;
	if (!canEdit) EditButton->Enabled = false;
	InfoText->Text += "���: " + stoS(card.GetName()); InfoText->Text += System::Environment::NewLine;
	InfoText->Text += "�������: " + stoS(card.GetLastname()); InfoText->Text += System::Environment::NewLine;
	InfoText->Text += "��� �����������: " + card.GetAYear().ToString(); InfoText->Text += System::Environment::NewLine;
	InfoText->Text += "������: " + stoS(card.Group); InfoText->Text += System::Environment::NewLine;

	if (card.PayForm == PAYMENT::PF_BUDGET) InfoText->Text += "��������� ��������";
	if (card.PayForm == PAYMENT::PF_CONTRACT) InfoText->Text += "����������� ��������";
	if (card.PayForm == PAYMENT::PF_TARGET) InfoText->Text += "�������� �� �������� �����������";
	if (card.PayForm == PAYMENT::PF_NONE) InfoText->Text += "��� ������ �� �������� �� ������";
	InfoText->Text += System::Environment::NewLine;

	if (card.StudyForm == STUDY_TYPE::ST_COLLEGE) InfoText->Text += "����� ��������: �������";
	if (card.StudyForm == STUDY_TYPE::ST_SEMI_HIGH) InfoText->Text += "����� ��������: �������� ������ (��������)";
	if (card.StudyForm == STUDY_TYPE::ST_FULL_HIGH) InfoText->Text += "����� ��������: ������ ������ (�������)";
	if (card.StudyForm == STUDY_TYPE::ST_SPECIALIST) InfoText->Text += "����� ��������: �����������";
	InfoText->Text += System::Environment::NewLine;

	InfoText->Text += "���. ��������: " + card.GetDescription();
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