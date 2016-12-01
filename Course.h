#ifndef COURSE_H
#define COURSE_H

#include <string>

#include "Subject.h"

using namespace std;

class Course :
	public Subject
{
private:
	int _course_name;
	int _grade;
	bool IsInt(const string & s);
public:
	Course();
	~Course();
	void CourseName(string _name);
	string CourseName();
	void Grade(int grade);
	int Grade();
	string LetterGrade();
};

#endif