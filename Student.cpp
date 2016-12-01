#include "Student.h"

Student::Student()
{
}

Student::~Student()
{
}

void Student::AddCourse(Course course)
{
	// Check to make sure the course doesn't already exist
	bool found = false;
	for (vector<Course>::iterator it = _courses.begin(); it != _courses.end(); ++it)
	{
		string courseName = (Course(*it)).CourseName();
		if (courseName == course.CourseName()) found = true;
	}

	// If the course wasn't found, then add it.
	if (!found) _courses.push_back(course);
}

void Student::ChangeGrade(string courseName, int newGrade)
{
	// Find the course
	for (vector<Course>::iterator it = _courses.begin(); it != _courses.end(); ++it)
	{
		string courseName = (Course(*it)).CourseName();
		if (courseName == courseName)
		{
			((Course)*it).Grade(newGrade);
		}
	}
}

void Student::ChangeGrade(Course course)
{
	for (vector<Course>::iterator it = _courses.begin(); it != _courses.end(); ++it)
	{
		string courseName = (Course(*it)).CourseName();
		if (courseName == course.CourseName())
		{
			((Course)*it).Grade(course.Grade());
		}
	}
}