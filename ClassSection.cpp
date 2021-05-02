//
//  ClassSection.cpp
//  Class Reporting System
//
//  Created by Videsh Bridgelal on 4/21/21.
//

#include "ClassSection.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

/*vector<double> firstGrades, vector<double> secondGrades, vector<double> thirdGrades, vector<double> fourthGrades, vector<double> finalGrades*/

void ClassSection::ReadStudentFile(){
    Student currStudent;
    Classes currClass;
    
    vector<double> tempGrades(6);
    vector<int>    tempAttendance;
    double firstTest, secondTest, thirdTest, fourthTest, finalTest;
    //int    attendance;
    string firstName, lastName, tempID, tempEmail, tempClasses;
    
    ifstream studentFile;
    studentFile.open("StudentInfo.txt");
    
    if(studentFile.is_open()){
        while(!(studentFile.eof())){
            studentFile >> firstName;
            studentFile >> lastName;
            
            studentFile >> firstTest >> secondTest >> thirdTest >> fourthTest >> finalTest;
            
            firstGrades.push_back(firstTest);
            secondGrades.push_back(secondTest);
            thirdGrades.push_back(thirdTest);
            fourthGrades.push_back(fourthTest);
            finalGrades.push_back(finalTest);
            
            tempGrades.at(0) = firstTest;
            tempGrades.at(1) = secondTest;
            tempGrades.at(2) = thirdTest;
            tempGrades.at(3) = fourthTest;
            tempGrades.at(4) = finalTest;
            
            //FIXME: Implement attendance after
//            for(int i = 0; i < 30; ++i){
//                studentFile >> attendance;
//                tempAttendance.at(i) = attendance;
//            }
            
            studentFile >> tempID;
            studentFile >> tempEmail;
            
            studentFile.ignore();
            getline(studentFile, tempClasses);
            
            currStudent.SetName(firstName, lastName);
            currStudent.SetGrade(tempGrades);
            currStudent.SetAttendance(tempAttendance);
            currStudent.SetID(tempID);
            currStudent.SetEmail(tempEmail);
            currStudent.SetClasses(tempClasses);
            
            studentInfo.push_back(currStudent);
        }
    }
    else{
        cout << "Function ReadStudentFile: File not open" << endl;
    }
    studentFile.close();
}

void ClassSection::ReadClassFile(){
    Classes currClass;
    string CRN, rubric, section, courseName, instructor, days, time;
    int classSeats;
    
    ifstream classFile;
    classFile.open("ClassOfferingsInfo.txt");
    
    if(classFile.is_open()){
        while(!(classFile.eof())){
            classFile >> CRN;
            classFile >> rubric;
            classFile >> section;
            classFile >> courseName;
            classFile >> instructor;
            classFile >> days;
            classFile >> time;
            classFile >> classSeats;
            
            currClass.SetInfo(CRN, rubric, section, courseName, instructor, days, time, classSeats);
            
            classInfo.push_back(currClass);
        }
        
    }
    else{
        cout << "Function ReadClassFile: File not open" << endl;
    }
    classFile.close();
}

