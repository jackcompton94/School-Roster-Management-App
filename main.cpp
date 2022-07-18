// main.cpp
// C867 Task by Jack Compton

#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jack,Compton,jackcompton94@gmail.com,27,10,20,30,SOFTWARE"
};

int main() {
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #001511804" << endl;
	cout << "Name: Jack Compton" << endl;

	Roster classRoster;

	for (int i = 0; i < 5; i++) {
		classRoster.Parse(studentData[i]);	// Read from studentData[] and add to classRoster
	}
	
	cout << "classRoster.printAll();" << endl << endl;
	classRoster.PrintAll();


	cout << "classRoster.printInvalidEmails(); " << endl << endl;
	classRoster.PrintInvalidEmails();


	cout << "classRoster.printAverageDaysInCourse(); " << endl << endl;
	for (int i = 0; i < 5; i++) {
		classRoster.PrintAvgDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
	}


	cout << "classRoster.printByDegreeProgram(SOFTWARE);" << endl << endl;
	classRoster.PrintByDegreeProgram(DegreeProgram::SOFTWARE);


	cout << "classRoster.remove(\"A3\");" << endl << endl;
	classRoster.Remove("A3");


	cout << "classRoster.printAll();" << endl << endl;
	classRoster.PrintAll();


	cout << "classRoster.Remove(\"A3\");" << endl << endl;
	classRoster.Remove("A3");

	return 0;
}