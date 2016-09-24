#pragma once
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include <exception>
#include "TaskData.h"
#include "SuffixXorOfSingleValues.h"

using namespace std;

class XorOfSingleValuesComputer
{
public:
	shared_ptr<TaskData> _taskData;
	vector<int> _results;

	bool _IsResultComputed () const;
	vector<int> _GetResults () const;
	vector<vector<int>> _GetQueriesGroupedByEnd () const;
						   
public:
	XorOfSingleValuesComputer (shared_ptr<TaskData> dataPtr);
	int Result (int queryNumber);
};

