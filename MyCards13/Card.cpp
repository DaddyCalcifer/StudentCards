#include "CardHead.h"


	Card::Card(std::string const name_, std::string const lastname_, int ayear_, PAYMENT pform_)
	{
		Name = name_; Lastname = lastname_;
		AdmissionYear = ayear_; PayForm = pform_;
	}
	Card::Card() {}

	std::string Card::GetInfo()
	{
		std::string res = Name + " " + Lastname + " " + Group;
		if (PayForm == PAYMENT::PF_CONTRACT) res += " 0";
		if (PayForm == PAYMENT::PF_BUDGET) res += " 1";
		if (PayForm == PAYMENT::PF_TARGET) res += " 2";
		return res;
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