void ClassSection::GradeReport(string fileName, int classNum){
    Classes currClass = classInfo.at(classNum); //Used to call each student in vector
    Student currStudent;
    
    vector<Student> tempStudents;
    vector<double> tempGrades;
    string firstName, lastName, courseName, studentCourses;

    double average;
    unsigned int i = 0;
    unsigned int j = 0;
    
//    currClass.CalculateAverage();
//    currClass.StudentAverage();
//    currClass.SetStudents(tempStudents);
    courseName = currClass.GetCourseName();
    
    //Create Grade report text file
    ofstream outFile;
    outFile.open(fileName);
    
    //outFile << "Student\tFirst Test\tSecond Test\tThird Test\tFourth Test\tFinal Test\tAverage";
    outFile << left << setw(25);
    outFile << "Student\t";
    outFile << left << setw(40);
    outFile << "First Test\tSecond Test\tThird Test\tFourth Test\tFinal Test\tAverage" << endl;
    
    
    cout << left << setw(17);
    cout << "Student \t";
    cout << left << setw(40);
    cout << "First Test\tSecond Test\tThird Test\tFourth Test\tFinal Test\tAverage" << endl;

    
    for(i = 0; i < studentInfo.size(); ++i){
        currStudent = studentInfo.at(i);   //Calls current student
        currStudent.GetClasses(studentCourses);
        
        if(studentCourses.find(courseName) != string::npos){
            currStudent.GetName(firstName, lastName);
            currStudent.GetGrade(tempGrades);
            average = currStudent.CalculateAverage();
            //currStudent.PrintGradeReport();     //Prints to console
            
            //outFile << firstName << ' ' << lastName << '\t';
            outFile << setw(7) << left;
            outFile << firstName << '\t';
            outFile << left << setw(11);
            outFile << lastName << '\t';
            
            cout << left << setw(7);
            cout << firstName << '\t';
            cout << left << setw(11);
            cout << lastName << '\t';
            //cout << left << setw(8) << '\t';
            for(j = 0; j < 5; ++j){
                outFile << setw(10) << left;
                outFile << fixed << setprecision(2);
                outFile << tempGrades.at(j) << '\t';
                
                cout << left << setw(10);
                cout << fixed << setprecision(2);
                cout << tempGrades.at(j) << '\t';
            }
            if(average > 89){
                outFile << 'A' << endl;
                cout << 'A' << endl;
            }
            else if(average > 79){
                outFile << 'B' << endl;
                cout << 'B' << endl;
            }
            else if(average > 69){
                outFile << 'C' << endl;
                cout << 'C' << endl;
            }
            else if(average > 59){
                outFile << 'D' << endl;
                cout << 'D' << endl;
            }
            else {
                outFile << 'F' << endl;
                cout << 'F' << endl;
            }
        }
    }
    cout << endl;
    outFile.close();
}

void ClassSection::ClassOfferingsReport(){      //Working
    unsigned int i;
    Classes currClass;
    string CRN, rubric, section, courseName, instructor, days, time;
    int classSeats = 0;
    ofstream outFile;
    outFile.open("ClassOfferingsReport.txt");

    if(!(outFile.is_open())){ cout << "ClassOfferingsReport not open" << endl;}
    //Output to file
    outFile << "CRN: \tRubric: \tSection: \t";
    outFile << left << setw(30);
    outFile << "Course Name: \t";
    outFile << left << setw(20);
    outFile << " Instructor:" << '\t';
    outFile << left << setw(10);
    outFile << "Days:" << '\t';
    outFile << left << setw(17);
    outFile << "Time: " << '\t' << "ClassSeats:" << endl;
    
    //Output to program
    cout << "CRN: \tRubric: \tSection: \t";
    cout << left << setw(30);
    cout << "Course Name: \t";
    cout << left << setw(20);
    cout << "Instructor:" << '\t';
    cout << left << setw(10);
    cout << "Days:" << '\t';
    cout << left << setw(17);
    cout << "Time: " << '\t' << "ClassSeats:" << endl;

    for(i = 0; i < classInfo.size(); ++i){
        currClass = classInfo.at(i);    //Calls class
        currClass.PrintClass();         //Prints class info to console
        
        //Print all class info to file
        currClass.GetInfo(CRN, rubric, section, courseName, instructor, days, time, classSeats);
        
        outFile << CRN << '\t';
        outFile << rubric << '\t';
        outFile << section << '\t' << '\t';
        outFile << left << setw(30);
        outFile << courseName << '\t';
        outFile << left << setw(20);
        outFile << instructor << '\t';
        outFile << left << setw(10);
        outFile << days << '\t';
        outFile << left << setw(17);
        outFile << time << '\t';
        outFile << classSeats << '\t' << endl << endl;
    }
    outFile.close();
}

