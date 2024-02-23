#include <iostream>
#include "student.h"

using namespace std;

student get_student() {
    student new_student;
    cout << "Enter the student's id: ";
    cin >> new_student.id;

    cout << "Enter the student's name: ";
    cin >> new_student.name;

    cout << "Enter the student's final exam grade: ";
    cin >> new_student.final_exam;

    cout << "Enter the student's mid term exam grade: ";
    cin >> new_student.mid_term;

    int hws = 0;
    cout << "Enter the number of homeworks assignments for the semester: ";
    cin >> hws;

    for(int i = 0; i < hws; i++) {
        int grade;
        cout << "Enter the student's grade for assignemnt #" << i + 1 << ": ";
        cin >> grade;
        new_student.hw_grades.push_back(grade);
    }

    return new_student;

}

void print_student(student s) {
    cout << "Student ID: " << s.id << endl;
    cout << "Student name: " << s.name << endl;
    cout << "Final exam grade: " << s.final_exam << endl;
    cout << "Mid term exam grade: " << s.mid_term << endl;

    int i = 1;
    for(int &grade: s.hw_grades) {
        cout << "Assignment #" << i << " grade: " << grade << endl;
    }

    cout << s.name << "'s overall grade is: " << calc_overall_grade(s) << endl;
}

int calc_overall_grade(student s) {
    float weighted_final = 0.3 * s.final_exam;
    float weighted_mid_term = 0.3 * s.mid_term;
    
    float hw_average = 0;
    if(s.hw_grades.size() > 0) {
        for(int &grade: s.hw_grades) {
            hw_average += grade;
        }
        hw_average = hw_average / s.hw_grades.size();
    } else {
        hw_average = 100; 
    }
    float weighted_hw = 0.4 * hw_average;
    int overall_grade = static_cast<int>(weighted_final + weighted_hw + weighted_mid_term);
    return overall_grade;
}