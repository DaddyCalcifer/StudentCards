#include "funcsHeader.h"


	Card::Card(std::string const name_, std::string const lastname_, int ayear_, PAYMENT pform_)
	{
		Name = name_; Lastname = lastname_;
		AdmissionYear = ayear_; PayForm = pform_;
	}
	WorkerCard::WorkerCard(std::string const name_, std::string const lname_, std::string post_, int ayear_, int salary_)
	{
		Name = name_; Lastname = lname_; Post = post_;
		AdmissionYear = ayear_; Salary = salary_;
	}
	WorkerCard::WorkerCard() {}
	Card::Card() {}

	std::string Card::GetInfo()
	{
		std::string res = Name + " " + Lastname + " " + Group;
		if (PayForm == PAYMENT::PF_CONTRACT) res += " 0";
		if (PayForm == PAYMENT::PF_BUDGET) res += " 1";
		if (PayForm == PAYMENT::PF_TARGET) res += " 2";
		return res;
	}
	System::String^ Card::GetDescription()
	{
		return stoS(info);
	}
	void Card::SetDescription(std::string info_)
	{
		info = info_;
	}

	std::string WorkerCard::GetPost() { return Post; }
	void WorkerCard::SetPost(std::string new_post) { this->Post = new_post; }
	int WorkerCard::GetSalary() { return Salary; }
	void WorkerCard::ChangeSalary(int new_s) { this->Salary = new_s; }
	std::string WorkerCard::GetInfo() 
	{
		return Name + " " + Lastname + " " + Post + " " + std::to_string(AdmissionYear) + " " + std::to_string(Salary);
	}
	std::string WorkerCard::GetInfoFixed()
	{
		return Name + " " + Lastname + "\t\t" + Post + "      \t" + std::to_string(AdmissionYear) + " г.\t\t" + std::to_string(Salary) + " руб.";
	}

	std::string Human::GetName() { return Name; }
	std::string Human::GetLastname() { return Lastname; }
	int Human::GetAYear() { return AdmissionYear; }

	System::String^ stoS(std::string& os) // из std::string в String
	{
		System::String^ s;
		s = gcnew System::String(os.c_str());
		return s;
	}
	std::string Stos(System::String^ s) // из String в std::string
	{
		using namespace System::Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		std::string os(chars);
		return os;
	}

	void Human::CorrectYear(int crt) { AdmissionYear = crt; }
	void Human::ChangeName(String^ newn)
	{
		std::string name;
		Human::Name = Stos(newn);
	}
	void Human::ChangeLastname(String^ newln)
	{
		std::string lname;
		Human::Lastname = Stos(newln);
	}

	void DoAlert(System::String^ alert)
	{
		System::Windows::MessageBox::Show(alert, "ќшибка!");
	}