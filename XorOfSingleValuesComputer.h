#pragma once
#include <memory>
#include <vector>
#include <unordered_map>
#include "TaskData.h"
#include "IntervalTree.h"
#include "BinaryIndexedTree.h"

using namespace std;

class XorOfSingleValuesComputer
{
private:
	shared_ptr<TaskData> _taskData;
	vector<int> _results;

	bool _IsResultNotComputed () const;
	vector<int> _GetResults() const;
	vector<vector<int>> _GetVectorsWithSetQueries () const;
						   
public:
	XorOfSingleValuesComputer (shared_ptr<TaskData> dataPtr);
	const int& Result (const int& queryNumber);
};

