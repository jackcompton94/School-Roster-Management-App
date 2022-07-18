// student.h
// Created by Jack Compton

#pragma once

#include <string>
#include "degree.h"


using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* daysInCourse;
	DegreeProgram degreeProgram;

public:
	Student(	// Constructor using all input parameters 
		string studentID, 
		string firstName, 
		string lastName, 
		string email,
		int age, 
		int daysInCourse[], 
		DegreeProgram degreeProgram);

	void setStudentId(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string email);
	void setAge(int age);
	void setNumDays(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	string getStudentId() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getDaysInCourse() const;
	DegreeProgram getDegreeProgram();
	
	void Print();

	~Student(); // Student Destructor
};