// student.cpp
// Created by Jack Compton

#include <iostream>
#include <iomanip>
#include "student.h"


using namespace std;

Student::Student(	// Constructor using all input parameters  
	string studentID, 
	string firstName, 
	string lastName, 
	string email,
	int age, 
	int daysInCourse[], 
	DegreeProgram degreeProgram)
{
	setStudentId(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(email);
	setAge(age);
	setNumDays(daysInCourse);
	setDegreeProgram(degreeProgram);
}

// Getters
string Student::getStudentId() const {
	return studentID;
}

string Student::getFirstName() const {
	return firstName;
}

string Student::getLastName() const {
	return lastName;
}

string Student::getEmailAddress() const {
	return email;
}

int Student::getAge() const {
	return age;
}

int* Student::getDaysInCourse() const {
	return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}


// Setters
void Student::setStudentId(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setNumDays(int daysInCourse[]) {
	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

// Student Print All
void Student::Print() {
	int* days = getDaysInCourse();

	string degreeProgram = "NULL";
	switch (getDegreeProgram()) { // evaluates once and is compared to each enum state to select degreeProgram
	case DegreeProgram::SECURITY:
		degreeProgram = "SECURITY";
		break;
	case DegreeProgram::NETWORK:
		degreeProgram = "NETWORK";
		break;
	case DegreeProgram::SOFTWARE:
		degreeProgram = "SOFTWARE";
		break;
	}

	cout << "Student ID: " << studentID << "\t  ";
	cout << "First name: " << firstName << "\t";
	cout << "Last name: " << lastName << "\t";
	cout << "Age: " << age << "\t   ";
	cout << "Days in course: {";	

	for (int i = 0; i < 3; i++) {	// Loops through days[i] to format output
		cout << days[i];
		if (i < 2) {
			cout << ", ";
		}
	}

	cout << "}" << "\t   " << "Degree Program: " << degreeProgram << endl;
}

Student::~Student() {
	cout << "Student Destructor called" << endl;
}
