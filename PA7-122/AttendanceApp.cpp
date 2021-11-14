#include "AttendanceApp.hpp"

//opens the fstreams and closes when the wrapper is destroyed
AttendanceApp::AttendanceApp() {
	this->classImport.open("classList.csv", std::ios::in);
	this->masterListStorage.open("master.txt", std::ios::in);
}
AttendanceApp::~AttendanceApp() {
	this->classImport.close();
	this->masterListStorage.close();
}

//app runs from menu
void AttendanceApp::runApp() {
	Menu menu;
	int exit = 0;
	while (exit != 1) {
	int choice = menu.displayMenu();
	if (choice == 1) {
		importList();
	}

	if (choice == 2) {
		loadMaster();
	}

	if (choice == 3) {
		storeMaster();
	}

	if (choice == 4) {
		markAbsences();
	}

	if (choice == 5) {
		editAbsences();
		Sleep(4000);
	}

	if (choice == 6) {
		int subchoice = menu.displaySubMenu();
		generateReports(subchoice);
		Sleep(4000);
	}

	if (choice == 7) {
		storeMaster();
		exit = 1;
	}
	system("cls");
}
}

//imports from the csv which wipes the absences clean
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
		char comma = '\0';
		this->classImport.get(comma);
		getline(this->classImport, line, ',');
		string name = line;
		getline(this->classImport, line, '"');
		name += ',';
		name += line;
		this->classImport.get(comma);
		getline(this->classImport, line, ',');
		string email = line;
		getline(this->classImport, line, ',');
		string credits = line;
		getline(this->classImport, line, ',');
		string major = line;
		getline(this->classImport, line, '\n');
		string level = line;

		Stack<string>* empty = new Stack<string>();
		Data* newData = new Data(empty, 0, recordNum, ID, name, email, credits, major, level);
		mMasterList.insert(newData);
	}
}

//loads only from the master save doc
void AttendanceApp::loadMaster() {
	if (!masterListStorage.is_open()) {
		this->masterListStorage.open("master.txt", std::ios::in);
	}
	string line;
	mMasterList.~List();
	mMasterList.setmpHead(nullptr);

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
		
		Stack<string>* invert = new Stack<string>();
		Stack<string>* insert = new Stack<string>();
		getline(this->masterListStorage, line);

		//figuring out how to effectively store and recall this stack stuff
		if (line == "NoAbsence") {

		}
		else {
			char dates[100] = "";
			strcpy(dates,line.c_str());
			char date[100] = "";
			
			strcpy(date, strtok(dates, ","));

			int numDates = atoi(date);
			for (int i = 0; i < numDates; i++) {
				strcpy(date, strtok(NULL, ","));
				invert->push(date);
				
			}

			while (!invert->isEmpty()) {
				insert->push(invert->peek());
				invert->pop();
			}
		}
		
		Data* newData = new Data(insert, absences, recordNum, ID, name, email, credits, major, level);
		mMasterList.insert(newData);
	}
}

