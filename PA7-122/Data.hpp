#pragma once
#include "Stack.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::vector;
using std::string;


class Data
{
public:

	Data(Stack<string>* newAbsenceDates = {}, int newAbsenceNum = 0, int newRecordNum = 0, int newIDNum = 0, string newName = "",
		string newEmail = "", string newCredits = "", string newMajor = "", string newLevel = "");

	~Data();

	Data& operator= (const Data& rhs);

	//setters
	void getAbsenceDates(Stack<string>* const newAbsenceDates);
	void setAbsenceNum(int const newAbsences);
	void setRecordNum(int const newRecordNum);
	void setIDNum(int const newIDNum);
	void setName(string const newName);
	void setEmail(string const newEmail);
	void setCredits(string const newCredits);
	void setMajor(string const newMajor);
	void setLevel(string const newLevel);

	//getters
	Stack<string>* getAbsenceDates() const;
	int getAbsenceNum()	const;
	int getRecordNum() const;
	int getIDNum() const;
	string getName() const;
	string getEmail() const;
	string getCredits() const;
	string getMajor() const;
	string getLevel() const;

private:
	Stack<string>* mAbsenceDates;
	int mAbsenceNum;
	int mRecordNum;
	int mIDNum;
	string mName;
	string mEmail;
	string mCredits;
	string mMajor;
	string mLevel;

};

