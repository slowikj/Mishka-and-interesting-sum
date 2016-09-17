#pragma once
#include <vector>
#include "Interval.h"

using namespace std;

class IntervalTree
{
private:
	vector<int> _nodes;

	int _GetSizeOfTree (const int& minimumNumberOfLeaves) const;
	int _NearestPowerOf2NotLowerThan (const int& x) const;

public:
	IntervalTree (const int& arrayLength);
	void Insert (const int& where, const int& val);
	int Query (const Interval& interval);
	int NumberOfLeaves () const;
};

