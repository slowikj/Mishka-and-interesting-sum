#include "XorComputer.h"

using namespace std;

XorComputer::XorComputer (shared_ptr<TaskData> _dataPtr)
	: _taskData(_dataPtr)
{
}

int XorComputer::Result (int queryNumber)
{
	return this->Result(_taskData->Query(queryNumber));
}

int XorComputer::Result (const Interval& interval)
{
	int beg = interval.Begin;
	int end = interval.End;

	if (beg < 0 || end < 0 || beg > end)
		throw invalid_argument("the given interval is out of range!");

	if (!_IsPreprocessingDone())
		_prefixXor = _GetXorPrefixes();

	int prefixXorBefore = (beg == 0 ? 0
									: _prefixXor[beg - 1]);

	return _prefixXor[end] ^ prefixXorBefore;
}

bool XorComputer::_IsPreprocessingDone () const
{
	return _prefixXor.size() != 0;
}

vector<int> XorComputer::_GetXorPrefixes () const
{
	int len = _taskData->NumberOfNumbers();

	vector<int> res(len);
	res[0] = _taskData->Number(0);
	for(int i = 1; i < len; ++i)
		res[i] = res[i - 1] ^ _taskData->Number(i);

	return move(res);
}

