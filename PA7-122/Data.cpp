#include "Data.hpp"

Data::Data(Stack<string> newAbsenceDates, int newAbsenceNum, int newRecordNum, int newIDNum, string newName,
	string newEmail, string newCredits, string newMajor, string newLevel) {
	this->mAbsenceDates = newAbsenceDates;
	this->mAbsenceNum = newAbsenceNum;
	this->mRecordNum = newRecordNum;
	this->mIDNum = newIDNum;
	this->mName = newName;
	this->mEmail = newEmail;
	this->mCredits = newCredits;
	this->mMajor = newMajor;
	this->mLevel = newLevel;
}

Data::~Data() {
	mAbsenceDates.~Stack();
}


Data& Data::operator= (const Data& rhs) {
	this->mAbsenceNum = rhs.getAbsenceNum();
	this->mRecordNum = rhs.getRecordNum();
	this->mIDNum = rhs.getIDNum();
	this->mName = rhs.getName();
	this->mEmail = rhs.getEmail();
	this->mCredits = rhs.getCredits();
	this->mMajor = rhs.getMajor();
	this->mLevel = rhs.getLevel();

	//deep copy stack implemented in Stack Template
	this->mAbsenceDates = rhs.getAbsenceDates();

	return *this;
}

//setters
void Data::getAbsenceDates(Stack<string> const newAbsenceDates) {
	this->mAbsenceDates = newAbsenceDates;
}
void Data::setAbsenceNum(int const newAbsences) {
	this->mAbsenceNum = newAbsences;
}
void Data::setRecordNum(int const newRecordNum) {
	this->mRecordNum = newRecordNum;
}
void Data::setIDNum(int const newIDNum) {
	this->mIDNum = newIDNum;
}
void Data::setName(string const newName) {
	this->mName = newName;
}
void Data::setEmail(string const newEmail) {
	this->mEmail = newEmail;
}
void Data::setCredits(string const newCredits) {
	this->mCredits = newCredits;
}
void Data::setMajor(string const newMajor) {
	this->mMajor = newMajor;
}
void Data::setLevel(string const newLevel) {
	this->mLevel = newLevel;
}

//getters
Stack<string> Data::getAbsenceDates() const {
	return this->mAbsenceDates;
}
int Data::getAbsenceNum()	const {
	return this->mAbsenceNum;
}
int Data::getRecordNum() const {
	return this->mRecordNum;
}
int Data::getIDNum() const {
	return this->mIDNum;
}
string Data::getName() const {
	return this->mName;
}
string Data::getEmail() const {
	return this->mEmail;
}
string Data::getCredits() const {
	return this->mCredits;
}
string Data::getMajor() const {
	return this->mMajor;
}
string Data::getLevel() const {
	return this->mLevel;
}