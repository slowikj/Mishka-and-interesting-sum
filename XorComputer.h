#pragma once
#include <memory>
#include <exception>
#include <vector>
#include "TaskData.h"

using namespace std;

class XorComputer
{
private:
	shared_ptr<TaskData> _taskData;
	vector<int> _prefixXor;
	
	bool _IsPreprocessingDone () const;
	vector<int> _GetXorPrefixes () const;

public:
	XorComputer (shared_ptr<TaskData> _dataPtr);
	int Result (const Interval& interval);
	int Result (const int& queryNumber);
};

