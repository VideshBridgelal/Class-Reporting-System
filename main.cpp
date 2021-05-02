//
//  main.cpp
//  Class Reporting System
//
//  Created by Videsh Bridgelal on 4/20/21.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <string>

#include "ClassSection.h"

using namespace std;

int main() {
    ClassSection school;
    
    school.ReadClassFile();
    school.ReadStudentFile();
    
    school.TestClasses();
    char userChar = '\0';
    int userNum;
    string fileName;
    string courseName;
    
    
    //Basic UI for proogram
    cout << "c - Class Offerings" << endl;
    cout << "r - Roster Report" << endl;
    //cout << "a - Attendance Report" << endl;
    cout << "g - Grade Report" << endl;
    cout << "q - Quit" << endl;
    
    while (userChar != 'q'){
        cin >> userChar;
        cout << endl;
        switch(userChar){
            case 'c':   //Class Offerings Report
                school.ClassOfferingsReport();
                
                cout << "c - Class Offerings" << endl;
                cout << "r - Roster Report" << endl;
                //cout << "a - Attendance Report" << endl;
                cout << "g - Grade Report" << endl;
                cout << "q - Quit" << endl;
                break;
            
//-----------------------------------------------------------------------
            case 'r':   //Roster Report
                //13 in Calculus I
                //17 in Caclulus II and UniPhys I
                //15 in UniversityPhysics II and ProgFund I
                cout << "0. Calculus I" << endl;
                cout << "1. Calculus II" << endl;
                cout << "2. University Physics I" << endl;
                cout << "3. University Physics II" << endl;
                cout << "4. Programming Fundamentals I" << endl;
                cout << "Pick a class #: ";
                cin >> userNum;
                cout << endl;
                switch(userNum){
                    case 0:
                        fileName = "Calculus_1.txt";
                        courseName = "Calculus_I";
                        school.ClassRosterReport(fileName, userNum);
                        break;
                        
                    case 1:
                        fileName = "Calculus_2.txt";
                        courseName = "Calculus_2";
                        school.ClassRosterReport(fileName, userNum);
                        break;
                        
                    case 2:
                        fileName = "UniversityPhysics_1.txt";
                        courseName = "University_Physics_I";
                        school.ClassRosterReport(fileName, userNum);
                        break;
                        
                    case 3:
                        fileName = "UniversityPhysics_2.txt";
                        courseName = "University_Physics_II";
                        school.ClassRosterReport(fileName, userNum);
                        break;
                        
                    case 4:
                        fileName = "ProgrammingFund.txt";
                        courseName = "Programming_Fundamentals_I";
                        school.ClassRosterReport(fileName, userNum);
                        break;
                        
                    default:
                        cout << "Invalid input" << endl;
                        break;
                }
                
                cout << "c - Class Offerings" << endl;
                cout << "r - Roster Report" << endl;
                //cout << "a - Attendance Report" << endl;
                cout << "g - Grade Report" << endl;
                cout << "q - Quit" << endl;
                
                break;
                
                
//-----------------------------------------------------------------------
//            case 'a':   //Attendance Report
//                cout << "0. Calculus I" << endl;
//                cout << "1. Calculus II" << endl;
//                cout << "2. University Physics I" << endl;
//                cout << "3. University Physics II" << endl;
//                cout << "4. Programming Fundamentals I" << endl;
//                cout << "Pick a class #: ";
//                cin >> userNum;
//                cout << endl;
//
//                switch(userNum){
//                    case 1:
//                        fileName = "CalculusAttendance.txt";
//                        school.ClassAttendanceReport(fileName, userNum);
//                        break;
//
//                    case 2:
//                        fileName = "Calculus2Attendance.txt";
//                        school.ClassAttendanceReport(fileName, userNum);
//                        break;
//
//                    case 3:
//                        fileName = "UniversityPhysicsAttendance.txt";
//                        school.ClassAttendanceReport(fileName, userNum);
//                        break;
//
//                    case 4:
//                        fileName = "UniversityPhysics2Attendance.txt";
//                        school.ClassAttendanceReport(fileName, userNum);
//                        break;
//
//                    case 5:
//                        fileName = "ProgrammingFundAttendance.txt";
//
//                        school.ClassAttendanceReport(fileName, userNum);
//                        break;
//
//                    default:
//                        cout << "Invalid input" << endl;
//                        break;
//                }
//
//                cout << "c - Class Offerings" << endl;
//                cout << "r - Roster Report" << endl;
//                cout << "a - Attendance Report" << endl;
//                cout << "g - Grade Report" << endl;
//                cout << "q - Quit" << endl;
//                break;

//-----------------------------------------------------------------------
            case 'g':   //Grade Report
                cout << "0. Calculus I" << endl;
                cout << "1. Calculus II" << endl;
                cout << "2. University Physics I" << endl;
                cout << "3. University Physics II" << endl;
                cout << "4. Programming Fundamentals I" << endl;
                cout << "Pick a class #: ";
                cin >> userNum;
                cout << endl;
                
                switch(userNum){
                    case 0:
                        fileName = "CalculusGradeReport.txt";
                        school.GradeReport(fileName, userNum);
                        break;
                        
                    case 1:
                        fileName = "Calculus2GradeReport.txt";
                        school.GradeReport(fileName, userNum);
                        break;
                        
                    case 2:
                        fileName = "UniPhysGradeReport.txt";
                        school.GradeReport(fileName, userNum);
                        break;
                        
                    case 3:
                        fileName = "UniPhys2GradeReport.txt";
                        school.GradeReport(fileName, userNum);
                        break;
                        
                    case 4:
                        fileName = "ProgFundGradeReport.txt";

                        school.GradeReport(fileName, userNum);
                        break;
                        
                    default:
                        cout << "Invalid input" << endl;
                        break;
                }
                
                cout << "c - Class Offerings" << endl;
                cout << "r - Roster Report" << endl;
                //cout << "a - Attendance Report" << endl;
                cout << "g - Grade Report" << endl;
                cout << "q - Quit" << endl;
                break;
        }
    }
    return 0;
}
