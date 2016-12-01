#include "Subject.h"

Subject::Subject()
{
}

Subject::~Subject()
{
}

void Subject::Name(string name)
{
	_name = name;
}

string Subject::Name()
{
	return _name;
}
