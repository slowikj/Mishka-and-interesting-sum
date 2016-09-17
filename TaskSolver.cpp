#include "TaskSolver.h"

using namespace std;

TaskSolver::TaskSolver ()
{
	_taskData = make_shared<TaskData>();
}

vector<int> TaskSolver::Results ()
{
	if (_IsResultNotComputed ())
		_results = _GetVectorWithResults();

	return _results;
}

bool TaskSolver::_IsResultNotComputed () const
{
	return _results.size() == 0;
}

vector<int> TaskSolver::_GetVectorWithResults () const
{
	int numberOfQueries = _taskData->NumberOfQueries();

	vector<int> res(numberOfQueries);
	XorComputer entireXor(_taskData);
	XorOfSingleValuesComputer xorOfSingleValues(_taskData);

	for(int queryInd = 0; queryInd < numberOfQueries; ++queryInd)
		res[queryInd] = (entireXor.Result(queryInd)
						  ^ xorOfSingleValues.Result(queryInd));

	return res;
}

