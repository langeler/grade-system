#include "Grade.h"

Grade::Grade()
{
	// TODO Auto-generated constructor stub

}

Grade::~Grade()
{
	// TODO Auto-generated destructor stub
}

// Getter
int Grade::ID()
{
	return _id;
}

// Setter
void Grade::ID(int id)
{
	_id = id;
}

// Getter
int Grade::SubjectID()
{
	return _subject_id;
}

// Setter
void Grade::SubjectID(int id)
{
	_subject_id = id;
}

// Getter
int Grade::CourseID()
{
	return _course_id;
}

// Setter
void Grade::CourseID(int id)
{
	_course_id = id;
}

// Getter
int Grade::TheGrade()
{
	return _grade;
}

// Setter
void Grade::TheGrade(int grade)
{
	_grade = grade;
}

// Getter
int Grade::TeacherID()
{
	return _teacher_id;
}

// Setter
void Grade::TeacherID(int id)
{
	_teacher_id = id;
}

// Getter
int Grade::StudentID()
{
	return _student_id;
}

// Setter
void Grade::StudentID(int id)
{
	_student_id = id;
}

// Getter
int Grade::CoursePermID()
{
	return _course_perm_id;
}

// Setter
void Grade::CoursePermID(int id)
{
	_course_perm_id = id;
}

// Getter
string Grade::CourseName()
{
	return _course_name;
}

// Setter
void Grade::CourseName(string name)
{
	_course_name = name;
}

// Getter
string Grade::SubjectName()
{
	return _subject_name;
}

// Setter
void Grade::SubjectName(string name)
{
	_subject_name = name;
}

// Getter
string Grade::StudentName()
{
	return _student_name;
	
}

// Setter
void Grade::StudentName(string name)
{
	_student_name = name;
}

// Getter
string Grade::TeacherName()
{
	return _teacher_name;
}

// Setter
void Grade::TeacherName(string name)
{
	_teacher_name = name;
}


