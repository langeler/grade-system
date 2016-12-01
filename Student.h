#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

#include "People.h"
#include "Course.h"

using namespace std;

class Student :
	public People
{
private:
	vector<Course> _courses;

public:
	Student();
	Student(string name, int m, int d, int y) : People(name, m, d, y) {}
	~Student();
	void AddCourse(Course course);
	void ChangeGrade(string courseName, int newGrade);
	void ChangeGrade(Course course);
};

#endif // !STUDENT_H