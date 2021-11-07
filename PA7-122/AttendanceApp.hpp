#pragma once
#include "List.hpp"
#include "Node.hpp"
#include "Stack.hpp"
#include "Data.hpp"
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

	void generateReports();

private:
	List<Data> mMasterList;
	fstream classImport;
	fstream masterListStorage;
};

