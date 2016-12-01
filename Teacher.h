#ifndef TEACHER_H
#define TEACHER_H

#include <string>

#include "People.h"

using namespace std;

class Teacher :
	public People
{
public:
	Teacher();
	Teacher(string name, int m, int d, int y) : People(name, m, d, y) {}
	~Teacher();
};

#endif // !TEACHER_H