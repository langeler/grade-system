#include <iostream>
#include "Grade.h"
#include "AllGrades.h"

using namespace std;

int main() {
	AllGrades grades("data");
	grades.DisplayGrades(-1);
	grades.SetGrade(2, 4, 5, 5);
	grades.SetGrade(2, 1, 1, 4);
	grades.DisplayGrades(-1);
	grades.SaveGrades();
	
	return 0;
}
