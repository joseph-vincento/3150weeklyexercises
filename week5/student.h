#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>

using namespace std;

struct student {
  int id;
  string name;
  int final_exam;
  int mid_term;
  vector<int> hw_grades;
};

student get_student();
void print_student(student s);
int calc_overall_grade(student s);

#endif