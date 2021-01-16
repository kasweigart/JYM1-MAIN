#include "roster.h"

int main() {

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Kyle,Sweigart,ksweiga@wgu.edu,23,10,20,30,SOFTWARE"
	};

	const int numStudents = 5;

	Roster classRoster;

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Scripting and Programming - Applications -- C867, C++, 001521520, Kyle Sweigart" << std::endl << std::endl;
	classRoster.printAll();
	cout << std::endl;

	cout << "Displaying students with invalid email addresses: " << std::endl;
	classRoster.printInvalidEmails();
	cout << std::endl;

	cout << "Displaying average days to complete course for student: A1" << std::endl;
	classRoster.printAverageDaysInCourse("A1");

	
	cout << "Displaying by degree program: SOFTWARE" << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	

	classRoster.remove("A3");
	cout << std::endl;
	classRoster.remove("A3");

	classRoster.~Roster();

	system("pause");
	return 0;
}