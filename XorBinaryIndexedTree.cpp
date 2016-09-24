#include "XorBinaryIndexedTree.h"

XorBinaryIndexedTree::XorBinaryIndexedTree (int arrayLength)
	: _nodes(arrayLength + 1, 0)
{
	_treeSize = _nodes.size();
}

void XorBinaryIndexedTree::Insert (int where, int val)
{
	int index = where + 1;

	while (index < _treeSize)
	{
		_nodes[index] ^= val;
		index = _NextNodeToUpdate(index);
	}
}

int XorBinaryIndexedTree::_NextNodeToUpdate (int index) const
{
	return index + _GreatestPowerOf2DivisorOf(index);
}

int XorBinaryIndexedTree::_GreatestPowerOf2DivisorOf (int x) const
{
	return ((x ^ (x - 1)) + 1) >> 1;
}

int XorBinaryIndexedTree::Query (const Interval& interval) const
{
	return _PrefixResult(interval.End + 1) ^ _PrefixResult(interval.Begin);
}

int XorBinaryIndexedTree::_PrefixResult (int End) const
{
	int index = End;
	int res = 0;

	while (index > 0)
	{
		res ^= _nodes[index];
		index = _NextNodeToGetValue(index);
	}

	return res;
}

int XorBinaryIndexedTree::_NextNodeToGetValue (int index) const
{
	return index - _GreatestPowerOf2DivisorOf(index);
}
