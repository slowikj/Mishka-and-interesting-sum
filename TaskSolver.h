#pragma once
#include <vector>
#include "XorComputer.h"
#include "XorOfSingleValuesComputer.h"

using namespace std;

class TaskSolver
{
private:
	shared_ptr<TaskData> _taskData;
	vector<int> _results;
	
	vector<int> _GetVectorWithResults () const;
	bool _IsResultComputed () const;

public:
	TaskSolver ();
	vector<int> Results ();
};

