#include "Course.h"

Course::Course()
{
}

Course::~Course()
{
}

void Course::CourseName(string n)
{
	size_t pos = 0;
	string delimiter = "";
	string token;
	string name;
	while ((pos = n.find(delimiter)) != string::npos)
	{
		token = n.substr(0, pos);
		if (!IsInt(token))
			name += token + " ";
		else
		{
			Name(name);
			_course_name = stoi(token);
		}
	}
}

string Course::CourseName()
{
	return Name() + " " + to_string(_course_name);
}

void Course::Grade(int grade)
{
	_grade = grade;
}

int Course::Grade()
{
	return _grade;
}

string Course::LetterGrade()
{
	string letter_grade;

	switch (_grade)
	{
	case 5:
		letter_grade = "A";
		break;
	case 4:
		letter_grade = "B";
		break;
	case 3:
		letter_grade = "C";
		break;
	case 2:
		letter_grade = "D";
		break;
	default:
		letter_grade = "F";
		break;
	}

	return letter_grade;
}

// Helper method to check if a string is an integer.
// This could be put into a bigger utility class in the future.
bool Course::IsInt(const string &s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}