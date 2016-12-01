#ifndef ALL_GRADES_H_
#define ALL_GRADES_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <utility>
#include "Grade.h"

using namespace std;

class AllGrades {

private:
	string _data_dir;
	vector<Grade> _grades;
	vector<pair<int, string> > GetCourseName(int cid);
	pair<int, string> GetName(int sid, string fname);
	pair<int, string> GetTeacherName(int pid);

public:
	AllGrades(string data_dir);
	virtual ~AllGrades();
	void DisplayGrades(int student_id);
	void SetGrade(int student_id, int teacher_id, int course_id, int grade);
	void SaveGrades();
};

#endif /* GRADE_H_ */
