#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int testCGPA()
{
    Course courses[2] = {
        createCourse("CSE4107", "StructuredProgrammingI", 3.0),
        createCourse("CSE4108", "StructuredProgrammingILab", 1.5)
    };
    CourseResult results[2] = {
        createCourseResult(&courses[0], 240),
        createCourseResult(&courses[1], 105)
    };
    double cgpa = calculateGPA(results, 2);
    return cgpa > 3.83 && cgpa < 3.84;
}

int testGradePoint()
{
    Course course = createCourse("CSE4107", "StructuredProgrammingI", 3.0);
    CourseResult result = createCourseResult(&course, 240);
    return getGradePoint(result) == 4.00;
}

int testLetterGrade()
{
    Course course = createCourse("CSE4108", "StructuredProgrammingILab", 1.5);
    CourseResult result = createCourseResult(&course, 105);
    return getLetterGrade(result)[0] == 'A' && getLetterGrade(result)[1] == '-';
}

int main()
{
    printf("GPAmoduletests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testCGPA()) passed++;
    total++;
    if (testGradePoint()) passed++;
    total++;
    if (testLetterGrade()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}