#pragma once

#include <vector>
#include "Interval.h"

class BinaryIndexedTree
{
private:
	vector<int> _nodes;
	int _treeSize;
	
	int _GreatestPowerOf2DivisorOf (int x) const;
	int _NextNodeToUpdate (int index) const;
	int _NextNodeToGetValue (int index) const;
	int _PrefixResult (int End) const;

public:
	BinaryIndexedTree (int arrayLength);
	void Insert (int where, int val);
	int Query (const Interval& interval) const;
};
