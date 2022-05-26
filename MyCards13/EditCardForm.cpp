#include "EditCardForm.h"

MyCards13::EditCardForm::EditCardForm(int ind, int fac)
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

	editInfoBox->Text = base[index].GetDescription();
}
System::Void MyCards13::EditCardForm::SaveButton_Click(System::Object^ sender, System::EventArgs^ e)
{
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

	base.at(index).SetDescription(Stos(editInfoBox->Text));
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