#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include "Date.h"

using namespace std;

class People
{
private:
	string _name;
	Date _dob;
public:
	People();
	People(string name, int m, int d, int y);
	~People();
	void Name(string name);
	string Name();
	void DateOfBirth(int m, int d, int y);
	string DateOfBirth();
};

#endif // !PEOPLE_H