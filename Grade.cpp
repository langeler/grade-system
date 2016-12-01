#include "Grade.h"

Grade::Grade()
{
}

Grade::~Grade()
{
}

void Grade::CourseName(string course_name)
{
	_course_name = course_name;
}

string Grade::CourseName()
{
	return _course_name;
}

void Grade::ClassName(string class_name)
{
	_class_name = class_name;
}

string Grade::ClassName()
{
	return _class_name;
}

void Grade::ClassTeacher(string name, int m, int d, int y)
{
	_teacher = Teacher(name, m, d, y);
}

Teacher Grade::ClassTeacher()
{
	return Teacher();
}

void Grade::AddStudent(string name, int m, int d, int y)
{
	Student student(name, m, d, y);

	// Check to make sure the student doesn't already exist
	bool found = false;
	for (vector<Student>::iterator it = _students.begin(); it != _students.end(); ++it)
	{
		string studentName = (Student(*it)).Name();
		if (studentName == student.Name()) found = true;
	}

	// If the student wasn't found, then add it.
	if (!found) _students.push_back(student);
}

Student Grade::FindStudent(Student student)
{
	for (vector<Student>::iterator it = _students.begin(); it != _students.end(); ++it)
	{
		string studentName = (Student(*it)).Name();
		if (studentName == student.Name()) return (Student)*it;
	}
}

void Grade::SetGrade(Student student, int grade)
{
	for (vector<Student>::iterator it = _students.begin(); it != _students.end(); ++it)
	{
		string studentName = (Student(*it)).Name();
		if (studentName == student.Name()) ((Student)*it).ChangeGrade(_course_name, grade);
	}
}