#include "roster.h"

void Roster::parse(string studentData) {

	int comma = studentData.find(",");
	string studentID = studentData.substr(0, comma);

	int newStartingIndex = comma + 1;
	comma = studentData.find(",", newStartingIndex);
	string firstName = studentData.substr(newStartingIndex, comma - newStartingIndex);

	newStartingIndex = comma + 1;
	comma = studentData.find(",", newStartingIndex);
	string lastName = studentData.substr(newStartingIndex, comma - newStartingIndex);

	newStartingIndex = comma + 1;
	comma = studentData.find(",", newStartingIndex);
	string email = studentData.substr(newStartingIndex, comma - newStartingIndex);

	newStartingIndex = comma + 1;
	comma = studentData.find(",", newStartingIndex);
	int age = stoi(studentData.substr(newStartingIndex, comma - newStartingIndex));

	newStartingIndex = comma + 1;
	comma = studentData.find(",", newStartingIndex);
	int daysInCourse1 = stoi(studentData.substr(newStartingIndex, comma - newStartingIndex));

	newStartingIndex = comma + 1;
	comma = studentData.find(",", newStartingIndex);
	int daysInCourse2 = stoi(studentData.substr(newStartingIndex, comma - newStartingIndex));

	newStartingIndex = comma + 1;
	comma = studentData.find(",", newStartingIndex);
	int daysInCourse3 = stoi(studentData.substr(newStartingIndex, comma - newStartingIndex));

	newStartingIndex = comma + 1;
	comma = studentData.find(",", newStartingIndex);
	string degreeProgramString = studentData.substr(newStartingIndex, comma - newStartingIndex);

	DegreeProgram degreeProgram;

	if (degreeProgramString == "SOFTWARE") degreeProgram = SOFTWARE;
	if (degreeProgramString == "SECURITY") degreeProgram = SECURITY;
	if (degreeProgramString == "NETWORK") degreeProgram = NETWORK;

	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	int daysArray[] = {daysInCourse1,
					   daysInCourse2,
					   daysInCourse3
	};

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysArray, degreeProgram);
}

void Roster::printAll() {

	Student::printHeader();

	for (int i = 0; i <= Roster::lastIndex; i++) {
		classRosterArray[i]->Student::print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	Student::printHeader();

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails() {

	bool any = false;

	for (int i = 0; i <= Roster::lastIndex; i++) {
		string email = (classRosterArray[i]->getEmail());

		if (email.find(" ") != string::npos || email.find("@") == string::npos || email.find(".") == string::npos) {
			any = true;
			cout << classRosterArray[i]->getFirstName() << ": " << classRosterArray[i]->getEmail() << std::endl;
		}
	}

	if (!any) cout << "No invalid email addresses found." << std::endl;
}

void Roster::printAverageDaysInCourse(string studentID) {

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << classRosterArray[i]->getStudentID() << ": ";
			cout << (classRosterArray[i]->getDaysToCompleteCourse()[0] +
				classRosterArray[i]->getDaysToCompleteCourse()[1] +
				classRosterArray[i]->getDaysToCompleteCourse()[2]) / 3.0 << std::endl;
		}
	}

	cout << std::endl;
}

void Roster::remove(string studentID) {

	bool success = false;

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			success = true;
			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success) {
		cout << "Student ID: " << studentID << " was removed from the roster." << std::endl << std::endl;
		this->printAll();
	}
	else cout << "Student ID: " << studentID << " was not found." << std::endl << std::endl;
}

Roster::~Roster() {

	cout << "Roster destructor called." << std::endl << std::endl;

	for (int i = 0; i < numStudents; i++) {
		cout << "Destroying student A" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
