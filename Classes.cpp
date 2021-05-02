//
//  Classes.cpp
//  Class Reporting System
//
//  Created by Videsh Bridgelal on 4/21/21.
//

#include "Classes.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void Classes::PrintClass(){
    cout << CRN << '\t';
    cout << rubric << '\t' << '\t';
    cout << section << '\t';
    cout << left << setw(30);
    cout << courseName << '\t';
    cout << left << setw(20);
    cout << instructor << '\t';
    cout << left << setw(10);
    cout << days << '\t';
    cout << left << setw(17);
    cout << time << '\t';
    cout << classSeats << '\t' << endl << endl;
}

void Classes::PrintRoster(Student currStudent){
    string firstName, lastName, studentID, studentEmail;
    currStudent.GetName(firstName, lastName);
    currStudent.GetID(studentID);
    currStudent.GetEmail(studentEmail);
    cout << firstName << ' ' << lastName << '\t' << studentID << '\t' << studentEmail << endl;
    currStudent.PrintRoster();
}

void Classes::ClassAttendance(){
    Student currStudent;
    vector<int> tempAttendance;
    //FIXME: finish later
    unsigned int i;
    unsigned int j;
    
    for(i = 0; i < students.size(); ++i){
        currStudent = students.at(i);
        currStudent.GetAttendance(tempAttendance);
        for(j = 0; j < 30; ++j){
            cout << tempAttendance.at(i);
        }
    }
}

void Classes::SetInfo(string CRN, string rubric, string section, string courseName, string instructor, string days, string time, int classSeats){
    this->CRN = CRN;
    this->rubric = rubric;
    this->section = section;
    this->courseName = courseName;
    this->instructor = instructor;
    this->days = days;
    this->time = time;
    this->classSeats = classSeats;
}

void Classes::GetInfo(string& CRN, string& rubric, string& section, string& courseName, string& instructor, string& days, string& time, int& classSeats){
    CRN = this->CRN;
    rubric = this->rubric;
    section = this->section;
    courseName = this->courseName;
    instructor = this->instructor;
    days = this->days;
    time = this->time;
    classSeats = this->classSeats;
}

void Classes::CalculateAverage(){
    Student currStudent;
    vector<double> tempGrades;
    vector<double> firstGrade;
    vector<double> secondGrade;
    vector<double> thirdGrade;
    vector<double> fourthGrade;
    vector<double> finalGrade;
    double total = 0;
    double average;
    unsigned int i;
    
    for(i = 0; i < students.size(); ++i){
        currStudent = students.at(i);
        currStudent.GetGrade(tempGrades);
        
        firstGrade.push_back(tempGrades.at(0));
        secondGrade.push_back(tempGrades.at(1));
        thirdGrade.push_back(tempGrades.at(2));
        fourthGrade.push_back(tempGrades.at(3));
        finalGrade.push_back(tempGrades.at(4));
    }
    
        //Calculate firstGrade test average
    for(i = 0; i < firstGrade.size(); ++i){
        total = total + firstGrade.at(i);
    }
    average = total / firstGrade.at(i);
    averageGrades.at(0) = average;
        
    total = 0;  //Resets total
    //Calculate secondGrade test average
    for(i = 0; i < secondGrade.size(); ++i){
        total = total + secondGrade.at(i);
    }
    average = total / secondGrade.size();
    averageGrades.at(1) = average;
    
    total = 0;
    //Calculate thirdGrade test average
    for(i = 0; i < thirdGrade.size(); ++i){
        total = total + thirdGrade.at(i);
    }
    average = total / thirdGrade.size();
    averageGrades.at(2) = average;
    
    total = 0;
    //Calculate fourthGrade test average
    for(i = 0; i < fourthGrade.size(); ++i){
        total = total + fourthGrade.at(i);
    }
    average = total / fourthGrade.size();
    averageGrades.at(3) = average;
    
    total = 0;
    //Calculate finalGrade test average
    for(i = 0; i < finalGrade.size(); ++i){
        total = total + finalGrade.at(i);
    }
    average = total / finalGrade.size();
    averageGrades.at(4) = average;
}


