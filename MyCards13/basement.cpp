#include "funcsHeader.h"

std::string CardToText(Card& card)
	{
		std::string res = "";
		res = card.GetName() + " " + card.GetLastname() + "\t\t" /*+ std::to_string(card.GetAYear()) + " "*/;
		/*if (card.Faculty == FACULTY::MATH) res = res + F_MATH + " ";
		if (card.Faculty == FACULTY::TECH) res = res + F_TECH + " ";
		if (card.Faculty == FACULTY::RAILWAY) res = res + F_RAILWAY + " ";
		if (card.Faculty == FACULTY::ROAD_TRANSPORT) res = res + F_ROAD_TRANSPORT + " ";
		if (card.Faculty == FACULTY::ISTECH) res = res + F_ISTECH + " ";
		if (card.Faculty == FACULTY::INTERNATIONAL) res = res + F_INTERNATIONAL + " ";*/

		res = res + card.Group + "  \t";

		/*if (card.StudyForm == STUDY_TYPE::ST_COLLEGE) res = res + SF_COLLEGE + " ";
		if (card.StudyForm == STUDY_TYPE::ST_FULL_HIGH) res = res + SF_FULL_HIGH + " ";
		if (card.StudyForm == STUDY_TYPE::ST_SEMI_HIGH) res = res + SF_SEMI_HIGH + " ";
		if (card.StudyForm == STUDY_TYPE::ST_SPECIALIST) res = res + SF_SPECIALIST + " ";*/

		if (card.PayForm == PAYMENT::PF_BUDGET) res = res + "Бюджет";
		if (card.PayForm == PAYMENT::PF_CONTRACT) res = res + "Контракт";
		if (card.PayForm == PAYMENT::PF_TARGET) res = res + "Направление";

		return res;
	}
std::string CardToRF(Card& card)
	{
		std::string res = "";
		res = card.GetName() + " " + card.GetLastname() + " ";
		/*if (card.Faculty == FACULTY::MATH) res = res + "1" + " ";
		if (card.Faculty == FACULTY::TECH) res = res + "2" + " ";
		if (card.Faculty == FACULTY::RAILWAY) res = res + "3" + " ";
		if (card.Faculty == FACULTY::ROAD_TRANSPORT) res = res + "4" + " ";
		if (card.Faculty == FACULTY::ISTECH) res = res + "5" + " ";
		if (card.Faculty == FACULTY::INTERNATIONAL) res = res + "6" + " ";*/

		res += card.Group; res += " ";

		if (card.PayForm == PAYMENT::PF_BUDGET) res += "1\n";
		if (card.PayForm == PAYMENT::PF_CONTRACT) res += "0\n";
		if (card.PayForm == PAYMENT::PF_TARGET) res += "2\n";

		return res;
	}
void ReadBase(System::Windows::Forms::ListBox^ box, std::string path)
	{
		std::string line;
		std::ifstream in(path);
		if (in.is_open())
		{
			while (getline(in, line))
			{
				Card buffer = TextToCard(line);
				line = CardToText(buffer);
				box->Items->Add(stoS(line));
			}
		}
		in.close();
	}
