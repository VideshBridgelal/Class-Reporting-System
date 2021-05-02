//
//  Student.cpp
//  Class Reporting System
//
//  Created by Videsh Bridgelal on 4/21/21.
//

#include <iostream>
#include <vector>
#include <string>

#include "Student.h"

using namespace std;

double Student::CalculateAverage(){
    unsigned int i = 0;
    double total = 0;
    double average;
    
    
    for(i = 0; i < 5; ++i){
        if(i == 5)
            total = total + (grades.at(i) * 2.0);
        else
            total = total + grades.at(i);
    }
    average = (total / 600.0) * 100.0;
    grades.push_back(average);
    return (total / 500.0) * 100;
}

void Student::PrintGradeReport(){
    cout << firstName << ' ' << lastName << '\t';
    
    for(int i = 0; i < 5; ++i){
        cout << grades.at(i) << '\t';
    }
    
    if(grades.at(5) > 89)
        cout << 'A';
    else if(grades.at(5) > 79)
        cout << 'B';
    else if(grades.at(5) > 69)
        cout << 'C';
    else if(grades.at(5) > 59)
        cout << 'D';
    else cout << 'F';
    
    cout << endl;
}

void Student::PrintRoster(){
    cout << firstName << ' ' << lastName << '\t' << studentID << '\t' << studentEmail << endl;
}