void ClassSection::ClassRosterReport(string fileName, int classNum){   //Working
    
    unsigned int i;
    Classes currClass = classInfo.at(classNum); //Calls the class selected in main()
    Student currStudent;
    string firstName, lastName, studentID, studentEmail, courseName, studentCourse;
    
    courseName = currClass.GetCourseName();
    
    ofstream outFile;
    outFile.open(fileName); //Opens file chosen in main()
    
    //Output header to file
    outFile << "Roster:" << endl << endl;
    outFile << left << setw(10);
    outFile << "Name:\t\t\t";
    outFile << left << setw(10);
    outFile << "StudentID:\t\tEmail:" << endl;
    
    //Output header to program
    cout << courseName << endl;
    cout << left << setw(10);
    cout << "Name:\t\t\t\t";
    cout << left << setw(10);
    cout << "StudentID:\t\tEmail:" << endl;
    
    for(i = 0; i < studentInfo.size(); ++i){
        currStudent = studentInfo.at(i);
        currStudent.GetClasses(studentCourse);
        
        if(studentCourse.find(courseName) != string::npos){
            currStudent.GetName(firstName, lastName);
            currStudent.GetID(studentID);
            currStudent.GetEmail(studentEmail);
            cout << left << setw(7);
            cout << firstName << '\t';
            cout << left << setw(10);
            cout << lastName << '\t' << ' ';
            cout << studentID << "\t\t" << studentEmail << endl;
            
            outFile << left << setw(7);
            outFile << firstName << '\t';
            outFile << left << setw(10);
            outFile << lastName << '\t' << "  ";
            outFile << studentID << "\t\t" << studentEmail << endl;
        }
    }
    cout << endl;
}


//FIXME: NEEDS IMPLEMENTING
void ClassSection::ClassAttendanceReport(string fileName, int classNum){
    Classes currClass = classInfo.at(classNum);
    Student currStudent;
    vector<Student> tempStudent;
    vector<int> tempAttendance;
    string firstName, lastName;
    unsigned int i;
    unsigned int j;
    
    currClass.SetStudents(tempStudent);
    currClass.ClassAttendance();
    
    ofstream outFile;
    outFile.open(fileName);
    
    for(i = 0; i < tempStudent.size(); ++i){
        currStudent = tempStudent.at(i);
        currStudent.GetName(firstName, lastName);
        currStudent.GetAttendance(tempAttendance);
        outFile << firstName << ' ' << lastName;
        
        for(j = 0; j < 30; ++j){
            outFile << tempAttendance.at(j);
        }
    }
    outFile.close();
}


//FIXME: I may not need this function anymore
void ClassSection::FillClass(string courseName){     //For filling class with students taking class
    Student currStudent;
    Classes currClass;
    string  classes;
    unsigned int i;
    
    for(i = 0; i < studentInfo.size(); ++i){
        currStudent = studentInfo.at(i);
        currStudent.GetClasses(classes);
        
        currClass = classInfo.at(0);
        if(classes == currClass.GetCourseName()){
            
        }
        
//        if(classes.find("Calculus_I") != string::npos){
//            currClass = classInfo.at(0);
//            currClass.FillStudentsVector(currStudent);
//        }
//        else if(classes.find("Calculus_II") != string::npos){
//            currClass = classInfo.at(1);
//            currClass.FillStudentsVector(currStudent);
//        }
//        else if(classes.find("University_Physics_I") != string::npos){
//            currClass = classInfo.at(2);
//            currClass.FillStudentsVector(currStudent);
//        }
//        else if(classes.find("University_Physics_II") != string::npos){
//            currClass = classInfo.at(3);
//            currClass.FillStudentsVector(currStudent);
//        }
//        else if(classes.find("Programming_Fundamentals_I") != string::npos){
//            currClass = classInfo.at(4);
//            currClass.FillStudentsVector(currStudent);
//        }
    }
}
