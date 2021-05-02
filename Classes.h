//
//  Classes.hpp
//  Class Reporting System
//
//  Created by Videsh Bridgelal on 4/21/21.
//

#ifndef Classes_h
#define Classes_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Student.h"

using namespace std;

class Classes{
public:
    void PrintClass();
    void PrintRoster(Student currStudent);
    void ClassAttendance();
    void SetInfo(string CRN, string rubric, string section, string courseName, string instructor, string days, string time, int classSeats);
    void GetInfo(string& CRN, string& rubric, string& section, string& courseName, string& instructor, string& days, string& time, int& classSeats);
    void SetStudents(vector<Student>& tempStudents){
        tempStudents = students;
    }
    void FillStudentsVector(Student newStudent){
        students.push_back(newStudent);
    }
    void CalculateAverage();
    string GetCourseName(){
        return courseName;
    }
    
    void TestStudents(){
        Student currStudent;
        string firstName, lastName;
        
        for(int i = 0; i < students.size(); ++i){
            currStudent = students.at(i);
            currStudent.PrintRoster();
            //cout << firstName << ' ' << lastName;
        }
        
    }

private:
    Student student;
    vector<Student> students;
    vector<double> averageGrades;
    string  CRN;
    int  classSeats;
    string  rubric;
    string  section;
    string  courseName;
    string  instructor;
    string  days;
    string  time;
};
#endif /* Classes_hpp */
