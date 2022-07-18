// roster.cpp
// Created by Jack Compton

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "roster.h"
#include "degree.h"
#include "student.h"


using namespace std;

void Roster::Parse(string data) {
	vector<string> dataValues;
	DegreeProgram exampleDegree;

	for (int i = 0; i < 5; i++) {
		stringstream ss(data);

		while (ss.good()) {
			string subStr;
			getline(ss, subStr, ',');
			dataValues.push_back(subStr);	// Reads from hardcoded string to create vector of dataValues
		}

		if (dataValues[8] == "SECURITY") {
			exampleDegree = DegreeProgram::SECURITY;
		}
		else if (dataValues[8] == "NETWORK") {
			exampleDegree = DegreeProgram::NETWORK;
		}
		else if (dataValues[8] == "SOFTWARE") {
			exampleDegree = DegreeProgram::SOFTWARE;
		}
	}

	// Sending parsed studentData to Add
	Roster::Add(
		dataValues.at(0),
		dataValues.at(1),
		dataValues.at(2),
		dataValues.at(3),

		stoi(dataValues.at(4)),
		stoi(dataValues.at(5)),
		stoi(dataValues.at(6)),
		stoi(dataValues.at(7)),
		exampleDegree);
}

void Roster::Add
   (string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	int course1, int course2, int course3,
	DegreeProgram degreeProgram) 
{
	int daysInCourse[] = { course1, course2, course3 };
	
	// Sends to classRosterArray via new Student constructor 
	classRosterArray[arrayI++] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
}


void Roster::Remove(string studentID) {
	cout << "Removing student: " << studentID;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == NULL) {
			cout << endl << "Student does not exist" << endl;
			break;
		}

		if (classRosterArray[i]->getStudentId() == studentID) {		// Finds requested studentID
			classRosterArray[i] = NULL;								// Removes that studentID
			cout << endl << "Student succesfully removed" << endl;
		}
	}
}

// Print all students currently in Roster
void Roster::PrintAll() {

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			classRosterArray[i]->Print();
		}
	}
}


void Roster::PrintAvgDaysInCourse(string studentID) {

	for (int i = 0; i < 5; i++) {
		if (studentID == classRosterArray[i]->getStudentId()) {				// Match studentID

			int* days = classRosterArray[i]->getDaysInCourse();				// Points to each day
			int avgDays = (days[0] + days[1] + days[2]) / 3;				// Compute average

			cout << studentID << ": average days in a course: " << avgDays << endl;
		}
	}
}


void Roster::PrintInvalidEmails() {
	string email = "";

	for (int i = 0; i < 5; i++) {
		bool at = false;
		bool period = false;
		bool space = false;
		
		email = classRosterArray[i]->getEmailAddress();

		for (char& character : email) {
			if (character == '@') {
				at = true;
			}

			if (character == '.') {
				period = true;
			}

			if (character == ' ') {
				space = true;
			}
		}

		// Filters out any invalid emails to output
		if (at == false || period == false || space == true) {
			cout << classRosterArray[i]->getEmailAddress() << endl;
		}
	}
}


void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {

			if (degreeProgram == classRosterArray[i]->getDegreeProgram()) {
				classRosterArray[i]->Print();
			}
		}
	}
}


Roster::~Roster() {
	cout << "Roster Destructor Called" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Destroyed StudentID: A" << i + 1 << endl;
		classRosterArray[i] = NULL;
	}
}