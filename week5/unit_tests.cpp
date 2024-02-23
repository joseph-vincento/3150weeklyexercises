#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"
#include <string>

TEST_CASE("student") {
    SUBCASE("total class score") {
        // Case 1: student has all 100s
        student student1;
        student1.id = 1;
        student1.name = "test 1";
        student1.final_exam = 100;
        student1.mid_term = 100;
        student1.hw_grades.push_back(100);

        CHECK_EQ(100, calc_overall_grade(student1));

        // Case 2: student has all 0s
        student student2;
        student2.id = 2;
        student2.name = "test 2";
        student2.final_exam = 0;
        student2.mid_term = 0;
        student2.hw_grades.push_back(0);

        CHECK_EQ(0, calc_overall_grade(student2));

        // Case 3: no homeworks
        student student3;
        student3.id = 3;
        student3.name = "test 3";
        student3.final_exam = 100;
        student3.mid_term = 100;

        CHECK_EQ(100, calc_overall_grade(student3));

        // Case 4: expected use case
        // mixed grades, students overall grade is 81
        student student4;
        student4.id = 4;
        student4.name = "test 4";
        student4.final_exam = 74;
        student4.mid_term = 85;
        student4.hw_grades.push_back(95);
        student4.hw_grades.push_back(84);
        student4.hw_grades.push_back(87);
        student4.hw_grades.push_back(76);
        student4.hw_grades.push_back(79);

        CHECK_EQ(81, calc_overall_grade(student4));
    }
}