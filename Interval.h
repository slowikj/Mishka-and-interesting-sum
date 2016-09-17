#pragma once
#include <iostream>

using namespace std;

struct Interval
{
	int Begin, End;

	explicit Interval (int begin = 0, int end = 0)
		: Begin(begin), End(end)
	{
	}

	friend istream& operator>> (istream& is, Interval& interval)
	{
		return is >> interval.Begin >> interval.End;
	}
};

