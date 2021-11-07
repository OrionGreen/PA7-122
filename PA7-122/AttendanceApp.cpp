#include "AttendanceApp.hpp"

AttendanceApp::AttendanceApp() {
	this->classImport.open("classList.csv", std::ios::in);
	this->masterListStorage.open("master.txt", std::ios::in);
}
AttendanceApp::~AttendanceApp() {
	this->classImport.close();
	this->masterListStorage.close();
}

void AttendanceApp::runApp() {

}

void AttendanceApp::importList() {
	if(!classImport.is_open()){
		this->classImport.open("classList.csv", std::ios::in);
	}
	string line;
	getline(this->classImport, line);
	while (getline(this->classImport, line, ',')) {
		int recordNum = atoi(line.c_str());
		getline(this->classImport, line, ',');
		int ID = atoi(line.c_str());
		getline(this->classImport, line, ',');
		string name = line;
		getline(this->classImport, line, ',');
		name += ',';
		name += line;
		getline(this->classImport, line, ',');
		string email = line;
		getline(this->classImport, line, ',');
		string credits = line;
		getline(this->classImport, line, ',');
		string major = line;
		getline(this->classImport, line, '\n');
		string level = line;

		Stack<string> empty;
		Data* newData = new Data(empty, 0, recordNum, ID, name, email, credits, major, level);
		mMasterList.insert(*newData);
	}
}

void AttendanceApp::loadMaster() {
	if (!masterListStorage.is_open()) {
		this->masterListStorage.open("master.txt", std::ios::in);
	}
	string line;
	while (getline(this->masterListStorage, line)) {
		int recordNum = atoi(line.c_str());
		getline(this->masterListStorage, line);
		int ID = atoi(line.c_str());
		getline(this->masterListStorage, line);
		int absences = atoi(line.c_str());
		getline(this->masterListStorage, line);
		string name = line;
		getline(this->masterListStorage, line);
		string email = line;
		getline(this->masterListStorage, line);
		string credits = line;
		getline(this->masterListStorage, line);
		string major = line;
		getline(this->masterListStorage, line);
		string level = line;
		
		string date = " ";
		Stack<string> invert;
		Stack<string> insert;
		getline(this->masterListStorage, line);

		//figuring out how to effectively store and recall this stack stuff
		if (line == "NoAbsence\n") {

		}
		else {
			
			while (date.c_str() != '\0') {

			}
		}

		Data* newData = new Data(insert, absences, recordNum, ID, name, email, credits, major, level);
		mMasterList.insert(*newData);
	}
}

void AttendanceApp::storeMaster() {
	masterListStorage.close();
	if (!masterListStorage.is_open()) {
		this->masterListStorage.open("master.txt", std::ios::out);
	}
	Node<Data>* pMem = mMasterList.getmpHead();
	int listSize = 1;
	while (pMem != nullptr) {
		listSize += 1;
		pMem = pMem->getpNext();
	}
	
	for (int i = 1; i < listSize; i++) {
		pMem = mMasterList.getmpHead();
		while (pMem->getData().getRecordNum() != i) {
			pMem = pMem->getpNext();
		}
		masterListStorage << pMem->getData().getRecordNum() << endl;
		masterListStorage << pMem->getData().getIDNum() << endl;
		masterListStorage << pMem->getData().getAbsenceNum() << endl;
		masterListStorage << pMem->getData().getName() << endl;
		masterListStorage << pMem->getData().getEmail() << endl;
		masterListStorage << pMem->getData().getCredits() << endl;
		masterListStorage << pMem->getData().getMajor() << endl;
		masterListStorage << pMem->getData().getLevel() << endl;
		if (!pMem->getData().getAbsenceDates().isEmpty()) {
			while (!pMem->getData().getAbsenceDates().isEmpty()) {
				masterListStorage << pMem->getData().getAbsenceDates().peek() << ",";
				pMem->getData().getAbsenceDates().pop();
			}
			masterListStorage << endl;
		}
		else {
			masterListStorage << "NoAbsence" << endl;
		}
	}

	masterListStorage.close();
	if (!masterListStorage.is_open()) {
		this->masterListStorage.open("master.txt", std::ios::in);
	}
}

void AttendanceApp::markAbsences() {

}

void AttendanceApp::editAbsences() {

}

void AttendanceApp::generateReports() {

}