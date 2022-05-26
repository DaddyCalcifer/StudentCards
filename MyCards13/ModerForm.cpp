#include "ModerForm.h"

MyCards13::ModerForm::ModerForm(void)
{
	InitializeComponent();
	addPaymentBox->SelectedIndex = 0;
	RefreshWorkersBox(WorkersBox);
	workers_ = load_base();
}
MyCards13::ModerForm::~ModerForm()
{
	_base.clear();
	DoAlert("�� ��������!");
	if (components)
	{
		delete components;
	}
}
System::Void MyCards13::ModerForm::ShowStuds_Click(System::Object^ sender, System::EventArgs^ e)
{
	StudentsBox->Items->Clear();
	std::string path_ = GetPath(facultiesBox);
	_base = load_base(path_);
	ReadBase(StudentsBox, path_);
}
System::Void MyCards13::ModerForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
System::Void MyCards13::ModerForm::clearButt_Click(System::Object^ sender, System::EventArgs^ e)
{
	StudentsBox->Items->Clear();
}
System::Void MyCards13::ModerForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (StudentsBox->SelectedIndex >= 0)
	{
		_base.erase(_base.begin() + StudentsBox->SelectedIndex);
		std::string path_ = GetPath(facultiesBox);
		RewriteBase(_base, path_);
		StudentsBox->Items->Clear();
		ReadBase(StudentsBox, path_);
	}
	else { DoAlert("�� �� ������� ��������!"); }
}
System::Void MyCards13::ModerForm::EditButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (StudentsBox->SelectedIndex >= 0)
	{
		EditCardForm^ form = gcnew EditCardForm(StudentsBox->SelectedIndex, facultiesBox->SelectedIndex);
		form->ShowDialog();
		StudentsBox->Items->Clear();
		ReadBase(StudentsBox, GetPath(facultiesBox));
	}
	else { DoAlert("�� �� ������� ��������!"); }
}
System::Void MyCards13::ModerForm::AddButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string NewStudent = Stos(addNameBox->Text);
	NewStudent = NewStudent + " " + Stos(addLNameBox->Text);
	NewStudent = NewStudent + " " + Stos(addGroupBox->Text) + " ";
	NewStudent += std::to_string(addPaymentBox->SelectedIndex);
	NewStudent += " ";
	NewStudent += Stos(addStudentInfo->Text);
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
		else DoAlert("����� ������� ��� ���� � ����!");
	}
	else if (path_ != "") DoAlert("�� �� ��������� ����� ������ ��������!");
}
System::Void MyCards13::ModerForm::ClearAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		addNameBox->Clear();
		addLNameBox->Clear();
		addGroupBox->Clear();
		addPaymentBox->SelectedIndex = 0;
}
System::Void MyCards13::ModerForm::AddWorker_Click(System::Object^ sender, System::EventArgs^ e) //�������� ���������
{
		std::string stats = Stos(workerNameBox->Text) + " " + Stos(workerLNameBox->Text) + " "
			+ Stos(workerPostBox->Text) + " 2022 " + Stos(addSalaryBox->Value.ToString());
		if (std::regex_match(stats, WORKER_REGEX))
		{
			workers_.push_back(TextToWCard(stats));
			BaseAppend(stats, WORKERS_PATH);
			RefreshWorkersBox(WorkersBox);
			//
			if (clearWorkerBox->Checked)
			{
				workerNameBox->Clear();
				workerLNameBox->Clear();
				workerPostBox->Clear();
			}
		}
		else { DoAlert("������� ������������ ������!"); }
	}
System::Void MyCards13::ModerForm::clearWorkerButton_Click(System::Object^ sender, System::EventArgs^ e) //�������� �����
	{
		workerNameBox->Clear();
		workerLNameBox->Clear();
		workerPostBox->Clear();
	}
		   int iq0_counter = 0;
System::Void MyCards13::ModerForm::deleteWorker_Click(System::Object^ sender, System::EventArgs^ e) //������� ���������
	{
		if (WorkersBox->SelectedIndex >= 0)
		{
			workers_.erase(workers_.begin() + WorkersBox->SelectedIndex);
			RewriteBase(workers_);
			RefreshWorkersBox(WorkersBox);
			iq0_counter = 0;
		}
		else { if (iq0_counter >= 13) DoAlert("�� �� � ������, ��������� ���!"); else { DoAlert("�� �� ������� ���������!"); iq0_counter++; } }
	}
System::Void MyCards13::ModerForm::NewPost_Click(System::Object^ sender, System::EventArgs^ e) //�������� ���������
	{
		if (WorkersBox->SelectedIndex >= 0)
		{
			workers_.at(WorkersBox->SelectedIndex).SetPost(Stos(newWorkerPost->Text));
			if (std::regex_match(workers_.at(WorkersBox->SelectedIndex).GetInfo(), WORKER_REGEX))
			{
				RewriteBase(workers_);
				RefreshWorkersBox(WorkersBox);
			}
			else DoAlert("������� ������������ ������!");
		}
		else { DoAlert("�� �� ������� ���������!"); }
	}
System::Void MyCards13::ModerForm::newSalary_Click(System::Object^ sender, System::EventArgs^ e) //�������� ��������
	{
		if (WorkersBox->SelectedIndex >= 0)
		{
			workers_.at(WorkersBox->SelectedIndex).ChangeSalary(newSalaryBox->Value.ToInt32(newSalaryBox->Value));
			if (std::regex_match(workers_.at(WorkersBox->SelectedIndex).GetInfo(), WORKER_REGEX))
			{
				RewriteBase(workers_);
				RefreshWorkersBox(WorkersBox);
			}
			else DoAlert("������� ������������ ������!");
		}
		else { DoAlert("�� �� ������� ���������!"); }
	}
System::Void MyCards13::ModerForm::button1_Click_1(System::Object^ sender, System::EventArgs^ e)
{
		if (StudentsBox->SelectedIndex >= 0)
		{
			InfoForm^ form = gcnew InfoForm(_base.at(StudentsBox->SelectedIndex), StudentsBox->SelectedIndex, facultiesBox->SelectedIndex, true);
			form->ShowDialog();
			StudentsBox->Items->Clear();
			ReadBase(StudentsBox, GetPath(facultiesBox));
		}
		else DoAlert("�� �� ������� ��������!");
}