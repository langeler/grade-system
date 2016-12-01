#ifndef GRADE_H
#define GRADE_H

#include <string>
#include <vector>

#include "Student.h"
#include "Teacher.h"
#include "Course.h"

using namespace std;

class Grade
{
private:
	string _class_name;
	string _course_name;
	vector<Student> _students;
	Teacher _teacher;
public:
	Grade();
	~Grade();
	void CourseName(string course_name);
	string CourseName();
	void ClassName(string class_name);
	string ClassName();
	void ClassTeacher(string name, int m, int d, int y);
	Teacher ClassTeacher();
	void AddStudent(string name, int m, int d, int y);
	Student FindStudent(Student student);
	void SetGrade(Student student, int grade);
};

#endif