void RewriteBase(std::vector<Card> &base_, std::string path)
{
	std::ofstream out;          // поток для записи
	out.open(path); // окрываем файл для записи
	if (out.is_open())
	{
		for (int i = 0; i < base_.size(); i++)
		{
			out << CardToRF(base_.at(i));
		}
	}
	out.close();
}
void RewriteBase(std::vector<WorkerCard>& base_)
{
	std::ofstream out;          // поток для записи
	out.open(WORKERS_PATH); // окрываем файл для записи
	if (out.is_open())
	{
		for (int i = 0; i < base_.size(); i++)
		{
			out << base_[i].GetInfo() + "\n";
		}
	}
	out.close();
}
void BaseAppend(std::string card, std::string path)
{
	std::ofstream out(path, std::ios::app);
	if (out.is_open())
	{
		out << card << std::endl;
	}
	out.close();
}


	Card TextToCard(std::string txt)
	{
		std::cmatch info_;
		if (regex_match(txt.c_str(), info_, STUDENT_REGEX))
		{
			Card card_(info_[1], info_[2], 2000, PAYMENT::PF_BUDGET);

			if (info_[3] == "б" || info_[3] == "с" || info_[3] == "к" || info_[3] == "м")
			{
				if (info_[3] == "б") card_.StudyForm = STUDY_TYPE::ST_SEMI_HIGH;
				if (info_[3] == "с") card_.StudyForm = STUDY_TYPE::ST_SPECIALIST;
				if (info_[3] == "м") card_.StudyForm = STUDY_TYPE::ST_FULL_HIGH;
				if (info_[3] == "к") card_.StudyForm = STUDY_TYPE::ST_COLLEGE;
			}

			card_.Group.append(info_[3]); card_.Group.append(info_[4]); card_.Group += "-";
			card_.Group.append(info_[5]); card_.Group.append(info_[6]);
			card_.CorrectYear(2000 + stoi(info_[5]));

			switch (stoi(info_[7]))
			{
			case 0: card_.PayForm = PAYMENT::PF_CONTRACT; break;
			case 1: card_.PayForm = PAYMENT::PF_BUDGET; break;
			case 2: card_.PayForm = PAYMENT::PF_TARGET; break;
			}

			return card_;
		}
		return Card();
	}
	std::vector<Card> load_base (std::string path)
	{
		std::vector<Card> base_;
		std::string line;
		std::ifstream in(path); // окрываем файл для чтения
		if (in.is_open())
		{
			while (getline(in, line))
			{
				base_.push_back(TextToCard(line));
			}
		}
		in.close();
		return base_;
	}
	std::vector<WorkerCard> load_base()
	{
		std::vector<WorkerCard> base_;
		std::string line;
		std::ifstream in(WORKERS_PATH); // окрываем файл для чтения
		if (in.is_open())
		{
			while (getline(in, line))
			{
				base_.push_back(TextToWCard(line));
			}
		}
		in.close();
		return base_;
	}

	int log_in(String^ login, String^ password)
	{
		std::string line_;
		std::ifstream in(ACCOUNTS);
		if (in.is_open())
		{
			while (getline(in, line_))
			{
				if (line_ == (Stos(login) + " " + Stos(password)) + " 1")
					return 1;
				if (line_ == (Stos(login) + " " + Stos(password)) + " 0")
					return 0;
			}
		}
		in.close();
		return -1;
	}
	void AddAccount(String^ login, String^ password, int auth_level)
	{
		std::string log_pas_au = Stos(login) + " " + Stos(password) + " " + std::to_string(auth_level);
		std::ofstream out(ACCOUNTS, std::ios::app);
		if (out.is_open())
		{
			out << "\n" << log_pas_au;
		}
		out.close();
	}
	std::string GetPath(Windows::Forms::ComboBox^ box)
	{
		std::string res;
		switch (box->SelectedIndex)
		{
		case 0:
			res = "math_fac.cdb";
			break;
		case 1:
			res = "tech_fac.cdb";
			break;
		case 2:
			res = "railway_fac.cdb";
			break;
		case 3:
			res = "roadt_fac.cdb";
			break;
		case 4:
			res = "ist_fac.cdb";
			break;
		case 5:
			res = "inat_fac.cdb";
			break;
		default:
			DoAlert("Вы не выбрали факультет!");
			break;
		}
		return res;
	}
	bool isExist(std::string line, std::string pathh)
	{
		std::string line_;
		std::ifstream in(pathh);
		if (in.is_open())
		{
			while (getline(in, line_)) {if (line_ == line) return true; }
		}
		in.close();
		return false;
	}
	void SaveLoginInfo(String^ login, String^ password)
	{
		std::string datal = Stos(login) + "\n" + Stos(password);
		std::ofstream out;          // поток для записи
		out.open(LOGIN_PATH); // окрываем файл для записи
		if (out.is_open())
		{
			out << datal;
		}
		out.close();
	}
	String^ ReadLogin()
	{
		std::string line;
		std::ifstream in(LOGIN_PATH); // окрываем файл для чтения
		if (in.is_open())
		{
			getline(in, line);
		}
		in.close();
		return stoS(line);
	}
	String^ ReadPassword()
	{
		std::string line;
		std::ifstream in(LOGIN_PATH); // окрываем файл для чтения
		if (in.is_open())
		{
			for (size_t i = 0; i < 2; i++) getline(in, line);
		}
		in.close();
		return stoS(line);
	}
	//
	//
	WorkerCard TextToWCard(std::string txt)
	{
		std::cmatch info_;
		if (regex_match(txt.c_str(), info_, WORKER_REGEX))
		{
			WorkerCard card_(info_[1], info_[2], info_[3], stoi(info_[4]), stoi(info_[5]));
			return card_;
		}
		return WorkerCard();
	}
	void RefreshWorkersBox(Windows::Forms::ListBox^ box)
	{
		box->Items->Clear();
		//
		std::string line;
		std::ifstream in(WORKERS_PATH);
		if (in.is_open())
		{
			while (getline(in, line))
			{
				WorkerCard buffer = TextToWCard(line);
				line = buffer.GetInfoFixed();
				box->Items->Add(stoS(line));
			}
		}
		in.close();
	}