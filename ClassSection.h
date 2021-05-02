//
//  ClassSection.hpp
//  Class Reporting System
//
//  Created by Videsh Bridgelal on 4/21/21.
//

#ifndef ClassSection_h
#define ClassSection_h

#include <stdio.h>
#include <vector>
#include "Student.h"
#include "Classes.h"

using namespace std;

class ClassSection{
public:
    void ReadStudentFile();
    void ReadClassFile();
    void GradeReport(string fileName, int classNum);
    void ClassOfferingsReport();
    void ClassRosterReport(string fileName, int classNum);
    void ClassAttendanceReport(string fileName, int classNum);
    void FillClass(string courseName);
    
    void TestClasses(){
        Classes currClass;
        
        for(int i = 0; i < classInfo.size(); ++i){
            currClass = classInfo.at(i);
            currClass.TestStudents();
            //currClass.PrintClass();
        }
    }
    
private:
    Student student;                //For temporary student
    Classes classes;                //For temporary classes
    vector<Student> studentInfo;    //For holding students
    vector<Classes> classInfo;      //For holding classes
    vector<double>  firstGrades;    //These vectors are to calculate the overall averages
    vector<double>  secondGrades;
    vector<double>  thirdGrades;
    vector<double>  fourthGrades;
    vector<double>  finalGrades;
};

#endif /* ClassSection_hpp */
