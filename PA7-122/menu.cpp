#include "menu.hpp"

Menu::Menu() {

}

Menu::~Menu() {

}

int Menu::displayMenu() {
	int choice = 0;
	cout << "What would you like to do?" << endl << "1. Import List" << endl << "2. Load List" << endl << "3. Store List" << endl << "4. Mark Absences" << endl << "5. Edit Absences" << endl << "6. Generate Reports" << endl << "7. Exit" << endl;

	while (choice < 1 || choice > 7) {
		cin >> choice;
	}
	return choice;
}

int Menu::displaySubMenu() {
	int choice = 0;
	cout << "What report would you like?" << endl;
	cout << "1. Report of last known absence of all students" << endl;
	cout << "2. Report for students with absences that match or exceed a defined number" << endl;

	while (choice < 1 || choice > 2) {
		cin >> choice;
	}
	return choice;
}
