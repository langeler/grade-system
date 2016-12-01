#ifndef PERSON_DATE_H
#define PERSON_DATE_H

#include <string>

using namespace std;

class Date
{
private:
	short _month, _day, _year;
public:
	Date();
	~Date();
	void SetDate(int m, int d, int y);
	string GetDate();
};

#endif // !PERSON_DATE_H