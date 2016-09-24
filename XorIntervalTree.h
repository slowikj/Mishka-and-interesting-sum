#pragma once
#include <vector>
#include "Interval.h"
#include "AbstractXorIntervalTree.h"

using namespace std;

class XorIntervalTree : public AbstractXorIntervalTree
{
private:
	vector<int> _nodes;

	int _GetSizeOfTree (int minimumNumberOfLeaves) const;
	int _NearestPowerOf2NotLowerThan (int x) const;

public:
	XorIntervalTree (int arrayLength);
	void Insert (int where, int val);
	int Query (const Interval& interval) const;
	int NumberOfLeaves () const;
};

