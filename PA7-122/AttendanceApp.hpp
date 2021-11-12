#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "List.hpp"
#include "Node.hpp"
#include "Stack.hpp"
#include "Data.hpp"
#include "menu.hpp"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::vector;
using std::string;

class AttendanceApp
{
public:
	AttendanceApp();
	~AttendanceApp();

	void runApp();

	void importList();

	void loadMaster();

	void storeMaster();

	void markAbsences();

	void editAbsences();

	void generateReports(int choice);

private:
	List<Data> mMasterList;
	fstream classImport;
	fstream masterListStorage;
};

