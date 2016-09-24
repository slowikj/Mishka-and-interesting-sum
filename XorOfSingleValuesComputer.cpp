#include "XorOfSingleValuesComputer.h"

using namespace std;

XorOfSingleValuesComputer::XorOfSingleValuesComputer (shared_ptr<TaskData> dataPtr)
	: _taskData(dataPtr)
{
}

int XorOfSingleValuesComputer::Result (int queryNumber)
{
	if (!_IsResultComputed())
		_results = _GetResults();

	return _results[queryNumber];
}

bool XorOfSingleValuesComputer::_IsResultComputed () const
{
	return _results.size() != 0;
}

vector<int> XorOfSingleValuesComputer::_GetResults () const
{
	vector<int> res(_taskData->NumberOfQueries());

	vector<vector<int>> queriesEndAt = _GetQueriesGroupedByEnd();
	SuffixXorOfSingleValues suffixXorOfSingleValues("BinaryIndexedTree",
													_taskData->NumberOfNumbers());

	for(int i = 0; i < _taskData->NumberOfNumbers(); ++i)
	{
		suffixXorOfSingleValues.PushBack(_taskData->Number(i));
		
		for (int queryInd: queriesEndAt[i])
			res[queryInd] = suffixXorOfSingleValues.Result(_taskData->Query(queryInd).Begin);
	}

	return res;
}

vector<vector<int>> XorOfSingleValuesComputer::_GetQueriesGroupedByEnd () const
{
	vector<vector<int>> res(_taskData->NumberOfNumbers());

	for (int queryInd = 0; queryInd < _taskData->NumberOfQueries(); ++queryInd)
		res[_taskData->GetEndOfInterval(queryInd)].push_back (queryInd);

	return res;
}

