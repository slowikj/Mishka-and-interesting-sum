#pragma once

#include <vector>
#include "Interval.h"

class BinaryIndexedTree
{
private:
	vector<int> _nodes;
	int _treeSize;
	
	int _GreatestPowerOf2DivisorOf (const int& x) const;
	int _NextNodeToUpdate (const int& index) const;
	int _NextNodeToGetValue (const int& index) const;
	int _PrefixResult (int End) const;

public:
	BinaryIndexedTree (const int& arrayLength);
	void Insert (const int& where, const int &val);
	int Query (const Interval& interval) const;
};
