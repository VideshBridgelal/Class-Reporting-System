//
//  Student.hpp
//  Class Reporting System
//
//  Created by Videsh Bridgelal on 4/21/21.
//

#ifndef Student_h
#define Student_h

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Student{
public:
    void SetName(string firstName, string lastName){
        this->firstName = firstName;
        this->lastName = lastName;
    }
    void GetName(string& first, string& last){
        first = firstName;
        last = lastName;
    }
    void SetGrade(vector<double> grades){
        this->grades = grades;
    }
    void GetGrade(vector<double>& grades){
        grades = this->grades;
    }
    void SetAverage(double average){
        grades.push_back(average);
    }
    void SetID(string studentID){
        this->studentID = studentID;
    }
    void GetID(string& studentID){
        studentID = this->studentID;
    }
    void SetEmail(string studentEmail){
        this->studentEmail = studentEmail;
    }
    void GetEmail(string& studentEmail){
        studentEmail = this->studentEmail;
    }
    void SetAttendance(vector<int> userAttendance){
        attendance = userAttendance;
    }
    void GetAttendance(vector<int>& userAttendance){
        userAttendance = attendance;
    }
    void SetClasses(string studentClasses){
        this->studentClasses = studentClasses;
    }
    void GetClasses(string& studentClasses){
        studentClasses = this->studentClasses;
    }
    double CalculateAverage();
    void StudentAverage(double average);
    void PrintGradeReport();
    void PrintRoster();
    
private:
    string firstName;
    string lastName;
    string studentID;
    string studentEmail;
    string studentClasses;
    vector<double> grades;
    vector<int>    attendance;
    vector<string> classes;
};

#endif /* Student_hpp */
