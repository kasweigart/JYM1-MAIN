#pragma once
#include "degree.h"
#include <iomanip>
#include <iostream>

using std::cout;
using std::string;


class Student {


public:
	const static int daysSize = 3;


public:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToCompleteCourse[daysSize];
	DegreeProgram degreeProgram;


public:
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();

	void setStudentID(string studentID);
	void setFirstname(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToCompleteCourse(int daysToCompleteCourse[]);
	void setDegreeProgram(DegreeProgram degrProg);

	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int daysToCompleteProgram[], DegreeProgram degreeProgram);
	~Student();

	static void printHeader();

	void print();
};

