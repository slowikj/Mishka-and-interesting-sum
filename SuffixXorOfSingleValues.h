#pragma once
#include <memory>
#include <unordered_map>
#include <string>
#include <exception>
#include "XorIntervalTree.h"
#include "XorBinaryIndexedTree.h"
#include "AbstractXorIntervalTree.h"

using namespace std;

class SuffixXorOfSingleValues
{
private:
	unique_ptr<AbstractXorIntervalTree> _xorTree;
	unordered_map<int, int> _lastOccur;
	int _end;

	bool _IsBeginOfSuffixCorrect (int begin) const;

public:
	SuffixXorOfSingleValues (const string& treeName,
							 int maxNumberOfElements);

	int Result (int end) const;
	void PushBack (int number);
};

