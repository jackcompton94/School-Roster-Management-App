// roster.h
// Created by Jack Compton

#pragma once

#include <string>
#include "degree.h"
#include "student.h"

using namespace std;
static int arrayI = 0;

class Roster {
private:
	

public:
	Student* classRosterArray[5]{ NULL };

	void Parse(string data);
	void Add(string studentID, string firstName, string lastName, string email, int age, int course1, int course2, int course3, DegreeProgram degreeProgram);
	void Remove(string studentID);
	void PrintAll();
	void PrintAvgDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);

	~Roster(); // Roster Destructor
};