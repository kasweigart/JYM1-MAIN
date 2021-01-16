#include "student.h"

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysSize; i++) this->daysToCompleteCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
}



Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysSize; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	this->degreeProgram = degreeProgram;
}



Student::~Student() {

}



string Student::getStudentID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDaysToCompleteCourse() {
	return this->daysToCompleteCourse;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}



void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstname(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToCompleteCourse(int daysToCompleteCourse[]) {
	for (int i = 0; i < daysSize; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
}
 
void Student::setDegreeProgram(DegreeProgram degrProg) {
	this->degreeProgram = degrProg;
}

void Student::printHeader() {
	cout << "Student ID|First Name|Last Name|Email Address|Age|Days in Course|Degree Program" << std::endl;
}

void Student::print() {
	cout << this->getStudentID() << "\t";
	cout << this->getFirstName() << "\t";
	cout << this->getLastName() << "\t";
	cout << this->getEmail() << "\t";
	cout << this->getAge() << "\t";
	cout << this->getDaysToCompleteCourse()[0] << "\t";
	cout << this->getDaysToCompleteCourse()[1] << "\t";
	cout << this->getDaysToCompleteCourse()[2] << "\t";
	cout << DegreeProgramStrings[this->getDegreeProgram()] << "\n";
}
