#include "TaskData.h"
#include <algorithm>

using namespace std;

TaskData::TaskData ()
{
	_numbers = _GetReadNumbers();
	
	_queries = _GetReadQueries();
	for(Interval& query: _queries)
	{
		--query.Begin;
		--query.End;
	}
}

vector<int> TaskData::_GetReadNumbers() const
{
	return _GetReadSequence<int>();
}

vector<Interval> TaskData::_GetReadQueries() const
{
	return _GetReadSequence<Interval>();
}

template<class T>
vector<T> TaskData::_GetReadSequence() const
{
	int n;
	cin >> n;
	
	vector<T> res(n);
	for_each(res.begin(), res.end(),
			 [](T& elem)->void
			 {
			 	cin >> elem;
			 }
			);

	return move(res);
}

const int& TaskData::Number (const int& index) const
{
	return _numbers[index];
}

const Interval& TaskData::Query (const int& index) const
{
	return _queries[index];
}

int TaskData::NumberOfNumbers () const
{
	return _numbers.size();
}

int TaskData::NumberOfQueries () const
{
	return _queries.size();
}

int TaskData::GetBeginOfInterval (const int& index) const
{
	return _queries[index].Begin;
}

int TaskData::GetEndOfInterval (const int& index) const
{
	return _queries[index].End;
}

