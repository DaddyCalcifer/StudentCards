#pragma once
#include "CardHead.h"

std::string CardToText(Card& card);
std::string CardToRF(Card& card);
void ReadBase(System::Windows::Forms::ListBox^ box, std::string path);
void RewriteBase(std::vector<Card> &base_, std::string path);
void RewriteBase(std::vector<WorkerCard>& base_);
std::vector<Card> load_base(std::string path);
std::vector<WorkerCard> load_base();
void BaseAppend(std::string card, std::string path);
Card TextToCard(std::string txt);
void DoAlert(System::String^ alert);
System::String^ stoS(std::string& os);
std::string Stos(System::String^ s);
int log_in(String^ login, String^ password);
void AddAccount(String^ login, String^ password, int auth_level);
void SaveLoginInfo(String^ login, String^ password);
String^ ReadLogin();
String^ ReadPassword();
std::string GetPath(Windows::Forms::ComboBox^ box);
bool isExist(std::string line, std::string pathh);
void RefreshWorkersBox(Windows::Forms::ListBox^ box);
WorkerCard TextToWCard(std::string txt);
System::String^ GetLineCountS(std::string path_);