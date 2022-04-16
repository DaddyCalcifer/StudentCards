#pragma once
#include <Windows.h>
#include <string>
#include <vector>
#include <regex>
#include <fstream>

using namespace System;

#define F_MATH "��������������"
#define F_TECH "���������������"
#define F_RAILWAY "���������������"
#define F_ROAD_TRANSPORT "�������-������������"
#define F_ISTECH "�������������� ������� � ���������"
#define F_INTERNATIONAL "�������������"
#define SF_COLLEGE "�������"
#define SF_SEMI_HIGH "��������"
#define SF_FULL_HIGH "�������"
#define SF_SPECIALIST "�����������"
#define ACCOUNTS "accounts.cdb"
#define LOGIN_PATH "lastlog.cdb"

static std::regex STUDENT_REGEX("([�-��-�A-Za-z\\-]{2,20}) ([�-��-�A-Za-z\\-]{2,20}) ([����]{1})([�-�]{3})\\-([\\d]{2})([\\d]+) ([\\d]{1})");
static std::regex NAME_REGEX("([�-��-�A-Za-z\\-]{2,20})");
static std::regex GROUP_REGEX("([����]{1})([�-�]{3})\\-([\\d]{2})([\\d]+)");
static std::regex LOGIN_PASSWORD("([�-��-�A-Za-z\\-]{2,20}) ([�-��-�A-Za-z\\-]{2,20})");

enum class STUDY_TYPE {ST_SEMI_HIGH, ST_FULL_HIGH, ST_SPECIALIST, ST_COLLEGE};
enum class FACULTY {MATH, TECH, RAILWAY, ROAD_TRANSPORT, ISTECH, INTERNATIONAL};
enum class PAYMENT {PF_BUDGET, PF_CONTRACT, PF_TARGET};

class CH_ERROR : public std::exception
{
public:
	CH_ERROR(const char* error_log) : exception(error_log) {}
};

class Human
{
protected:
	std::string Name, Lastname;
	int AdmissionYear;
public:
	void CorrectYear(int crt);
	void ChangeName(String^ newn);
	void ChangeLastname(String^ newn);
	//
	std::string GetName();
	std::string GetLastname();
	int GetAYear();
	virtual std::string GetInfo() = 0;
};

class Card : public Human
{
public:
	std::string Group; FACULTY Faculty;
	PAYMENT PayForm = PAYMENT::PF_CONTRACT;
	STUDY_TYPE StudyForm = STUDY_TYPE::ST_SEMI_HIGH;
	Card(std::string const name_, std::string const lastname_, int ayear_, PAYMENT pform_);
	Card();
	//
	std::string GetInfo();
};
