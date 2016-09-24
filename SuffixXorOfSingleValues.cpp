#include "SuffixXorOfSingleValues.h"
#include <iostream>
using namespace std;

SuffixXorOfSingleValues::SuffixXorOfSingleValues (const string& treeName,
												  int maxNumberOfElements)
{
	if (treeName == "IntervalTree")
		_xorTree = make_unique<XorIntervalTree>(maxNumberOfElements);
	else if (treeName == "BinaryIndexedTree")
		_xorTree = make_unique<XorBinaryIndexedTree>(maxNumberOfElements);

	_end = 0;
}

int SuffixXorOfSingleValues::Result (int begin) const
{
	if (!_IsBeginOfSuffixCorrect(begin))
		throw new invalid_argument("begin");

	return _xorTree->Query(Interval(begin, _end - 1));
}

bool SuffixXorOfSingleValues::_IsBeginOfSuffixCorrect (int begin) const
{
	return !(begin < 0 || begin >= _end);
}

void SuffixXorOfSingleValues::PushBack (int number)
{
	if (_lastOccur.find(number) != _lastOccur.end())
		_xorTree->Insert(_lastOccur[number], number);

	_xorTree->Insert(_end, number);
	_lastOccur[number] = _end;

	++_end;
}
