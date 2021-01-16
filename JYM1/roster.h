#pragma once
#include "student.h"

class Roster {
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string row);

	void add(string sID, string fName, string lName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	void printAll();

	void printByDegreeProgram(DegreeProgram degreeProgram);

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();
	
	void remove(string studentID);

	~Roster();
};