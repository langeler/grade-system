#include <iostream>
#include <string>

#include "Date.h"
#include "People.h"
#include "Student.h"
#include "Teacher.h"
#include "Grade.h"

using namespace std;

int main(int argc, char** argv)
{
	Teacher teacher("Mattias Wickberg", 3, 21, 1986);
	Student student("Alexander Ensani", 1, 2, 1997);
	Grade grades;

	// Set up the Grades object
	grades.ClassName("TE14B");
	grades.CourseName("swedish 1");
	grades.ClassTeacher(teacher.Name(), 3, 21, 1986);
	grades.AddStudent(student.Name(), 1, 2, 1997);
	grades.SetGrade(student, 4);

	return 0;
}