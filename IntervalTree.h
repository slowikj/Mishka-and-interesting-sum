#pragma once
#include <vector>
#include "Interval.h"

using namespace std;

class IntervalTree
{
private:
	vector<int> _nodes;

	int _GetSizeOfTree (int minimumNumberOfLeaves) const;
	int _NearestPowerOf2NotLowerThan (int x) const;

public:
	IntervalTree (int arrayLength);
	void Insert (int where, int val);
	int Query (const Interval& interval);
	int NumberOfLeaves () const;
};

