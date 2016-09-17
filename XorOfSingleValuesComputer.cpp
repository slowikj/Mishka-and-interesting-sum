#include "XorOfSingleValuesComputer.h"

using namespace std;

XorOfSingleValuesComputer::XorOfSingleValuesComputer (shared_ptr<TaskData> dataPtr)
	: _taskData(dataPtr)
{
}

const int& XorOfSingleValuesComputer::Result (const int& queryNumber)
{
	if (_IsResultNotComputed())
		_results = _GetResults();

	return _results[queryNumber];
}

bool XorOfSingleValuesComputer::_IsResultNotComputed () const
{
	return _results.size() == 0;
}

vector<int> XorOfSingleValuesComputer::_GetResults () const
{
	vector<int> res(_taskData->NumberOfQueries());

	vector<vector<int>> queries = _GetVectorsWithSetQueries();
	unordered_map<int,int> lastOccur;
//	IntervalTree xorOfSingleValues(_taskData->NumberOfNumbers());
	BinaryIndexedTree xorOfSingleValues(_taskData->NumberOfNumbers());

	for(int i = 0; i < _taskData->NumberOfNumbers(); ++i)
	{
		int val = _taskData->Number(i);
		if (lastOccur.find(val) != lastOccur.end())
			xorOfSingleValues.Insert(lastOccur[val], val);

		xorOfSingleValues.Insert(i, val);
		lastOccur[val] = i;

		for (const int& queryInd: queries[i])
			res[queryInd] = xorOfSingleValues.Query(_taskData->Query(queryInd));
	}

	return res;
}

vector<vector<int>> XorOfSingleValuesComputer::_GetVectorsWithSetQueries () const
{
	vector<vector<int>> res(_taskData->NumberOfNumbers());

	for (int queryInd = 0; queryInd < _taskData->NumberOfQueries(); ++queryInd)
		res[_taskData->GetEndOfInterval(queryInd)].push_back (queryInd);

	return res;
}

