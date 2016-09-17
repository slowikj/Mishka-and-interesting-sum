#pragma once
#include <vector>
#include <memory>
#include "Interval.h"

using namespace std;

class TaskData
{
private:
	vector<int> _numbers;
	vector<Interval> _queries;

	vector<int> _GetReadNumbers () const;
	vector<Interval> _GetReadQueries () const;

	template<class T>
	vector<T> _GetReadSequence () const;

public:
	TaskData ();

	int Number (int index) const;
	const Interval& Query (int index) const;
	int NumberOfNumbers () const;
	int NumberOfQueries () const;
	int GetBeginOfInterval (int index) const;
	int GetEndOfInterval (int index) const;
};

