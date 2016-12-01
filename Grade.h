#ifndef GRADE_H_
#define GRADE_H_

#include <iostream>
#include <string>

using namespace std;

class Grade {
private:
	int _id;
	int _subject_id;
	int _course_id;
	int _grade;
	int _student_id;
	int _teacher_id;
	int _course_perm_id;
	string _course_name;
	string _subject_name;
	string _student_name;
	string _teacher_name;
public:
	Grade();
	virtual ~Grade();
	int ID();
	void ID(int id);
	int SubjectID();
	void SubjectID(int id);
	int CourseID();
	void CourseID(int id);
	int TheGrade();
	void TheGrade(int grade);
	int TeacherID();
	void TeacherID(int id);
	int StudentID();
	void StudentID(int id);
	int CoursePermID();
	void CoursePermID(int id);
	string CourseName();
	void CourseName(string name);
	string SubjectName();
	void SubjectName(string name);
	string StudentName();
	void StudentName(string name);
	string TeacherName();
	void TeacherName(string name);

};

#endif /* GRADE_H_ */
