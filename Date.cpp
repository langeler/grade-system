#include "Date.h"


Date::Date()
{
}

Date::~Date()
{
}

void Date::SetDate(int m, int d, int y)
{
	_month = (short)m;
	_day = (short)d;
	_year = (short)y;
}

string Date::GetDate()
{
	string date = to_string(_year) + ' ' + to_string(_month) + ' ' + to_string(_day);
	return date;
}