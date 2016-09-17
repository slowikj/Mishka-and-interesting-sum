#include "BinaryIndexedTree.h"

BinaryIndexedTree::BinaryIndexedTree (const int& arrayLength)
	: _nodes(arrayLength + 1, 0)
{
	_treeSize = _nodes.size();
}

void BinaryIndexedTree::Insert (const int& where, const int &val)
{
	int index = where + 1;

	while (index < _treeSize)
	{
		_nodes[index] ^= val;
		index = _NextNodeToUpdate(index);
	}
}

int BinaryIndexedTree::_NextNodeToUpdate (const int& index) const
{
	return index + _GreatestPowerOf2DivisorOf(index);
}

int BinaryIndexedTree::_GreatestPowerOf2DivisorOf (const int& x) const
{
	return ((x ^ (x - 1)) + 1) >> 1;
//	return x - (x&(x-1));
//	return x & (-x);
}

int BinaryIndexedTree::Query (const Interval& interval) const
{
	return _PrefixResult(interval.End + 1) ^ _PrefixResult(interval.Begin);
}

int BinaryIndexedTree::_PrefixResult (int End) const
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

int BinaryIndexedTree::_NextNodeToGetValue (const int& index) const
{
	return index - _GreatestPowerOf2DivisorOf(index);
}