//stores to the master save doc stores in the smae order every time so it's less efficient but I didn't want my list flipping on my every time I store and load,
//I think attendance should be in a predictable order every time so I traded efficiency for usabillity
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
		while (pMem->getData()->getRecordNum() != i) {
			pMem = pMem->getpNext();
		}
		masterListStorage << pMem->getData()->getRecordNum() << endl;
		masterListStorage << pMem->getData()->getIDNum() << endl;
		masterListStorage << pMem->getData()->getAbsenceNum() << endl;
		masterListStorage << pMem->getData()->getName() << endl;
		masterListStorage << pMem->getData()->getEmail() << endl;
		masterListStorage << pMem->getData()->getCredits() << endl;
		masterListStorage << pMem->getData()->getMajor() << endl;
		masterListStorage << pMem->getData()->getLevel() << endl;
		if (!pMem->getData()->getAbsenceDates()->isEmpty()) {
			Stack<string> invert;
			masterListStorage << pMem->getData()->getAbsenceNum() << ",";
			while (!pMem->getData()->getAbsenceDates()->isEmpty()) {
				masterListStorage << pMem->getData()->getAbsenceDates()->peek() << ",";
				invert.push(pMem->getData()->getAbsenceDates()->peek());
				pMem->getData()->getAbsenceDates()->pop();
			}
			while (!invert.isEmpty()) {
				pMem->getData()->getAbsenceDates()->push(invert.peek());
				invert.pop();
			}
			invert.~Stack();
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

//marks absences iterating through the list
void AttendanceApp::markAbsences() {
	Node<Data>* pMem = mMasterList.getmpHead();
	string date = "";

	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	int year = (now->tm_year + 1900);
	int month = (now->tm_mon + 1);
	int day = (now->tm_mday);

	date = std::to_string(month) + '/' + std::to_string(day) + '/' + std::to_string(year);

	if (pMem != nullptr) {
		while (pMem != nullptr) {
			char choice = '\0';
			cout << "Was " << pMem->getData()->getName() << " absent today? y or n" << endl;
			while (choice != 'y' && choice != 'n') {
				cin >> choice;
			}

			if (choice == 'y') {
				pMem->getData()->setAbsenceNum(pMem->getData()->getAbsenceNum() + 1);
				pMem->getData()->getAbsenceDates()->push(date);
			}
			

			pMem = pMem->getpNext();
		}
	}
}

//lets you get rid of an absence
void AttendanceApp::editAbsences() {
	cout << "Please either enter a student name or Id number to edit the absences of. Id numbers consits of 4 digits and student names are formatted Last,First" << endl;
	string search = "";
	cin >> search;

	Node<Data>* pMem = mMasterList.getmpHead();

	if (pMem != nullptr) {
		while (pMem != nullptr) {
			if (search == pMem->getData()->getName() || search == std::to_string(pMem->getData()->getIDNum())) {
				cout << "Here is the record of " << pMem->getData()->getName() << " ID Number: " << pMem->getData()->getIDNum() << endl;
				if (!pMem->getData()->getAbsenceDates()->isEmpty()) {
					Stack<string> invert;
					cout << "Absences on record:" << endl;
					while (!pMem->getData()->getAbsenceDates()->isEmpty()) {
						cout << pMem->getData()->getAbsenceDates()->peek() << endl;
						invert.push(pMem->getData()->getAbsenceDates()->peek());
						pMem->getData()->getAbsenceDates()->pop();
					}

					cout << "Which absence should be deleted?" << endl;
					string delab = "";
					cin >> delab;
					while (!invert.isEmpty()) {
						if (invert.peek() == delab) {
							pMem->getData()->setAbsenceNum(pMem->getData()->getAbsenceNum() - 1);
							invert.pop();
							cout << "Absence Successfully Deleted" << endl;

						}
						else {
							pMem->getData()->getAbsenceDates()->push(invert.peek());
							invert.pop();
						}
					}

				}
				else {
					cout << "Student: " << pMem->getData()->getName() << " Doesn't have and absences to ammend." << endl;
				}
			}

			pMem = pMem->getpNext();
		}
	}
}

//generates two different types of reports on absences.
void AttendanceApp::generateReports(int choice) {
	Node<Data>* pMem = mMasterList.getmpHead();

	if (choice == 1 && pMem != nullptr) {
		cout << "Students and their last absences." << endl;
		while (pMem != nullptr) {
			cout << "Student: " << pMem->getData()->getName() << " Date: ";
			if (!pMem->getData()->getAbsenceDates()->isEmpty()) {
				cout << pMem->getData()->getAbsenceDates()->peek() << endl;
			}
			else {
				cout << "No Absences!" << endl;
			}
			pMem = pMem->getpNext();
		}

	}
	else if(choice == 2 && pMem != nullptr) {
		int abNum = 0;
		cout << "How many absences would you like to sort by?" << endl;
		cin >> abNum;
		while (pMem != nullptr) {
			if (pMem->getData()->getAbsenceNum() >= abNum) {
				cout << "Student: " << pMem->getData()->getName() << " Number of Absences: " << pMem->getData()->getAbsenceNum() << endl;
			}
			pMem = pMem->getpNext();
		}
	}
}