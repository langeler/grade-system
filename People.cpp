#include "People.h"

People::People()
{
}

People::People(string name, int m, int d, int y)
{
	_name = name;
	_dob.SetDate(m, d, y);
}

People::~People()
{
}

void People::Name(string name)
{
	_name = name;
}

string People::Name()
{
	return _name;
}

void People::DateOfBirth(int m, int d, int y)
{
	_dob.SetDate(m, d, y);
}

string People::DateOfBirth()
{
	return _dob.GetDate();
}