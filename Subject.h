#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

using namespace std;

class Subject
{
private:
	string _name;

public:
	Subject();
	~Subject();
	void Name(string name);
	string Name();
};

#endif